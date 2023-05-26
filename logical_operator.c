#include "main.h"


/**
 * LogicalOPhandler - handles logical operators
 * @str: string to be handled if it contains Logical OP
 * @env: the environment of the current process
 * @LINE: line number
 * Return: void
 */
void LogicalOPhandler(char *str, char **env, int LINE)
{
	int i = 0;
	char *buffer;

	buffer = str;
	while (1)
	{
		if (*(str + i) == '|' &&
				*(str + i + 1) == '|')
		{
			*(str + i) = '\0';
			if (!executor(parser(buffer, env), env, LINE))
			{
				return;
			}
			/* TODO: change this to remove preceeding spaces if exist */
			i += 2;
			buffer = str + i;
		}
		else if (*(str + i) == ';')
		{
			*(str + i) = '\0';
			executor(parser(buffer, env), env, LINE);
			/* TODO: change this to remove preceeding spaces if exist */
			i += 1;
			buffer = str + i;
		}
		else if (*(str + i) == '&' && *(str + i + 1) == '&')
		{
			*(str + i) = '\0';
			if (executor(parser(buffer, env), env, LINE))
				return;
			i += 2;
			buffer = str + i;
		}
		if (*(str + i) == '\0')
		{
			executor(parser(buffer, env), env, LINE);
			return;
		}
		i++;
	}
}

