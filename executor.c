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
	pid_t childp = fork();
	int status, i = 0;

	if (childp != 0)
	{
		wait(&status);
		/* TODO: solve this memory issue */
#if 0 /* don't change this to 1, it will cause memory errors */
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
#endif
	}
	else
	{
		if (execve(args[0], args, env) < 0)
			exit(98);
	}
	return (status);
}

