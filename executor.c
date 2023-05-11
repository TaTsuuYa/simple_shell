#include "main.h"

/**
 * executor - executes commands
 * @args: array of arguments
 * @env: array of environment variables
 *
 * Return: 1 on success, 0 otherise
 */

int executor(char **args, char **env)
{
	int success = 0;
	
	success = execve(args[0], args, env);
	if (success < 0)
		return (0);

	return (1);
}

