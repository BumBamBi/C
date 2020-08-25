

#include<stdio.h>

// 영어 한글 판독기

int check(char st[])
{
	unsigned char uc;
	uc = st[0];

	if (uc < 128)
		return 0;
	else
		return 1;
}

int main()
{
	char string[3] = {};
	scanf("%s", string);	// scanf 는 &을 붙여서 주소를 썼어야 했지만 배열에서의 변수는 주소값을 나타내므로 &을 붙이지 않음


	if (check(string) == 1)	//if문 안에서 괄호 안에는 참(1)과 거짓(0)으로 표현됨
		printf("한글\n");
	else
		printf("영어\n");

	return 0;
}



