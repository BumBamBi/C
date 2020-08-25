#include<stdio.h>

/*		1번

int CountL(char *p)
{
	int i = 0;
	for (int a = 0; p[a] != NULL; a++)
	{
		printf("%c", p[i]);
		i++;
	}
	return i;
}

int CountC(char *p)
{
	int i;
	int L = CountL(p);
	int cnt = 0;
	for (i = 0; i < L; i++)
	{
		if (p[i] >= 'a' && p[i] <= 'z')
		{
			cnt++;
		}
	}
	return cnt;
}



int main()
{
	char arr[100] = "Ha Sibal Pigonha";
	int result;
	result = CountC(arr);
	printf("\n영문 소문자는 %d개", result);
}
*/




/*		2번

int CountL(char* p)
{
	int i = 0;
	for (int a = 0; p[a] != NULL; a++)
	{
		printf("%c", p[i]);
		i++;
	}
	return i;
}

int DelNN(char* p)
{
	int i;
	int L = CountL(p);
	int cnt = 0;
	for (i = 0; i < L; i++)
	{
		if (!(p[i]) >= '0' && p[i]<= '9')
		{
			

		}
		else
		{
			cnt++;
		}
	}
	return L - cnt;
}

int main()
{
	char arr[100] = "abcd1234bdfd5678";
	int result;
	result = DelNN(arr);
	printf("\n 남은 숫자개수 %d,\n 남은 arr값 %s", result, arr);
}

*/

int CountStrlen(char* p)
{
	int i = 0;
	while (p[i] != NULL)
	{
		printf("%c", p[i]);
		i++;
	}
	return i;
}

char* CangeOrder(char *p)
{
	int i;
	int k;
	int temp;
	int startStr;
	int str_lengh = CountStrlen(p);
	int cnt = 0;
	for (i = 0; i < str_lengh; i++)
	{
		if (p[i] >= '0' && p[i] <= '9')
		{
			k = i;
			for (k = i; k > 0; k--)
			{
				if (!(p[k - 1] >= '0' && p[k - 1] <= '9'))
				{
					temp = p[k - 1];
					p[k-1] = p[i];
					p[i] = temp;
					k++;
				}
			}
		}
	}
	return &p[startStr];
}



int main()
{
	char arr[100] = "abcd1234efgh5678";
	char* result;

	result = CangeOrder(arr);
	printf("\nShorting 결과 : %s", arr);
	printf("\n첫 시작 문자의 주소값 : %d", result);
}