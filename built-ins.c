#include "main.h"

/**
 * handle_builtins - handles the built in commands
 * @args: command
 * @env: env vars
 *
 * Return: 1 success, 0 otherwise
 */

int handle_builtins(char **args, char **env)
{
	if (_strcmp(args[0], "exit"))
	{
		if (args[1] != NULL)
			exit(_atoi(args[1]));
		else
			exit(0);
	}

	if (_strcmp(args[0], "env"))
	{
		if (args[1] != NULL)
		{
			write_std("env: '", STDERR_FILENO);
			write_std(args[1], STDERR_FILENO);
			write_std("': No such file or directory\n", STDERR_FILENO);
		}
		else
			print_env(env);
		return (1);
	}

	return (0);
}

