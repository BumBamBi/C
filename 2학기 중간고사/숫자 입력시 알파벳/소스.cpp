#include<stdio.h>

// ���� �Է½� ���ĺ� ������ �ϱ�

int main()
{
	char alpha[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	int a;
	scanf("%d", &a);
	printf("%c\n", alpha[a - 1]);
}