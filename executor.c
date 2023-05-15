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
	char *newCommand;

	//if (!file_test(args[0], env, 1))
	//	return (1);
	if (isExecutable(args[0]))
	{
		if (!file_test(args[0], env, 1))
			return (1);
	}
	else
	{
		newCommand = searchInPath(args[0], env);
		if (newCommand == NULL)
		{
			file_test("lsdjfsdlfwersdf", env, 1);
			return (2); /* TODO: change this */
		}
		else
		{
			args[0] = newCommand;
		}
	}

	childp = fork();

	if (childp != 0)
	{
		wait(&status);
		free(args);
		if (newCommand != NULL)
			free(newCommand);
	}
	else
	{
		if (execve(args[0], args, env) < 0)
			exit(98);
	}
	return (status);
}

