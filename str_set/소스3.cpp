#include<stdio.h>

//ASCII CODE : A(65) a(97)


void strupr(char*str)
{
	while (*str != NULL)
	{
		if (*str >= 65 && *str <= 90)
		{
			*str = *str + 32;
		}
		str++;
	}
}


int main()
{
	char str[] = "STRING string";
	
	printf("%s\n", str);

	strupr(str);

	printf("%s\n", str);

	return 0;
}