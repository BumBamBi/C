#include<stdio.h>


int main()
{
	for (int i = 0; i < 4; i++)
	{
		printf("%c%c", 0xA1, 0xE1);
		if (i % 3 == 0)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%c%c", 0xA1, 0xE1);
			}
			printf("\n");
		}
		else
		{
			for (int k = 0; k < 6; k++)
			{
				printf(" ");
			}
			printf("%c%c\n", 0xA1, 0xE1);
		}
	}
	return 0;
}
