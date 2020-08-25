#include<stdio.h>

char* strchr(char*str, char alpha)
{
	while (*str != NULL)
	{
		if (*str == alpha)
		{
			return str;//문자가 있는 주소값을 출력한다.
		}
		else
		{
			str++;//주소값을 증가.
		}
	}	
	return NULL;//없다면 NULL
}

int main()
{
	char str[] = "I want to find a character";
	char alpha;

	scanf("%c", &alpha);//원하는 문자의 값을 입력받는다.

	char*num = strchr(str, alpha);//num에는 찾는 문자가 있다면 주소값을 저장하고
									//찾는 문자가 없다면 NULL값을 저장한다.

	while (1)
	{
		if (num == NULL)
		{
			printf("더 이상 없음.\n");
			return 0;
		}
		else
		{
			printf("%p\n", num);//strchr의 경우 num까지 찾으므로,
			num = strchr(num + 1, alpha);//문자열의 NULL값까지 찾기 위해서는 num+1을 해준다.
		}
	}
	

}