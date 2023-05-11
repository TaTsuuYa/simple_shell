#include "main.h"
#include <stdio.h>

int main(void)
{
	char **arr;
	int i = 0;

	printf("before parser");
	arr = parser("ls -l sdf");
	printf("after parser");

	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		i++;
	}

	return (0);
}

