#include "main.h"
#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	char *arr[] = {"asd", "-l", "-a", NULL};

	(void) argc;
	(void) argv;

	printf("exec: %d\n", executor(arr, env));

	return (0);
}

