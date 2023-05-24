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

	for (i = 0; s[i] != 0; i++)
	{}

	return (i);
}

/**
 * write_std - prints error to stderr
 * @txt: text to be printed
 * @field: std file descriptor
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
	int i = 0;
	char *file_name;

	/* getting the name of current program */
	while (env[i] != NULL)
	{
		if (env[i][0] == '_' && env[i][1] == '=')
		{
			file_name = &env[i][2];
		}
		i++;
	} /* TODO: probably should handle case where `_` env variable doesn't exist */
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
	int i, count = 0, check = 0;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == ' ' && check == 1)
		{
			check = 0;
		}
		else if (command[i] != ' ' && check == 0)
		{
			check = 1;
			count++;
		}
	}

	return (count);
}

/**
 * isExecutable - checks if command is an executable or alias
 *                for a command in /bin/
 * @command: string, the first element of parser array
 * Return: 1 if true, otherwise 0
 */
int isExecutable(char *command)
{
	int i = 0;

	while (*(command + i) != '\0')
	{
		if (*(command + i) == '/')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
