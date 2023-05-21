/**
 * NOTE: this should only be changed for testing purposes, it should always
 *       changed back to 0, or else the checker will not compile correctly
 *       because there are 2 main functions
 *
 * compilation command: gcc test.c utils.c -o test
 */
#if 0
#include "main.h"


int main(int argc, char **argv, char **env)
{
	//char command[] = "/bin/ls -l && /bin/cal";

	printf("---------------- testing getVarValue -----------------\n");
	printf("SHELL: %s\n", "/bin/bash");
	printf("SHELL: %s\n", getVarValue("$SHELL", env));
	printf("HOME: %s\n", "/home/nyly");
	printf("HOME: %s\n", getVarValue("$HOME", env));

	printf("---------------- testing argcnt -----------------\n");
	printf("WANT: 2\n");
	printf("GOT : %d\n", argcnt("ls -al   "));
	printf("WANT: 3\n");
	printf("GOT : %d\n", argcnt("ls   -al   /bin/ "));
	printf("WANT: 1\n");
	printf("GOT : %d\n", argcnt("ls"));
	printf("WANT: 2\n");
	printf("GOT : %d\n", argcnt("ls -al"));

	return (0);
}
#endif
