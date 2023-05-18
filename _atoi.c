#include "main.h"

/**
 * _atoi - converts a string to an int
 * @s: string
 *
 * Return: int if convertable, 0 otherwise
 */

int _atoi(char *s)
{
	int res = 0, i = 0, sign = 1;

	if (s[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	while (s[i] != 0)
	{
		if (s[i] > '9' || s[i] < '0')
			return (0);

		res = (res * 10) + (int)(s[i] - '0');

		i++;
	}

	res *= sign;

	return (res);
}

