#include<stdio.h>


int main()
{
	//����ü	-	�ΰ� �̻��� ���ҵ�� ������ ���� �ڷ���
	//������ �����͸� ��� �ϳ��� ������ ����� �� �ֵ��� ����
	//�˱����� �پ������� �迭ó�� ������� ����������� ���� (������ ���׹����� �� ����, ����Ǵ� ������ ũ�⵵ �޶� �� �� ����)	-	pc�� 4byte�� �о���Ƿ�

	/*	1�� ���

	struct ����ü��Ī
	{
		��� ����1;
		��� ����2;
	}����ü ������;

	*/

	/* 2�� ���

	struct ����ü��Ī ����ü������;		-		�ѹ��� �����صθ� �̷��� �ҷ��� �� ����

	*/
				
	//����ü�� ����鼭 ���� ���� �ǰ�	-	�ٷ� ���� �������
	//����ü�� ����� ���߿� ���� ���� �ǰ�		-		�� �� �������

	struct addr1
	{
		int a;
		int b;
		char *c;
	}data;

	//	a = 0;		-		����	a�� ������� ����	/	struct addr�� main �Լ� ���̵� ���̵� �Ȱ���	==>		�Լ�ó�� ���δ�.
	data.a = 0;				// .�� ��Ʈ ����		==>		�Ƹ��� data �ȿ� �ִ� a�� ����? ���ִµ�?
	data.c = "Hello";		// main�Լ����� ó�� �����		���� �̷��� �ʱ�ȭ ����
	printf("%d\n", data.a);
	printf("%s\n", data.c);


	//struct ����
	struct Birrhday
	{
		int year;
		int month;
		int day;
		char calendar;

		int a[10];
		int b;
	}K = { 1997, 3, 25, '+' };

	printf("%d��, %d��, %d��, %c\n\n", K.year, K.month, K.day, K.calendar);

	printf("%d\n\n", sizeof(K));	//	4����Ʈ ������ 1 2 3 4 �� �ǰ� �� ũ�� 4�� �������	4 8 12..

	printf("&year		%p\n&month		%p\n&day		%p\n&calendar	%p\n&a[0]		%p\n&a[1]		%p\n&b		%p\n", &K.year, &K.month, &K.day, &K.calendar, &K.a[0], &K.a[1], &K.b);
	//	������������ �����ϸ鼭 �̾



	//����ü�� ������
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