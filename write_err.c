#include "main.h"

/**
 * write_err - prints error to stderr
 * @file: file name
 */

void write_err(char *file)
{
	write(STDERR_FILENO, file, _strlen(file));
}

