#include "main.h"

/**
 * parser - parses the @command
 * @command: input command
 *
 * Return: pointer to parsed command
 */

char **parser(char *command)
{
	int i, argc;
	char **argv;

	if (command == NULL)
		return (NULL);

	argc = argcnt(command);
	argv = malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
		return (NULL);

	argv[0] = strtok(command, " ");
	for (i = 1; i < argc; i++)
		argv[i] = strtok(NULL, " ");

	argv[i] = NULL;

	return (argv);
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

