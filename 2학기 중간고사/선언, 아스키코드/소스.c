#include<stdio.h>

//cpp이 아닌 c임!!!!!!!!!!!!

char z; //전역 변수는 다른 변수들의 주소값과 달리 앞자리 수가 다르다 = 모든 함수에서 찾을 수 있다
		//초기화가 자동으로 됨

int main(void)
{
	char a, b, c, d;
	int i, j, k;
	char e, f, g;
	int l;
	char h;
	int m; //여기 까진 메모리 공간을 만들어 준 것

	bb(); //f11을 누르면 함 수 안으로 들어감

	m = 0; //여기부터 프로그램의 시작

		   //Shift + f9 로 간략한 조사식 실행 가능
		   //char의 값은 1byte크기를 가지지만
		   //그의 주소값은 4byte 크기를 가진다
	program1();
	program2();
}

int bb(void)
{
	char a = 'a';	//a에 사실 97을 저장함
					//char a = 97; 과 같다
	printf("%d  %c\n", a, a);	//%c로 97을 c로 해석해서 보여줌

	char A = "abc";	//""는 주소이기에 원래는 잘못됬지만 넣어주었다.
	int B = 'a';	//제대로 작동
	int C = "abc";	//주소값을 int형으로 넣어준것
}

int program1()
{
	unsigned char i, count = 0;

	for (i = 32; i < 127; i++)
	{
		printf("%c (%3d) ", i, i);

		if (count == 6)
		{
			count = 0;
			printf("\n");
		}
		count++;

	}

	printf("\n");
	return 0;

	//32 공백
	//48 0
	//65 A
	//97 a
}

int program2()
{
	char a, b, c, d, e;
	char bb[5];	//배열은 주소값이 차례대로 있음
	int cc[5];	//똑같이 차례대로 있으나 주소가 int형이기 떄문에 4byte씩 차이남
}