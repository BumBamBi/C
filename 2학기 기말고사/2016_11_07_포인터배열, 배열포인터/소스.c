#include<stdio.h>

void changename1(char** p)		//ReadOnly ���� ���� �Ұ�
{
	p[0][0] = '0';
	p[1][0] = '1';
}

void changename2(char** p)		//ReadOnly ���� ���� �Ұ�
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






void printname1(char** p)																			//p�� ������ �����̹Ƿ�
{

	printf("(fuits�� ù��° ���ڿ���) = %s, (fruits�� �ι�° ���ڿ���) = %s\n\n", p[0], p[1]);		//p[1]�� �� 4byte �̵�
	printf("(fuits�� ù��° ���ڿ���) = %s, (fruits�� �ι�° ���ڿ���) = %s\n\n", *p, (*p)+1);		//p[1]�� �� 4byte �̵�
	printf("%s\n\n", p);
}

void printname2(char** p)
{
	printf("(fuits�� ù��° ���ڿ��� ù��° ���ڴ�) = %c, (fruits�� �ι�° ���ڿ��� ù��° ���ڴ�) = %c\n", **p, *p[1]);
	printf("(fuits�� ù��° ���ڿ��� ù��° ���ڴ�) = %c, (fruits�� �ι�° ���ڿ��� ù��° ���ڴ�) = %c\n", p[0][0], p[1][0]);
	printf("(fuits�� ù��° ���ڿ��� ù��° ���ڴ�) = %c, (fruits�� �ι�° ���ڿ��� ù��° ���ڴ�) = %c\n\n", (*p)[0], *(*(p+1)));

	printf("(fuits�� ù��° ���ڿ��� �ι�° ���ڴ�) = %c, (fruits�� �ι�° ���ڿ��� �ι�° ���ڴ�) = %c\n", (*p)[1], p[1][1]);
	printf("(fuits�� ù��° ���ڿ��� �ι�° ���ڴ�) = %c, (fruits�� �ι�° ���ڿ��� �ι�° ���ڴ�) = %c\n\n", (*p)[1], *(*(p+1)+1));
}

void printname3(char (*p)[10])
{
	printf("(fname�� ù��° ���ڿ���) = %s, (fname�� �ι�° ���ڿ���) = %s\n\n", p[0], p[1]);
}

void printname4(char(*p)[10])
{
	printf("(fname�� ù��° ���ڿ��� ù��° ���ڴ�) = %c, (fname�� �ι�° ���ڿ��� ù��° ���ڴ�) = %c\n\n", p[0][0], p[1][0]);
}

int main()
{
	char* fruit[] = { "apple","blueberry", "orange", "melon" };

	char fname[][10] = { "apple","blueberry", "orange", "melon" };

	//changename1(&fruit[0]);		//0,1�� ���ٲ���		//X
	//changename2(&fruit[0]);		//2,3���� ���ٲ���		//X
	printname1(fruit);			//���ڿ� ���			//Clear
	printname2(&fruit[0]);			//���� ���				//Clear


	changename3(&fname[0]);			//0,1�� �ٲ���			//Clear
	changename4(&fname[0]);			//2,3���� �ٲ���		//Clear

	printname3(&fname[0]);			//���ڿ� ���			//Clear
	printname4(&fname[0]);			//���� ���				//Clear


	changename5(*fname);			//
}