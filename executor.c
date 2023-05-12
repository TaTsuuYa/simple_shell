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

	if (childp != 0)
		wait(&childp);
	else
		if (execve(args[0], args, env) < 0)
			return(0);

	return (1);
}

