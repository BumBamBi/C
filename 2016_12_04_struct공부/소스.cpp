#include<stdio.h>

#if 1
int main()
{
	struct ID
	{
		char name[20];
		int age;
		char adress[100];
		char phone[50];
		char birth[20];
		char couple[20];
	}Lee, Yoo;

	Lee = { "�̱���", 20, "��⵵ ���� ���籸 ȣ���� 860 ���̾� �޷���Ʈ 208�� 1701ȣ", "010-5561-7510", "1997.03.25", "������" };
	Yoo = { "������", 21, "��󳲵� �뿵�� �̼��� ����1�� 15 602ȣ", "010-3742-1437", "1996.05.03", "�̱���" };

	struct Food
	{
		char A[20][30];
	}G[20];

	G[20] = { "�ø�", "�ʹ�", "��â", "Į����", "��ĩ����", "��������", "ġŲ, �ݶ�", "¥���", "����Ų���", "�ѷ��긣", "����", "���찡 ���� ���� �丮", "���ְ� ���� ���� �丮" };

	int I = 1;

	while (I == 1 || I == 2 || I == 3)
	{

		I = 0 ;	

		printf("�˰� ���� ������ �Է��ϼ���\n\nex)1 - �̱��� / 2 - ������ / 3 - ����  / �� �� - ����\n\n");
		scanf("%d", &I);

		if (I == 1)
		{
			printf("�̸�   : %s\n", Lee.name);
			printf("����   : %d\n", Lee.age);
			printf("�ּ�   : %s\n", Lee.adress);
			printf("��ȣ   : %s\n", Lee.phone);
			printf("����   : %s\n", Lee.birth);
			printf("����� : %s\n\n\n", Lee.couple);
		}

		if (I == 2)
		{
			printf("�̸�   : %s\n", Yoo.name);
			printf("����   : %d\n", Yoo.age);
			printf("�ּ�   : %s\n", Yoo.adress);
			printf("��ȣ   : %s\n", Yoo.phone);
			printf("����   : %s\n", Yoo.birth);
			printf("����� : %s\n\n\n", Yoo.couple);
		}

		if (I == 3)
		{
			for (int i = 1; i < 13; i++)
			{
				printf("%d�� : %s\n", i, G.A[i]);
			}
			printf("\n\n");
		}
	}
}
#endif	//�̱��� ������ ����

