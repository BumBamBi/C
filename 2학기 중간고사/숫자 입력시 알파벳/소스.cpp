#include<stdio.h>

// 숫자 입력시 알파벳 나오게 하기

int main()
{
	char alpha[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	int a;
	scanf("%d", &a);
	printf("%c\n", alpha[a - 1]);
}