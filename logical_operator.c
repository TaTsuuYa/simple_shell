#include "main.h"


void LogicalOPhandler(char **argv, int argc, char **env) /* TODO: maybe change int */
{
	int i, bufferIndex = 0;
	char *buffer[argc];

	for (i = 0; i < argc; i++)
	{
		if (argv[i][0] == '|' &&
				argv[i][1] == '|' &&
				argv[i][2] == '\0')
		{
			buffer[bufferIndex] = NULL;
			if (executor(buffer, env))
			{
				return;
			}
		}
		else if (argv[i][0] == '&' &&
						argv[i][1] == '&' &&
						argv[i][2] == '\0')
		{
			buffer[bufferIndex] = NULL;
			executor(buffer, env);
			bufferIndex = 0;
		}
		else
		{
			buffer[bufferIndex] = argv[i];
		}
		bufferIndex++;
	}
}
