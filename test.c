#include "main.h"

int main(int argc, char **argv, char **env)
{
	char *arr[] = {"/bin/ls", "-l", NULL};

	(void) argc;
	(void) argv;

	executor(arr, env);

	return (0);
}

