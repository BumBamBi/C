#include<stdio.h>

int strlen(char*p)//���ڿ� ���� ���� �Լ�
{
	int cnt = 0;
	while (*p != NULL)
	{
		cnt++;
		p++;
	}
	return cnt;
}

void strrev(char*str, int cnt)//���ڿ��� �Էµ� ���ڸ�ŭ ������ �Լ�
{
	int num = cnt / 2;
	int i = 0;
	
	for (i = 0; i < num; i++)
	{
		char temp = str[i];
		str[i] = str[cnt-1];
		str[cnt - 1] = temp;
		cnt--;			
	}
	
}

int main()
{
	char str[] = "! I like computer.&^^";
	int cnt = strlen(str);//strlen�� ������ ��

	printf("���� str : %s\n", str);

	strrev(str, cnt);//strlen���� ���� �����´�.

	printf("������ restr : %s\n", str);

	return 0;
}
