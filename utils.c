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
 *
 * Return: 1 success, 0 otheriwse
 */

int file_test(char *command)
{
	struct stat st;

	if (stat(command, &st) != 0)
	{
		write_err(FILE_NAME);
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

