#include<stdio.h>

char* strchr(char*str, char alpha)
{
	while (*str != NULL)
	{
		if (*str == alpha)
		{
			return str;
			str++;
		}
		else
		{
			str++;
		}
	}
	return NULL;
}

int main()
{
	char str[] = "I want to find a character";
	char alpha;

	scanf("%c", &alpha);

	char*num = strchr(str, alpha);

	//number 1 : 한 번만 출력
	
	printf("%p", num);

	return 0;
}