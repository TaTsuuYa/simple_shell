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

	argv[0] = _strtok(command);
	for (i = 1; i < argc; i++)
		argv[i] = _strtok(NULL);

	argv[i] = NULL;

	return (argv);
}

