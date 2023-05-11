#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>


int main (int argc, char **argv)
{
	char *command;
	size_t size = 0;
	ssize_t commandLen;
	struct stat st;
	pid_t child_id;
	char *args[2];
	int ReturnValue;

	args[1] = NULL;
	while (1)
	{
		write(1, "$ ", 2);
		commandLen = getline(&command, &size, stdin);
		command[commandLen - 1] = '\0';
		if (stat(command, &st) != 0)
		{
			write(1, "./shell: No such file or directory\n", 35);
		}
		else
		{
			child_id = fork();
			if (child_id != 0)
			{
				wait(&child_id);
			}
			else
			{
				args[0] = command;
				if (execve(args[0], args, NULL) == -1)
				{
					write(1, "./shell: No such file or directory\n", 35);
					/* exit(1); */
					return (-1);
				}
			}
		}
	}
	return (0);
}
