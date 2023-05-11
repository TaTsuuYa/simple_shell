#include "main.h"
#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	char *arr[] = {"/bin/ls", "-l", NULL};
  int Result;

	(void) argc;
	(void) argv;

	Result = executor(arr, env);
  printf("executor return value = %d\n", Result);

	return (0);
}

