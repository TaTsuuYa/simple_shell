#include "_strtok.c"
#include <stdio.h>

int main(void)
{
	char *str, *str2;
	size_t buf;

	printf(">> ");
	getline(&str, &buf, stdin);

	str2 = _strtok(str);
	while (str2 != NULL)
	{
		printf("%s-", str2);
		str2 = _strtok(NULL);
	}

	return (0);
}

