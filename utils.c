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

