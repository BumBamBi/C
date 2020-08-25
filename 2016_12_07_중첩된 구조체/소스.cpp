#include<stdio.h>

struct list
{
	char* name;
	char gendet;
	int age;
	struct list *next;
}a = { "Kim", 'M', 20 }, b = { "lee", 'F', 18 }, c = { "Park", 'M', 20 };

struct list *ptr;


struct bit_field
{
	unsigned int a : 1;	//1비트만 쓰겠다		//LSB
	unsigned int b : 1;	//1비트만 쓰겠다
	unsigned int c : 1;	//1비트만 쓰겠다
	unsigned int d : 1;	//1비트만 쓰겠다
	unsigned int e : 1;	//1비트만 쓰겠다
	unsigned int f : 1;	//1비트만 쓰겠다
	unsigned int g : 1;	//1비트만 쓰겠다
	unsigned int h : 1;	//1비트만 쓰겠다		//MSB
}A;

struct b_type
{
	unsigned a : 1;
	int : 6;			//비워 두겠다.
	unsigned b : 1;
};

union u_tag
{
	char ch;
	int num;
	long big_num;
}info_u;


union data
{
	char a=0;
	int b;
	long c;
};


int main()
{
	a.next = &b;
	b.next = &c;
	c.next = NULL;



	A.a = 1;
	A.b = 1;
	A.c = 1;
	A.d = 1;
	A.e = 1;
	A.f = 1;
	A.g = 1;
	A.h = 1;

	union data value;

	printf("%d\n", sizeof(value.a));
	printf("%d\n", sizeof(value.b));
	printf("%d\n", sizeof(value.c));

	value.a = (long)0x12345678;

	printf("%x\n", value.a);
	printf("%x\n", value.b);
	printf("%x\n", value.c);
}