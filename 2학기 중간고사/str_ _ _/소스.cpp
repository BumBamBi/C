#include<stdio.h>

int strlen1(char* a)
{
	int count = 0;

	while(a[count] != NULL)
	{
		count++;
	}

	return count;
}

int strlen2(char* a)
{
	char* origin_a = a;

	while (*a != NULL)
	{
		a++;
	}

	return a - origin_a;
}

void strcpy(char* a, char* b)
{
	while (*a != NULL)
	{
		*b = *a;
		a++;
		b++;
	}
}

void strcat(char* a, char* b)
{
	while (*a != NULL)
	{
		a++;
	}
	while (*b != NULL)
	{
		*a = *b;
		a++;
		b++;
	}

}

char* FirstFind(char* A, char* B)
{
	while (1)
	{
		if (*A == *B)
		{
			return A;
		}
		else if (*A != *B)
		{
			return NULL;
		}
		else
		{
			A++;
		}
	}
}

int RestFind(char* A, char* B)
{
	while (1)
	{
		if (*A == *B)
		{
			A++;
			B++;
			if (*B == NULL)
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	char a[11] = "abcde";

	//strlen1
				int len1 = strlen1(a);

				printf("strlen1\n");
				printf("%d\n\n", len1);
	
	//strlen2
				int len2 = strlen2(a);

				printf("strlen2\n");
				printf("%d\n\n", len2);

	//strcpy
				char b[11] = {};

				strcpy(a, b);

				printf("strcpy\n");
				printf("%s\n\n", b);


	//strcat
				strcat(a,b);

				printf("strcat\n");
				printf("%s\n\n", a);

	//strstr
				printf("strstr\n");

				char A[100] = "aaabcaaabd";
				char B[100] = "aabdc";

				char* AA = FirstFind(A, B);

				while (AA != NULL)
				{
					int K = RestFind(AA, B);

					if (K)
					{
						printf("%s\n", AA);
						break;
					}
					else
					{
						AA = FirstFind(AA + 1, B);
					}
				}
				if (AA == NULL)
				{
					printf("%s\n", AA);
				}

}