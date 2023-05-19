#include "main.h"

/**
 * handle_builtins - handles the built in commands
 * @args: command
 * @env: env vars
 */

void handle_builtins(char **args, char **env)
{
	if (_strcmp(args[0], "exit"))
	{
		if (args[1] != NULL)
			exit(_atoi(args[1]));
		else
			exit(0);
	}

	if (_strcmp(args[0], "env"))
		print_env(env);
}

