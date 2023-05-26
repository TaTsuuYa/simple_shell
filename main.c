#include "main.h"


/**
 * main - Entry point
 * @argc: number of args
 * @argv: args array
 * @env: environment array
 *
 * Return: alwayse 0
 */
int main(int argc, char **argv, char **env)
{
	char *command = NULL;
	size_t size = 0;
	ssize_t commandLen;
	int isInteractive = isatty(STDIN_FILENO), line = 1;

	(void) argc;
	(void) argv;

	builtin_exit(1, 0);
	/* NOTE: 1 to 0 to test with valgrind */
#if 1
	while (1)
	{
#endif
		if (isInteractive)
			write(1, "($) ", 4);
		commandLen = getline(&command, &size, stdin);

		if (commandLen == -1)
		{
			free(command);
			builtin_exit(0, 0);
		}
		command[commandLen - 1] = '\0';
		free_alocs(command, NULL);
		LogicalOPhandler(command, env, line);
		line++;
#if 1
	}
#endif
	/**
	 * NOTE: i changed this free statement out of the loop cuz somehow i started
	 *			 getting double free error, it's strange why it didn't throw it in
	 *			 previous versions, my guess is that `command` pointer doesn't change
	 *			 because it's the same variable, so freeing it 2 times will cause
	 *			 this error, maybe we sould test this on an older version to make
	 *       sure why this error is being thrown now.
	 */
	free(command);
	return (0);
}

