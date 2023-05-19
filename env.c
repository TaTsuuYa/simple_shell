#include "main.h"

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

