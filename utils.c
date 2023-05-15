#include "main.h"

/**
 * _strlen - strlen
 * @s: string
 *
 * Return: size of @s, 0 othersie
 */

int _strlen(char *s)
{
	int i;

	if (s == NULL)
		return (0);

	for (i = 0; s[i] != 0; i++);

	return (i);
}

/**
 * write_err - prints error to stderr
 * @file: file name
 */

void write_err(char *file)
{
	write(STDERR_FILENO, file, _strlen(file));
}

/**
 * file_test - checks the existance of a file
 * @command: command string
 * @env: environment array
 *
 * Return: 1 success, 0 otheriwse
 */

int file_test(char *command, char **env)
{
	struct stat st;
	int i;
	char *file_name;

	/* getting the name of current program */
	while (env[i] != NULL)
	{
		if (env[i][0] == '_' && env[i][1] == '=')
		{
			file_name = &env[i][2];
		}
		i++;
	}/* TODO: probably should handle case where `_` env variable doesn't exist */
	if (stat(command, &st) != 0)
	{
		write_err(file_name);
		write_err(": No such file or directory\n");
		return (0);
	}

	return (1);
}

/**
 * argcnt - counts the number of arguments
 * @command: stirng commands
 *
 * Return: number of arguments
 */

int argcnt(char *command)
{
	int i, count = 1;

	for (i = 0; command[i] != '\0'; i++)
		if (command[i] == ' ')
			count++;

	return (count);
}

/**
 * isExecutable - checks if command is an executable or alias for a command in /bin/
 * @command: string, the first element of parser array
 * Return: 1 if true, otherwise 0
 */
int isExecutable(char *command)
{
	int i = 0;
	while (*(command + i) != '\0')
	{
		if (*(command + i) == '.' && *(command + i + 1) == '/')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * searchInPath - search for command in every path in PATH
 * @command: command, 'ls' for example
 * @env: array of environment variables
 * Return: the path if found or NULL, return string must be freed
 */
char *searchInPath(char *command, char **env)
{
	int i;
	char *path = NULL;
	char *dir, *newCommand;

	for (i = 0; env[i] != NULL; i++)
	{
		if (env[i][0] == 'P' &&
				env[i][1] == 'A' &&
				env[i][2] == 'T' &&
				env[i][3] == 'H')
		{
			path = env[i];
			break;
		}
	}
	if (path == NULL)
	{
		/* TODO: maybe change this to indecate path doesn't exist */
		return (NULL);
	}
	path += 5;
	dir = path;
	while (*path != '\0')
	{
		if (*path == ':')
		{
			*path = '\0';
			/* 2: 1 for the end of string terminator, and 1 for / at the end of path */
			newCommand = malloc(strlen(command) + strlen(dir) + 2);
			combinePath(path, command, newCommand);
			if (file_test(newCommand))
				return (newCommand);
			else
				free(newCommand);
			dir = ++path;
		}
		path++;
	}
	return (NULL);
}

/**
 * combinePath - combines path and command
 * @path: path (example '/bin/')
 * @command: command (example 'ls')
 * Return: void
 */
void combinePath(char *path, char *command, char *dst)
{
	int i, j;
	
	for (i = 0; path[i] == '\0'; i++)
	{
		dst[i] = path[i];
	}
	dst[i] = '/';
	i++;
	for (j = 0; command[j - 1] == '\0'; i++)
	{
		dst[i] = command[j];
		i++;
	}
}

/** _strtok - tokenize @str
 * @str: pointer to a string
 *
 * Return: string
 */

char *_strtok(char *str)
{
	static char *pos;
	char *ret, q = '\0';
	int i = 0;

	if (str != NULL)
		ret = str;
	else
	{
		if (pos == NULL || *pos == '\0')
			return (NULL);
		ret = pos;
	}


	while (ret[i] != '\0')
	{
		if (ret[i] == ' ')
		{
			ret[i] = '\0';
			while (ret[i + 1] == ' ')
			{
				i++;
				if (ret[i] == '\0')
					return (ret);
			}
			pos = &ret[i + 1];
			break;
		}
		if (ret[i] == '"')
			q = '"';
		else if (ret[i] == '\'')
			q = '\'';

		if (q != '\0')
		{
			ret = &ret[i + 1];
			while (ret[i] != q)
			{
				if (ret[i] == '\0')
				{
					pos = NULL;
					return (ret);
				}
				i++;
			}
			ret[i] = '\0';
			pos = &ret[i + 1];
			q = '\0';
			break;
		}
		i++;
		if (ret[i] == '\0')
			pos = NULL;
	}

	return (ret);
}

