

#include<stdio.h>

// ���� �ѱ� �ǵ���

int check(char st[])
{
	unsigned char uc;
	uc = st[0];

	if (uc < 128)
		return 0;
	else
		return 1;
}

int main()
{
	char string[3] = {};
	scanf("%s", string);	// scanf �� &�� �ٿ��� �ּҸ� ���� ������ �迭������ ������ �ּҰ��� ��Ÿ���Ƿ� &�� ������ ����


	if (check(string) == 1)	//if�� �ȿ��� ��ȣ �ȿ��� ��(1)�� ����(0)���� ǥ����
		printf("�ѱ�\n");
	else
		printf("����\n");

	return 0;
}



