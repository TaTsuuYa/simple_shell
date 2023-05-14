#include "main.h"

/** _strtok - tokenize @str
 * @str: pointer to a string
 *
 * Return: string
 */

char *_strtok(char *str)
{
	static char *pos;
	char *ret;
	int i = 0;

	if (str != NULL)
		ret = str;
	else
	{
		if (pos == NULL)
			return (NULL);
		ret = pos;
	}


	while (ret[i] != '\0')
	{
		if (ret[i] == ' ')
		{
			ret[i] = '\0';
			while (ret[i + 1] == ' ')
			{
				i++;
				if (ret[i] == '\0')
					return (ret);
			}
			pos = &ret[i + 1];
			break;
		}
		if (ret[i] == '"')
		{
			ret = &ret[i + 1];
			while (ret[i] != '"')
			{
				if (ret[i] == '\0')
				{
					pos = NULL;
					return (ret);
				}
				i++;
			}
			ret[i] = '\0';
			pos = &ret[i + 1];
			break;
		}
		if (ret[i] == '\'')
		{
			ret = &ret[i + 1];
			while (ret[i] != '\'')
				i++;
			ret[i] = '\0';
			pos = &ret[i + 1];
			break;
		}
		i++;
		if (ret[i] == '\0')
			pos = NULL;
	}

	return (ret);
}

