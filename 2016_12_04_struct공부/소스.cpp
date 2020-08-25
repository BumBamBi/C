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

	Lee = { "이광우", 20, "경기도 고양시 덕양구 호국로 860 래미안 휴레스트 208동 1701호", "010-5561-7510", "1997.03.25", "유현주" };
	Yoo = { "유현주", 21, "경상남도 통영시 미수동 진남1길 15 602호", "010-3742-1437", "1996.05.03", "이광우" };

	struct Food
	{
		char A[20][30];
	}G[20];

	G[20] = { "냉면", "초밥", "곱창", "칼국수", "잔칫국수", "돼지국밥", "치킨, 콜라", "짜장면", "베스킨라빈스", "뚜레쥬르", "게장", "광우가 직접 만든 요리", "현주가 직접 만든 요리" };

	int I = 1;

	while (I == 1 || I == 2 || I == 3)
	{

		I = 0 ;	

		printf("알고 싶은 정보를 입력하세요\n\nex)1 - 이광우 / 2 - 유현주 / 3 - 맛집  / 그 외 - 종료\n\n");
		scanf("%d", &I);

		if (I == 1)
		{
			printf("이름   : %s\n", Lee.name);
			printf("나이   : %d\n", Lee.age);
			printf("주소   : %s\n", Lee.adress);
			printf("번호   : %s\n", Lee.phone);
			printf("생일   : %s\n", Lee.birth);
			printf("배우자 : %s\n\n\n", Lee.couple);
		}

		if (I == 2)
		{
			printf("이름   : %s\n", Yoo.name);
			printf("나이   : %d\n", Yoo.age);
			printf("주소   : %s\n", Yoo.adress);
			printf("번호   : %s\n", Yoo.phone);
			printf("생일   : %s\n", Yoo.birth);
			printf("배우자 : %s\n\n\n", Yoo.couple);
		}

		if (I == 3)
		{
			for (int i = 1; i < 13; i++)
			{
				printf("%d번 : %s\n", i, G.A[i]);
			}
			printf("\n\n");
		}
	}
}
#endif	//이광우 유현주 맛집

