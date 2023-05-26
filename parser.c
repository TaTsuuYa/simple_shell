#include "main.h"

/**
 * parser - parses the @command
 * @command: input command
 * @env: environment array
 *
 * Return: pointer to parsed command
 */

char **parser(char *command, char **env)
{
	int i, argc;
	char **argv;

	if (command == NULL)
		return (NULL);

	argc = argcnt(command);
	if (argc == 0)
	{
		return (NULL);
	}
	argv = malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
		return (NULL);
	free_alocs(NULL, argv);

	argv[0] = _strtok(command);
	for (i = 1; i < argc; i++)
		argv[i] = getVarValue(_strtok(NULL), env);

	argv[i] = NULL;

	return (argv);
}

