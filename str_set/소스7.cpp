#include<stdio.h>

char* strchr(char*str, char alpha)
{
	while (*str != NULL)
	{
		if (*str == alpha)
		{
			return str;//���ڰ� �ִ� �ּҰ��� ����Ѵ�.
		}
		else
		{
			str++;//�ּҰ��� ����.
		}
	}	
	return NULL;//���ٸ� NULL
}

int main()
{
	char str[] = "I want to find a character";
	char alpha;

	scanf("%c", &alpha);//���ϴ� ������ ���� �Է¹޴´�.

	char*num = strchr(str, alpha);//num���� ã�� ���ڰ� �ִٸ� �ּҰ��� �����ϰ�
									//ã�� ���ڰ� ���ٸ� NULL���� �����Ѵ�.

	while (1)
	{
		if (num == NULL)
		{
			printf("�� �̻� ����.\n");
			return 0;
		}
		else
		{
			printf("%p\n", num);//strchr�� ��� num���� ã���Ƿ�,
			num = strchr(num + 1, alpha);//���ڿ��� NULL������ ã�� ���ؼ��� num+1�� ���ش�.
		}
	}
	

}