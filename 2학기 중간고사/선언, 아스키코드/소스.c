#include<stdio.h>

//cpp�� �ƴ� c��!!!!!!!!!!!!

char z; //���� ������ �ٸ� �������� �ּҰ��� �޸� ���ڸ� ���� �ٸ��� = ��� �Լ����� ã�� �� �ִ�
		//�ʱ�ȭ�� �ڵ����� ��

int main(void)
{
	char a, b, c, d;
	int i, j, k;
	char e, f, g;
	int l;
	char h;
	int m; //���� ���� �޸� ������ ����� �� ��

	bb(); //f11�� ������ �� �� ������ ��

	m = 0; //������� ���α׷��� ����

		   //Shift + f9 �� ������ ����� ���� ����
		   //char�� ���� 1byteũ�⸦ ��������
		   //���� �ּҰ��� 4byte ũ�⸦ ������
	program1();
	program2();
}

int bb(void)
{
	char a = 'a';	//a�� ��� 97�� ������
					//char a = 97; �� ����
	printf("%d  %c\n", a, a);	//%c�� 97�� c�� �ؼ��ؼ� ������

	char A = "abc";	//""�� �ּ��̱⿡ ������ �߸������� �־��־���.
	int B = 'a';	//����� �۵�
	int C = "abc";	//�ּҰ��� int������ �־��ذ�
}

int program1()
{
	unsigned char i, count = 0;

	for (i = 32; i < 127; i++)
	{
		printf("%c (%3d) ", i, i);

		if (count == 6)
		{
			count = 0;
			printf("\n");
		}
		count++;

	}

	printf("\n");
	return 0;

	//32 ����
	//48 0
	//65 A
	//97 a
}

int program2()
{
	char a, b, c, d, e;
	char bb[5];	//�迭�� �ּҰ��� ���ʴ�� ����
	int cc[5];	//�Ȱ��� ���ʴ�� ������ �ּҰ� int���̱� ������ 4byte�� ���̳�
}