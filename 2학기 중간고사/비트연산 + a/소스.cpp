#include<stdio.h>

int main(void)									// main 함수 int는 함수가 끝나고 운영체제에 돌려줄 바이트의 값										// int 면 return 값을 줘야되고 void면 return; 만 해도됨
												// void는 필요한 인자
{
	unsigned char hangul[3] = "광";				//ㅁㅁㅁ 세칸의 배열중에 두칸을 "광" 로 쓰고 마지막칸은 null로 한다.
	unsigned char code;							//unsigned를 쓰면 8비트일때 가장 큰 숫자자리의 비트는 부호를 나타내는데 이것도 값으로 이용한다 (부호 x 다 양수)
	code = hangul[0];							//"광"를 저장할려면 2byte가 필요한데 그 중 첫번째 byte를 저장
	printf("%x %d\n", code, code);
	code = hangul[1];							//"광"를 저장할려면 2byte가 필요한데 그 중 두번째 byte를 저장
	printf("%x %d\n\n", code, code);

	printf("%c %c\n", hangul[0], hangul[1]);	//두 byte에 저장된 값을 따로 출력  =>> ??
	printf("%c%c\n\n", hangul[0], hangul[1]);		//두 byte에 저장된 값을 붙여서 출력	=>> 광

	unsigned char b1 = 0xb1;
	unsigned char b2 = 0xa4;
	printf("%c%c\n\n", b1, b2);					//1byte값 두개를 만들어서 붙여서 출력 =>> 광


	unsigned char aaa[3] = { 0xb1, 0xa4, 0 };
	printf("%c%c\n\n", aaa[0], aaa[1]);			//3byte의 배열을 만들어서 두 값을 따로 붙여서 출력 =>> 광




	int a = 2;
	int b = 1;

	printf("%d\n", (a&b));				// 3 bit로 비교
	printf("%d\n\n", (a&&b));			// 1 참 거짓으로 비교			>>왜 1?





	unsigned short a1 = 128;		//이해 X
	unsigned char a2[3] = "";

	if ((a1 && a2) == 128)
	{
		printf("특수문자\n");
	}
	else
	{
		printf("숫자 or 영어\n");
	}

	return 0;

}