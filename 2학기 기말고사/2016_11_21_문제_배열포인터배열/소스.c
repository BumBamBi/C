#include<stdio.h>

/* 1번 문제*/
/*
int main()
{
	char data[3][15] = { "Incheon123", "National456", "Univ.789" };	//배열 선언

	printf("바꾸기 전 =>> %s\n", data[2]);	//바꾸기 전 data배열 출력

	char(*ppp)[15] = &data[0];	//배열포인터 ppp선언 후 data의 첫 주소 입력

	ppp[2][4] = 'e';	//ppp가 data의 첫 주소를 갖고 있으므로 ppp[2]는 Univ.789의 U를 가리키고 ppp[2][4]는 .을 가리킨다.
	ppp[2][5] = 'r';
	ppp[2][6] = 's';
	ppp[2][7] = 'i';
	ppp[2][8] = 't';
	ppp[2][9] = 'y';
	ppp[2][10] = '7';
	ppp[2][11] = '8';
	ppp[2][12] = '9';

	printf("바꾼 후   =>> %s\n", data[2]);
}


/*	2번 문제*/
/*
int main()
{
	char *str1 = "acbd1234xyz5678", str2[20];	//배열 선언

	char *ppp = str1;	//포인터 변수 ppp를 만들고 str1의 첫 주소를 대입

	int n = 0;		//n = 0 으로 선언

	while (1)
	{
		if (*ppp>=48 && *ppp<=57)
		{	//	만약 *ppp의 값이 0 1 2 3 4 5 6 7 8 9 중 있다면
			str2[n] = *ppp; //그 값을 str2[n]에 대입하고
			ppp = ppp + 1;	//ppp의 값은 1을 더하고
			n++;			// n의 값도 1을 더함
			if (*ppp == NULL)
				break;		//만약 *ppp가 NULL이 되면 반복 탈출
		}
		else
		{
			ppp = ppp + 1;	// 만약 *ppp의 값이 0 1 2 3 4 5 6 7 8 9 중 없다면 1더함
		}
	}

	char* A = str2;		//초기화를 위함 포인터 변수 A선언 후 str2의 값을 대입해줌

	while (*A == '0' || *A == '1' || *A == '2' || *A == '3' || *A == '4' || *A == '5' || *A == '6' || *A == '7' || *A == '8' || *A == '9')
	{
		A++;	//만약 *A의 값이 0 1 2 3 4 5 6 7 8 9 중 있다면 A에 1을 더함
	}

	*A = NULL; //A에 NULL 입력 후 출력

	printf("%s\n", str2);
}
*/


/*		3번 문제*/
/*
int main()
{
	char data[3][15] = { "Incheon123", "National456", "Univ.789" }, str2[20];		//배열 선언

	char(*ppp)[15] = &data[0];		//배열 포인터 ppp에 data의 첫주소 대입

	int n = 0;		//n = 0으로 두고

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 15; j++)		//ppp[0][0]부터 ppp[2][14]까지 반복
		{
			if (ppp[i][j] == '0' || ppp[i][j] == '1' || ppp[i][j] == '2' || ppp[i][j] == '3' || ppp[i][j] == '4' || ppp[i][j] == '5' || ppp[i][j] == '6' || ppp[i][j] == '7' || ppp[i][j] == '8' || ppp[i][j] == '9')
			{ //ppp[i][j]가 숫자면
				str2[n] = ppp[i][j];	//그 값을 str[n]에 대입하고
				n++;	//n은 1더함
			}
		}
	}

	char *A = str2;	//초기화할 A만들고 str2의 주소 입력

	while (*A == '0' || *A == '1' || *A == '2' || *A == '3' || *A == '4' || *A == '5' || *A == '6' || *A == '7' || *A == '8' || *A == '9')
	{//*A가 숫자면 A에 1을 더하고
		A++;
	}

	*A = NULL; //A에 NULL입력

	printf("%s\n", str2);
}
*/


/*		4번 문제 */
/*
int main()
{
	char data1[20] = "Incheon 123", data2[30] = "National 456", data3[40] = "University 789", str[20];		//배열 선언

	char*ppp[3] = { data1, data2, data3 };		//포인터 배열 ppp[3]선언

	int n = 0;	//n=0으로 두고

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 20; j++)	//ppp[0][0]부터 끝까지 반복함
		{
			if (ppp[i][j] == '0' || ppp[i][j] == '1' || ppp[i][j] == '2' || ppp[i][j] == '3' || ppp[i][j] == '4' || ppp[i][j] == '5' || ppp[i][j] == '6' || ppp[i][j] == '7' || ppp[i][j] == '8' || ppp[i][j] == '9')
			{	//ppp[i][j]가 숫자면
				str[n] = ppp[i][j]; //str[n] 에 대입한다
				n++;	//n에 1을 더하고
			}
		}
	}

	char *A = str;	//초기화할 A 선언하고 str을 대입

	while (*A == '0' || *A == '1' || *A == '2' || *A == '3' || *A == '4' || *A == '5' || *A == '6' || *A == '7' || *A == '8' || *A == '9')
	{//*A의 값이 숫자면 1을 다하고 반복
		A++;
	}
	*A = NULL; //*A에 NULL 입력

	printf("%s", str);
}
*/