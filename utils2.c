#include "main.h"

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
		if (env[i][0] == 'P' && env[i][1] == 'A' &&
				env[i][2] == 'T' && env[i][3] == 'H')
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
			{
				return (newCommand);
			}
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
 * @dst: destination buffer
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

/**
 * _strtok - tokenize @str
 * @str: pointer to a string
 *
 * Return: string
 */

char *_strtok(char *str)
{
	static char *pos;
	char *ret;
	int i = 0;

	if (str != NULL)
	{
		for (i = 0; str[i] == ' '; i++)
		{}
		ret = &str[i];
		for (i = 0; ret[i] != ' ' && ret[i] != '\0'; i++)
		{}
		if (ret[i] == '\0')
		{
			pos = NULL;
			return (ret);
		}
		ret[i] = '\0';
		pos = &ret[i + 1];
		return (ret);
	}
	else
	{
		for (i = 0; pos[i] == ' '; i++)
		{}
		ret = &pos[i];
		for (i = 0; ret[i] != ' ' && ret[i] != '\0'; i++)
		{}
		if (ret[i] == '\0')
		{
			pos = NULL;
			return (ret);
		}
		ret[i] = '\0';
		pos = &ret[i + 1];
		return (ret);
	}
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
 * _strncmp - compares n bytes from two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to be compared
 *
 * Return: 1 if stings are the same, 0 otherwise
 */

int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;

	while (n > i)
	{
		if (s1[i] != s2[i])
			return (0);

		if (s1[i] == 0 || s2[i] == 0)
			return (1);

		i++;
	}

	return (1);
}

