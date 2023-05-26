#include "main.h"
/**
 * executor - executes commands
 * @args: array of arguments
 * @env: array of environment variables
 *
 * Return: 0 on success or diffrent value on failure
 */

int executor(char **args, char **env, int LINE)
{
	pid_t childp;
	int status, linenum;
	char *newCommand = NULL;
	/* handeling built-ins */
	if (args == NULL)
		return (0);
	else if (handle_builtins(args, env))
		return (0);
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
			write_std(getVarValue("$_", env), STDERR_FILENO);
			write_std(": line ", STDERR_FILENO);
			linenum = '0' + LINE;
			write(STDERR_FILENO, &linenum, 1);
			write_std(": ", STDERR_FILENO);
			write_std(args[0], STDERR_FILENO);
			write_std(": command not found\n", STDERR_FILENO);
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
		{
			exit_status = 98;
			exit(exit_status);
		}
	}
	exit_status = status;
	return (exit_status);
}

