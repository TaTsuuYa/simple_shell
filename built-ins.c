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
			builtin_exit(0, 0);
	}

	if (_strcmp(args[0], "env"))
	{
		if (args[1] != NULL)
		{
			write_std("env: ‘", STDERR_FILENO);
			write_std(args[1], STDERR_FILENO);
			write_std("’: No such file or directory\n", STDERR_FILENO);
		}
		else
			print_env(env);
		return (1);
	}
	if (_strcmp(args[0], "cd"))
	{
		handleCD(args + 1, env);
		return (1);
	}

	return (0);
}

/**
 * handleCD - handles the execution of cd command
 * @args: array of cd args
 * @env: environment array
 * Return: void
 */
void handleCD(char **args, char **env)
{
	if (args[0] == NULL)
	{
		if (chdir(getVarValue("$HOME", env)))
		{
			/* TODO: handle the errno set by chdir */
		}
	}
	else if (args[1] != NULL)
	{
		/* TODO: this err msg could be not exactly correct */
		write_std(getVarValue("$_", env), STDERR_FILENO);
		write_std(": cd: too many arguments\n", STDERR_FILENO);
	}
	else
	{
		if (chdir(getVarValue(args[0], env)))
		{
			/*
			 * TODO: this is not necessarily correct
			 *       if chdir fails, it modify errno to indecate
			 *       what was the error exactly, but since errno
			 *       is not part of the allowed function, we assume
			 *       that the failing reason is "No such file"
			 */
			write_std(getVarValue("$_", env), STDERR_FILENO);
			write_std(": cd: ", STDERR_FILENO);
			write_std(args[0], STDERR_FILENO);
			write_std(": No such file or directory\n", STDERR_FILENO);
			/* -bash: cd: sdfsdf: No such file or directory */
		}
	}
}

