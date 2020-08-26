#include<stdio.h>

void test1()
{
	printf("1번 문제\n\n");

	char data[3][20] = { "Incheon123", "National456", "Univ.789" };

	printf("%s\n", &data[2]);

	char(*ppp)[20]= data;

	ppp[2][4] = 'e';
	ppp[2][5] = 'r';
	ppp[2][6] = 's';
	ppp[2][7] = 'i';
	ppp[2][8] = 't';
	ppp[2][9] = 'y';
	ppp[2][10] = '7';
	ppp[2][11] = '8';
	ppp[2][12] = '9';
	ppp[2][13] = '7';
	ppp[2][14] = '8';
	ppp[2][15] = '9';

	printf("%s\n\n", &ppp[2]);
}

void test2()
{
	printf("2번 문제\n\n");

	char *str1 = "acbd1234xyz5678", str2[20];

	for (int i = 0; i < 20; i++)
	{
		str2[i] = 0;
	}

	char *ppp = str1;

	int n = 0;

	while (*ppp != NULL)
	{
		if (*ppp >= '0' &&*ppp <= '9')
		{
			str2[n] = *ppp;
			n++;
			ppp++;
		}
		else
		{
			ppp++;
		}
	}

	printf("%s\n\n", str2);
}

void test3()
{
	printf("3번 문제\n\n");

	char data[3][15] = { "Incheon123", "National456", "Univ.789" }, str2[20];

	for (int i = 0; i < 20; i++)
	{
		str2[i] = 0;
	}

	char(*ppp)[15] = data;

	int n = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (ppp[i][j] >= '0' && ppp[i][j] <= '9')
			{
				str2[n] = ppp[i][j];
				n++;
			}
		}
	}
	printf("%s\n\n", str2);
}

void test4()
{
	printf("4번 문제\n\n");

	char data1[20] = "Incheon 123", data2[30] = "National 456", data3[40] = "University 789", str[20];

	for (int i = 0; i < 20; i++)
	{
		str[i] = 0;
	}

	char *ppp[3] = { data1, data2, data3 };

	int n = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (ppp[i][j] >= '0' && ppp[i][j] <= '9')
			{
				str[n] = ppp[i][j];
				n++;
			}
		}
	}
	printf("%s\n\n", str);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
}