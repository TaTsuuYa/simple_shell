#include "main.h"

void no_cmd_msg(char **env, int LINE, char *cmd);

/**
 * executor - executes commands
 * @args: array of arguments
 * @env: array of environment variables
 * @LINE: line number
 *
 * Return: 0 on success or diffrent value on failure
 */

int executor(char **args, char **env, int LINE)
{
	pid_t childp;
	int status;
	char *newCommand = NULL;
	/* handeling built-ins */
	if (args == NULL) /* no commands just spaces case */
		return (0);
	else if (handle_builtins(args, env, LINE))
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
			if (_strcmp(getVarValue("$PATH", env), ""))
				no_file_msg(env, LINE, args[0]);
			else
				no_cmd_msg(env, LINE, args[0]);
			return (127);
		}
		else
			args[0] = newCommand;
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
		if (execve(args[0], args, env) < 0)
			builtin_exit(0, 98);
	builtin_exit(1, WEXITSTATUS(status));
	return (status);
}

/**
 * no_cmd_msg - prints a no command message
 * @env: environment variables
 * @LINE: line number
 * @cmd: command
 */

void no_cmd_msg(char **env, int LINE, char *cmd)
{
	write_std(getVarValue("$_", env), STDERR_FILENO);
	write_std(": ", STDERR_FILENO);
	write_int(LINE, STDERR_FILENO);
	write_std(": ", STDERR_FILENO);
	write_std(cmd, STDERR_FILENO);
	write_std(": not found\n", STDERR_FILENO);
	builtin_exit(1, 127);
}


/**
 * no_file_msg - prints a no command message
 * @env: environment variables
 * @LINE: line number
 * @cmd: command
 */

void no_file_msg(char **env, int LINE, char *cmd)
{
	write_std(getVarValue("$_", env), STDERR_FILENO);
	write_std(": ", STDERR_FILENO);
	write_int(LINE, STDERR_FILENO);
	write_std(": ", STDERR_FILENO);
	write_std(cmd, STDERR_FILENO);
	write_std(": No such file or directory\n", STDERR_FILENO);
	builtin_exit(1, 127);
}

