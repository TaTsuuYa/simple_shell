#include "main.h"

/**
 * _atoi - converts a string to an int
 * @s: string
 *
 * Return: int if convertable, 0 otherwise
 */

int _atoi(char *s)
{
	int res = 0, i = 0, sign = 1;

	if (s[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	while (s[i] != 0)
	{
		if (s[i] > '9' || s[i] < '0')
			return (0);

		res = (res * 10) + (int)(s[i] - '0');

		i++;
	}

	res *= sign;

	return (res);
}

/**
 * getVarValue - returns the value of an env var
 * @var: environment variables
 * @env: environment array
 * Return: arg value or arg name itself
 */
char *getVarValue(char *var, char **env)
{
	int i = 0;
	int varLen;

	if (*var != '$')
	{
		return (var);
	}
	varLen = _strlen(var + 1);
	while (env[i] != NULL)
	{
		if (_strncmp(env[i], var + 1, varLen))
		{
			return (&env[i][varLen + 1]);
		}
		i++;
	}
	return (var);
}

/**
 * print_env - prints the environment variables
 * @env: environment variable
 */

void print_env(char **env)
{
	int i = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		write_std(env[i], STDIN_FILENO);
		write_std("\n", STDIN_FILENO);
	}
}

/**
 * builtin_exit - hnadles the updating or exiting
 * @mode: decides whether to update or exit
 * @status: exit status
 */

void builtin_exit(int mode, int status)
{
	static int exit_status;

	if (mode == 0)
		exit(exit_status);
	if (mode == 1)
		exit_status = status;
}

/**
 * write_int - prints an int
 * @i: printed int
 * @field: std file descriptor
 */

void write_int(int i, int field)
{
	char c = '0' + (i % 10);

	if (i == 0)
		return;

	write_int(i / 10, field);
	write(field, &c, 1);
}

