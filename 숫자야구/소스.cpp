#include<stdio.h>

int strike, ball = 0;

int correct(int number, int* K);
int trying(int a, int* aa, int* aaa);


int main()
{
	int A_number = 356;
	int B_number = 497;

	printf("player1��! ���ڸ� �Է��ϼ���!(�ߺ�X 3�ڸ�)\n");
	scanf("%d", &A_number);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("player2��! ���ڸ� �Է��ϼ���!(�ߺ�X 3�ڸ�)\n");
	scanf("%d", &B_number);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	int realA[3];
	int realB[3];

	correct(A_number, realA);
	correct(B_number, realB);

	int scanA, scanB = 0;

	int tryA[3] = { NULL };
	int tryB[3] = { NULL };

	int win;

	int loop = 1;

	printf("							   1p				    2p\n");
	while (loop)
	{
		printf("<player1 ����>\nplayer2 �� ����Ǵ� ���ڸ� �Է��ϼ���\n");
		scanf("%d", &scanB);
		win = 1;
		printf("\n��");
		loop = trying(scanB, tryB, realB);
		printf("��					%d  %d  %d(%ds %db)\n\n", tryB[0], tryB[1], tryB[2], strike, ball);
		if (loop == 1)
		{
			printf("<player2 ����>\nplayer1 �� ����Ǵ� ���ڸ� �Է��ϼ���\n");
			scanf("%d", &scanA);
			win = 2;
			printf("\n��");
			loop = trying(scanA, tryA, realA);
			printf("��									%d, %d, %d(%ds %db)\n\n", tryA[0], tryA[1], tryA[2], strike, ball);
		}
	}

	if (win == 1)
	{
		printf("\n\n�ڡ١ڡ١ڡ١ڡ١ڡ�  <<  player1 �� �̰���ϴ�!  >>  �ڡ١ڡ١ڡ١ڡ١ڡ�\n\n");
	}
	if (win == 2)
	{
		printf("\n\n�ڡ١ڡ١ڡ١ڡ١ڡ�  <<  player2 �� �̰���ϴ�!  >>  �ڡ١ڡ١ڡ١ڡ١ڡ�\n\n");
	}
}

int correct(int number, int* K)
{
	int a = number / 100;
	int b = number / 10 - (10 * a);
	int c = number - (10 * (number / 10));
	
	K[0] = a;
	K[1] = b;
	K[2] = c;

	return 0;
}

int trying(int a, int* aa, int* aaa)
{
	strike = 0;
	ball = 0;

	int x = a / 100;
	int y = a / 10 - (10 * x);
	int z = a - (10 * (a / 10));

	aa[0] = x;
	aa[1] = y;
	aa[2] = z;

	for (int i = 0; i < 3; i++)
	{
		if (aa[i] == aaa[i])
		{
			strike++;
		}
	}

	for (int j = 0; j < 3; j++)
	{
		for (int k = 1; k < 3; k++)
		{
			if (aa[j] == aaa[(j + k) % 3])
			{
				ball++;
			}
		}
	}
	if (strike == 3)
	{
		ball = 0;
	}

	printf("<%d ��Ʈ����ũ %d ��>", strike, ball);

	if(strike == 3)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}