#include "main.h"
#include <stdio.h>
/**
 * executor - executes commands
 * @args: array of arguments
 * @env: array of environment variables
 *
 * Return: 1 on success, 0 otherise
 */

int executor(char **args, char **env)
{
	pid_t childp = fork();
	int status;

	if (childp != 0)
		wait(&status);
	else
		if (execve(args[0], args, env) < 0)
			exit(1);

	return (0);
}

