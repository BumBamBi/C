#include<stdio.h>

int main(void)									// main �Լ� int�� �Լ��� ������ �ü���� ������ ����Ʈ�� ��										// int �� return ���� ��ߵǰ� void�� return; �� �ص���
												// void�� �ʿ��� ����
{
	unsigned char hangul[3] = "��";				//������ ��ĭ�� �迭�߿� ��ĭ�� "��" �� ���� ������ĭ�� null�� �Ѵ�.
	unsigned char code;							//unsigned�� ���� 8��Ʈ�϶� ���� ū �����ڸ��� ��Ʈ�� ��ȣ�� ��Ÿ���µ� �̰͵� ������ �̿��Ѵ� (��ȣ x �� ���)
	code = hangul[0];							//"��"�� �����ҷ��� 2byte�� �ʿ��ѵ� �� �� ù��° byte�� ����
	printf("%x %d\n", code, code);
	code = hangul[1];							//"��"�� �����ҷ��� 2byte�� �ʿ��ѵ� �� �� �ι�° byte�� ����
	printf("%x %d\n\n", code, code);

	printf("%c %c\n", hangul[0], hangul[1]);	//�� byte�� ����� ���� ���� ���  =>> ??
	printf("%c%c\n\n", hangul[0], hangul[1]);		//�� byte�� ����� ���� �ٿ��� ���	=>> ��

	unsigned char b1 = 0xb1;
	unsigned char b2 = 0xa4;
	printf("%c%c\n\n", b1, b2);					//1byte�� �ΰ��� ���� �ٿ��� ��� =>> ��


	unsigned char aaa[3] = { 0xb1, 0xa4, 0 };
	printf("%c%c\n\n", aaa[0], aaa[1]);			//3byte�� �迭�� ���� �� ���� ���� �ٿ��� ��� =>> ��




	int a = 2;
	int b = 1;

	printf("%d\n", (a&b));				// 3 bit�� ��
	printf("%d\n\n", (a&&b));			// 1 �� �������� ��			>>�� 1?





	unsigned short a1 = 128;		//���� X
	unsigned char a2[3] = "";

	if ((a1 && a2) == 128)
	{
		printf("Ư������\n");
	}
	else
	{
		printf("���� or ����\n");
	}

	return 0;

}