#include<stdio.h>

int strlen(char*str)
{
	int cnt = 0;
	while (*str != NULL)
	{
		cnt++;
		str++;
	}
	return cnt;
}

int strcmp(char*str1, char*str2)
{
	int cnt = 0;
	while (*str1 != NULL)
	{
		if (*str1 == *str2)
		{
			cnt++;
			str1++;
			str2++;
		}
		else if(*str1<*str2)
		{
			return -1;
		}
		else if (*str1 > *str2)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	char str1[100] = "stringa";
	char str2[100] = "stringb";

	//scanf("%s", str1);
	//scanf("%s", str2);

	int length = strlen(str1);
	int result = strcmp(str1, str2);

	if (result==0)
	{
		printf("0\n");		
	}
	else if (result == 1)
	{
		printf("1\n");
	}
	else if (result == -1)
	{
		printf("-1\n");
	}

	return 0;
}
