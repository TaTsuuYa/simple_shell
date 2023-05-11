#include "main.h"


void LogicalOPhandler(char *argv, char **env) /* TODO: maybe change int */
{
	int i, bufferIndex = 0;
	char *buffer;

	buffer = argv;
	while(*(argv + i - 1) != '\0')
	{
		if (*(argv + i) == '|' &&
				*(argv + i + 1) == '|')
		{
			*(argv + i) = '\0';
			if (executor(parser(buffer), env))
			{
				return;
			}
			/* TODO: change this to remove preceeding spaces if exist */
			i += 3;
			buffer = argv + i;
		}
		else if (*(argv + i) == '&' &&
						*(argv + i + 1) == '&')
		{
			*(argv + i) = '\0';
			executor(parser(buffer), env);
			/* TODO: change this to remove preceeding spaces if exist */
			i += 3;
			buffer = argv + i;
			bufferIndex = 0;
		}
		i++;
	}
}
