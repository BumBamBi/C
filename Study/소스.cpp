#include<stdio.h>

int main()
{
	char a = 1;
	int b = 4;
	float c = 4;
	double d = 8;

	char* aa = "안규호";		//포인터 변수		ㅁㅁㅁㅁ				--> 안규호
	char** aaa = &aa;			//포인터 변수		ㅁㅁㅁㅁ

	printf("%", aaa);
}