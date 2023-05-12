#include "main.h"


int main (int argc, char **argv, char **env)
{
	char *command;
	size_t size = 0;
	ssize_t commandLen;
	struct stat st;
	pid_t child_id;
	char *args[2];

	(void) argc;
	(void) argv;

	args[1] = NULL;
	/* NOTE: 1 to 0 to test with valgrind */
#if 1
	while (1)
	{
#endif
		write(1, "$ ", 2);
		commandLen = getline(&command, &size, stdin);

		command[commandLen - 1] = '\0';
		LogicalOPhandler(command, env);
		free(command);
#if 1
	}
#endif
	return (0);
}
