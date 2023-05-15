#include "main.h"
/**
 * executor - executes commands
 * @args: array of arguments
 * @env: array of environment variables
 *
 * Return: 0 on success or diffrent value on failure
 */

int executor(char **args, char **env)
{
	pid_t childp;
	int status;

	if (!file_test(args[0], env, 1))
		return (1);

	childp = fork();

	if (childp != 0)
	{
		wait(&status);
		free(args);
	}
	else
	{
		if (execve(args[0], args, env) < 0)
			exit(98);
	}
	return (status);
}

