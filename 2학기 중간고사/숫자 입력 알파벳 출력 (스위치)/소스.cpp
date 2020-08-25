#include<stdio.h>

int main()
{
	int i;
	printf("숫자 출력\n");
	printf("번호를 입력하시오 (1~3)>");
	scanf("%d", &i);

	switch (i)
	{
	case 1: printf("A\n");
	}

	switch (i)
	{
	case 2: printf("B\n");
	}

	switch (i)
	{
	case 3: printf("C\n");
	}

}