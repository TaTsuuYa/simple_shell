#include "main.h"

/**
 * handle_builtins - handles the built in commands
 * @args: command
 * @env: env vars
 * @LINE: line number
 *
 * Return: 1 success, 0 otherwise
 */

int handle_builtins(char **args, char **env, int LINE)
{
	int status_exit;

	if (_strcmp(args[0], "exit"))
	{
		if (args[1] != NULL)
		{
			status_exit = _atoi(args[1]);
			if (status_exit < 0)
				print_illegal_num(args[1], env, LINE);
			else
			{
				free_alocs(NULL, NULL, 3);
				exit(status_exit);
			}
			return (1);
		}
		else
		{
			free_alocs(NULL, NULL, 3);
			builtin_exit(0, 0);
		}
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


/**
 * free_alocs - frees the allocs
 * @command: command variable
 * @args: args variable
 * @mode: decides what the function does
 * Return: void
 */
void free_alocs(char *command, char **args, int mode)
{
	static char *COMMAND;
	static char **ARGS;

	if (command != NULL)
		COMMAND = command;
	if (args != NULL)
		ARGS = args;
	if (mode & 2)
		free(COMMAND);
	if (mode & 1)
		free(ARGS);
}

/**
 * print_illegal_num - prints illegal number exit error
 * @status_exit: illegal number
 * @env: environement varieables
 * @LINE: line number
 * Return: void
 */
void print_illegal_num(char *status_exit, char **env, int LINE)
{

	write_std(getVarValue("$_", env), STDERR_FILENO);
	write_std(": ", STDERR_FILENO);
	write_int(LINE, STDERR_FILENO);
	write_std(": exit: Illegal number: ", STDERR_FILENO);
	write_std(status_exit, STDERR_FILENO);
	write_std("\n", STDERR_FILENO);
	free_alocs(NULL, NULL, 1);
	builtin_exit(1, 2);
	builtin_exit(0, 0);
}
