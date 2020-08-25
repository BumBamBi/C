#include<stdio.h>

void swap(char* a, char* b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


//1차원 정렬

int main()
{
	char A[] = "54321";

	printf("%s\n", A);

	for (int j = 0; j < 4; j++)				//2. 5+4+3+2+1 = 15 이므로 5 * X > 15 인 X값을 넣어주면 됨
	{
		for (int i = 0; i < 4; i++)			//1. 배열의 길이 - 1   == swap할 최대 자리 수 == 숫자 사이 간의 수
		{
			if (A[i] > A[i + 1])					//i+1 == 마지막 자리 수
			{
				swap(&A[i], &A[i + 1]);
				printf("%s\n", A);
			}
		}
	}
	printf("\n%s\n", A);
}


/*
//2차원 배열 정렬


void main()
{
	char A[2][5] = { {1,5,3,7,9},{2,4,10,6,8} };

	for (int a = 0; a < 2; a++)							//배열 보여주기
	{
		for (int b = 0; b < 5; b++)
		{
			printf("%d ", A[a][b]);
		}
	}

	printf("\n\n");


	for (int k = 0; k < 2; k++)							//두 배열 각각 정렬하기
	{
		for (int i = 0; i < 4; i++)
		{
			if (A[k][i] > A[k][i + 1])
			{
				swap(&A[k][i], &A[k][i + 1]);
			}
		}
	}


	for (int n = 0; n < 5; n++)							//전체중에서 1번 줄 배열 정렬
	{
		for (int m = 0; m < 5; m++)
		{
			if (A[0][m]>A[1][n])
			{
				swap(&A[0][m], &A[1][n]);
			}
		}
	}

	for (int n = 0; n < 4; n++)							//전체 중에서 2번 줄 다시 정렬 - 1번 줄 정렬하느라 다시 섞였기 때문
	{
		for (int m = 0; m < 4; m++)
		{
			if (A[1][m] > A[1][m + 1])
			{
				swap(&A[1][m], &A[1][m + 1]);
			}
		}
	}



	for (int a = 0; a < 2; a++)							//배열 보여주기
	{
		for (int b = 0; b < 5; b++)
		{
			printf("%d ", A[a][b]);
		}
	}
}

*/

#include<cstdlib>
#include<ctime>

/*
//2차원 랜덤 배열 -- 1차

int main()
{
	srand((unsigned)time(NULL));

	char A[2][10] = { {1,3,5,7,9,11,13,15,17,19},{21,23,25,27,29,31,33,35,37,39} };

	for (int j = 0; j < 2; j++)							//여기부터
	{
		for (int i = 9; i >= 0; i--)									//여기부터
		{
			int R = (rand() % (i+1));
			swap(&A[j][R], &A[j][i]);
		}																//여기까지는 같은 차원의 마지막 자리를 어떤 자리와 랜덤으로 바꾸고 남은 자리를 반복시킴
	}																	
	
	for (int l = 0; l < 2; l++)
	{
		for (int k = 0; k < 10; k++)
		{
			printf("%2d ", A[l][k]);
		}
	}													//여기까지 랜덤으로 섞기 (같은 차원끼리만..)



	for (int k = 0; k < 2; k++)							//각 차원 정렬
	{
		for (int j = 0; j < 9; j++)					//2. 10+9+8+....2+1 =55 이므로 10 * X > 55 인 X값을 넣어주면 됨 
		{
			for (int i = 0; i < 9; i++)				//1. 배열의 길이
			{
				if (A[k][i] > A[k][i + 1])
				{
					swap(&A[k][i], &A[k][i + 1]);
				}
			}
		}
	}


	printf("\n\n");

	for (int l = 0; l < 2; l++)
	{
		for (int k = 0; k < 10; k++)
		{
			printf("%2d ", A[l][k]);
		}
	}
}
*/

//2차원 랜덤 배열 -- 2차
/*

int main()
{
	int A[2][10] = {};

	int B[20] = { 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39 };
	
	srand((unsigned)time(NULL));

	int count = 0;

	while (count != 20)									//배열 무작위로 섞기
	{
		int R = rand() % 20;

		if (B[R] != 0)
		{
			A[0][count] = B[R];
			B[R] = 0;
			count++;
		}
	}

	for (int l = 0; l < 2; l++)							//섞인 배열 출력하기 
	{
		for (int k = 0; k < 10; k++)
		{
			printf("%2d ", A[l][k]);
		}
	}

	printf("\n\n\n");

}
*/



/*
void oneline(int* a)  // int 포인터로 받음
{
	int b;
	int cnt = 0;
	int* p = a;  //a의 첫 주소를 저장하기 위함

	for (int i = 19; i > 0; i--)  //반복횟수를 1씩 줄여간다.(비교 끝에 나온 맨 끝자리는 큰 것이 확정이므로 다음 비교 때 빼준다.)
	{
		a = p;  //처음부터 다시 비교를 시작할 때 a의 첫 주소부터 비교를 시작해야 한다.
		cnt = 0;   //카운트도 다시 0으로 초기화 시켜서 while문을 잘 빠져나올 수 있도록 한다.
		while (cnt < i)
		{
			if (*a > *(a + 1))  //a의 주소의 값이 그 다음 주소의 값보다 크다면
			{
				// a의 주소의 값과 그 다음 주소의 값을 서로 바꾼다.
				b = *a;
				*a = *(a + 1);
				*(a + 1) = b;
			}
			a++; //a의 주소를 한 칸 미뤄서 다음으로 옮겨 계속 비교해 나간다.
			cnt++;  //while문을 빠져나오기 위해 카운터를 더해준다.

		}
	}



}

int main(void)
{
	int b;
	int c = 0;
	int Data[2][10] = { { 1,3,5,7,9,11,13,15,17,19 },{ 21,23,25,27,29,31,33,35,37,39 } };  //2차원 배열에 순서대로 초기화를 먼저한다.

	while (c < 20)  // 20번 반복하기 위해 사용
	{
		int* p;
		int* d;
		int t;
		p = &Data[rand() % 2][rand() % 10];   // 무작위로 정한 Data변수의 주소값을 변수 p에 저장한다.
		d = &Data[rand() % 2][rand() % 10];   // 또 다른 무작위로 정한 Data변수의 주소값을 변수 d에 저장한다.
		t = *p;
		*p = *d;
		*d = t;           // 포인터를 이용해 무작위로 정했던 두 Data변수의 값을 서로 바꿔준다.

		c = c + 1; // c를 이용해 반복 횟수를 카운트한다.
	}


	for (int i = 0; i < 20; i++)   printf("%d ", Data[0][i]); printf("\n"); // 랜덤한 Data배열 출력

	oneline(Data[0]);  // oneline함수 호출, Data 덩어리의 주소 중 큰 덩어리채의 주소말고, 작은 덩어리의 주소를 인자로 줌

	for (int i = 0; i < 20; i++)   printf("%d ", Data[0][i]);  // 정렬한 Data배열 출력


	return 0;
}

*/