#include<stdio.h>

int main()
{
	char a = 1;
	int b = 4;
	float c = 4;
	double d = 8;

	char* aa = "�ȱ�ȣ";		//������ ����		��������				--> �ȱ�ȣ
	char** aaa = &aa;			//������ ����		��������

	printf("%", aaa);
}