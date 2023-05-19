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
 *
 * Return: number fo bytes wtitten, -1 otherwise
 */

ssize_t write_std(char *txt, int field)
{
	return (write(field, txt, _strlen(txt)));
}

/**
 * file_test - checks the existance of a file
 * @command: command string
 * @env: environment array
 * @verbose: 1 or 0, to indecate if error msg should be printed
 *
 * Return: 1 success, 0 otheriwse
 */

int file_test(char *command, char **env, int verbose)
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
		if (verbose)
		{
			write_std(file_name, STDERR_FILENO);
			write_std(": No such file or directory\n", STDERR_FILENO);
		}
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
	char *dir, *endDir, *newCommand;

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
			endDir = path;
			/* 2: 1 for the end of string terminator, and 1 for / at the end of path */
			newCommand = malloc(_strlen(command) + _strlen(dir) + 2);
			combinePath(dir, command, newCommand, endDir - dir);
			if (file_test(newCommand, env, 0))
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
 * @pathSize: number of bytes to be copied from path
 * Return: void
 */
void combinePath(char *path, char *command, char *dst, unsigned int pathSize)
{
	unsigned int i, j;
	
	for (i = 0; i < pathSize; i++)
	{
		dst[i] = path[i];
	}
	dst[i] = '/';
	i++;
	for (j = 0; command[j] != '\0'; j++)
	{
		dst[i] = command[j];
		i++;
	}
	dst[i] = '\0';
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

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if stings are the same, 0 otherwise
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (1)
	{
		if (s1[i] != s2[i])
			return (0);

		if (s1[i] == 0 || s2[i] == 0)
			return (1);

		i++;
	}

	return (1);
}

/**
 * _atoi - converts a string to an int
 * @s: string
 *
 * Return: int if convertable, 0 otherwise
 */

int _atoi(char *s)
{
	int res = 0, i = 0, sign = 1;

	if (s[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	while (s[i] != 0)
	{
		if (s[i] > '9' || s[i] < '0')
			return (0);

		res = (res * 10) + (int)(s[i] - '0');

		i++;
	}

	res *= sign;

	return (res);
}

