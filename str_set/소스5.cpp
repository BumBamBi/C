#include<stdio.h>

void change(char*str)
{
	while (*str != NULL)
	{
		if (*str >= 65 && *str <= 90)//upper
		{
			*str = *str + 32;
		}

		else if (*str >= 97 && *str <= 122)//lower
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
	
	change(str);

	printf("%s\n", str);

	return 0;
}