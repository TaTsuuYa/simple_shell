#include "_strtok.c"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str, *str2;
	size_t buf;

	printf(">> ");
	getline(&str, &buf, stdin);
	str[strlen(str) - 1] = '\0';

	str2 = _strtok(str);
	while (str2 != NULL)
	{
		printf("%s-", str2);
		str2 = _strtok(NULL);
	}
	putchar('\n');

	return (0);
}

