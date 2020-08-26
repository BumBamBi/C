#include<stdio.h>

void changename1(char** p)		//ReadOnly 구간 변경 불가
{
	p[0][0] = '0';
	p[1][0] = '1';
}

void changename2(char** p)		//ReadOnly 구간 변경 불가
{
	p[0][0] = '2';
	p[1][0] = '3';
}



void changename3(char (*p)[10])
{
	p[0][0] = '0';
	p[1][0] = '1';
}
void changename4(char (*p)[10])
{
	p[0][0] = '2';
	p[1][0] = '3';
}

void changename5(char *p)
{
	p[0] = '8';
	p[1] = '9';
}






void printname1(char** p)																			//p는 포인터 변수이므로
{

	printf("(fuits의 첫번째 문자열은) = %s, (fruits의 두번째 문자열은) = %s\n\n", p[0], p[1]);		//p[1]일 때 4byte 이동
	printf("(fuits의 첫번째 문자열은) = %s, (fruits의 두번째 문자열은) = %s\n\n", *p, (*p)+1);		//p[1]일 때 4byte 이동
	printf("%s\n\n", p);
}

void printname2(char** p)
{
	printf("(fuits의 첫번째 문자열의 첫번째 문자는) = %c, (fruits의 두번째 문자열의 첫번째 문자는) = %c\n", **p, *p[1]);
	printf("(fuits의 첫번째 문자열의 첫번째 문자는) = %c, (fruits의 두번째 문자열의 첫번째 문자는) = %c\n", p[0][0], p[1][0]);
	printf("(fuits의 첫번째 문자열의 첫번째 문자는) = %c, (fruits의 두번째 문자열의 첫번째 문자는) = %c\n\n", (*p)[0], *(*(p+1)));

	printf("(fuits의 첫번째 문자열의 두번째 문자는) = %c, (fruits의 두번째 문자열의 두번째 문자는) = %c\n", (*p)[1], p[1][1]);
	printf("(fuits의 첫번째 문자열의 두번째 문자는) = %c, (fruits의 두번째 문자열의 두번째 문자는) = %c\n\n", (*p)[1], *(*(p+1)+1));
}

void printname3(char (*p)[10])
{
	printf("(fname의 첫번째 문자열은) = %s, (fname의 두번째 문자열은) = %s\n\n", p[0], p[1]);
}

void printname4(char(*p)[10])
{
	printf("(fname의 첫번째 문자열의 첫번째 문자는) = %c, (fname의 두번째 문자열의 첫번째 문자는) = %c\n\n", p[0][0], p[1][0]);
}

int main()
{
	char* fruit[] = { "apple","blueberry", "orange", "melon" };

	char fname[][10] = { "apple","blueberry", "orange", "melon" };

	//changename1(&fruit[0]);		//0,1로 못바꿔줌		//X
	//changename2(&fruit[0]);		//2,3으로 못바꿔줌		//X
	printname1(fruit);			//문자열 출력			//Clear
	printname2(&fruit[0]);			//문자 출력				//Clear


	changename3(&fname[0]);			//0,1로 바꿔줌			//Clear
	changename4(&fname[0]);			//2,3으로 바꿔줌		//Clear

	printname3(&fname[0]);			//문자열 출력			//Clear
	printname4(&fname[0]);			//문자 출력				//Clear


	changename5(*fname);			//
}