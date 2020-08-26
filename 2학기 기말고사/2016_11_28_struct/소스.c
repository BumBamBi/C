#include<stdio.h>


int main()
{
	//구조체	-	두개 이상의 원소들로 구성된 통합 자료형
	//연관된 데이터를 묶어서 하나의 단위로 취급할 수 있도록 묶음
	//옹기종기 붙어있지만 배열처럼 순서대로 연결되있지는 않음 (순서가 뒤죽박죽일 수 있음, 저장되는 데이터 크기도 달라 질 수 있음)	-	pc는 4byte씩 읽어오므로

	/*	1번 방법

	struct 구조체명칭
	{
		멤버 변수1;
		멤버 변수2;
	}구조체 변수명;

	*/

	/* 2번 방법

	struct 구조체명칭 구조체변수명;		-		한번만 선언해두면 이렇게 불러올 수 있음

	*/
				
	//구조체를 만들면서 변수 만들어도 되고	-	바로 공간 만들어짐
	//구조체를 만들고 나중에 변수 만들어도 되고		-		이 때 만들어지

	struct addr1
	{
		int a;
		int b;
		char *c;
	}data;

	//	a = 0;		-		에러	a가 선언되지 않음	/	struct addr이 main 함수 안이든 밖이든 똑같음	==>		함수처럼 쓰인다.
	data.a = 0;				// .은 도트 연산		==>		아마도 data 안에 있는 a를 연결? 해주는듯?
	data.c = "Hello";		// main함수에서 처음 선언됨		따라서 이렇게 초기화 가능
	printf("%d\n", data.a);
	printf("%s\n", data.c);


	//struct 예시
	struct Birrhday
	{
		int year;
		int month;
		int day;
		char calendar;

		int a[10];
		int b;
	}K = { 1997, 3, 25, '+' };

	printf("%d년, %d월, %d일, %c\n\n", K.year, K.month, K.day, K.calendar);

	printf("%d\n\n", sizeof(K));	//	4바이트 전에는 1 2 3 4 다 되고 더 크면 4의 배수ㅇㅇ	4 8 12..

	printf("&year		%p\n&month		%p\n&day		%p\n&calendar	%p\n&a[0]		%p\n&a[1]		%p\n&b		%p\n", &K.year, &K.month, &K.day, &K.calendar, &K.a[0], &K.a[1], &K.b);
	//	내림차순으로 저장하면서 이어감



	//구조체의 포인터
	struct book
	{
		char title[20];
		char auther[10];
		int price;
	}a = { "Hello, World", "Cprogram", 100 }, *room;

	room = &a;

	printf("%s\n", &a.title);
	printf("%c\n\n", a.title[0]);
	printf("%s\n", room->title);
	printf("%s\n", (*room).title);
}