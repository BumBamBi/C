#include<stdio.h>

void strtok(char *p, char(*pp)[10])
{
	int n = 1;
	int i = 0;
	int j = 0;
	
	while (*p != NULL)
	{
		if (n == 1)
		{
			if (*p == 32 || *p == 44 || *p == 9)
			{
				p++;
				j = 0;
				i++;
				n = 0;
			}
			else
			{
				pp[i][j] = *p;
				p++;
				j++;
				n = 1;
			}
		}

		if (n == 0)
		{
			if (*p == 32 || *p == 44 || *p == 9)
			{
				p++;
				n = 0;
			}
			else
			{
				pp[i][j] = *p;
				p++;
				j++;
				n = 1;
			}
		}
	}
}

int main()
{
	char a[] = "aaa,bbb,,ccc,,,ddd";
	char b[10][10] = {};

	strtok(a, b);

}