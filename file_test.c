#include "main.h"

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
		write_err(": No such file or directory");
		write_err("\n");
		return (0);
	}

	return (1);
}

