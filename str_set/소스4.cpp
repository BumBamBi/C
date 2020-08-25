#include<stdio.h>

//ASCII CODE : A(65) a(97)

void strlwr(char*str)
{
	while (*str != NULL)
	{
		if (*str >= 97 && *str <= 122)
		{
			*str = *str - 32;
		}
		str++;
	}
}

int main()
{
	char str[] = "STRING string";

	printf("%s\n", str);

	strlwr(str);

	printf("%s\n", str);

	return 0;
}