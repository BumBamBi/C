#include <stdio.h>

#if 0

int main()
{
	//char 타입의 1byte가 만들어짐

	char a1;					//변수 선언
	char a2 = 'a';				//a의 아스키코드를 저장
	char a3 = "a";				//되든 안되는 2글자를 1글자 자리에 넣으려고 하니 안됨 (컴파일이 되도 주소값이 들어감)
	char a4 = "abcd";			//5글자를 1글자 자리에 넣으려고 하니 안됨 (컴파일이 되도 주소값이 들어감)

	char b1[5];
	char b2[5] = { 'a','b','c','d','e' };		//각 알파벳의 아스키값이 각 바이트에 저장됨
	char b3[5] = "abcd";						//X		""안의 값은 메모리에 저장 후 그 메모리를 가리키는 주소값을 변수에 저장함 
												//		char 1byte 4개가 아니라 4byte 1개 필요
	char b4[] = "abcd";							//X		위와 마찬가지
	char b5[];									//X

	char *c1;									//O
	char *c2 = "abcde";							//O
	char *c3 = { 'a','b','c','d','e' };			//X
	char *c4 = "";								//O		null값 저장
	char *c5 = '';								//X		'' 안에는 값을 써줘야됨.		'a' 해도 안됨 *cp는 주소값 저장하는데 'a'는 아스키코드 숫자
}

int main()
{
	char a = 'a', b = 'b', c = 'c';
	char *aa = "aaa";
	char ab[3] = { 'b','b','b' };

	test(a, aa, ab);
}

int test(char a, char *aa, char *ab)
//  (char a, char *aa, char ab[])
{
	printf("%c,%s,%s", a, aa, ab);
}

#endif	//기본 공부


#if 0

//문자열의 길이를 반환하는 함수(null제외)
//설계법
//			함수 이름 결정				- strlen()
//			함수 반환값 결정			- unsigned int
//			함수 인자 수와 형태 결졍	- 인자 1개 (문자열을 입력받음 따라서 char*)	-문자열을 주지 않는 이유는 4byte 이상시 더 많이 복사해야함
//		
//																			 데이터 용량이 문자열의 2배 필요해짐, 어쩌피 삭제되면 불필요한 작업

int strlen(char *str)
{
	int length = 0;
	
	while (*str++ != NULL)
		length++ ;

	return length;
}

int main()
{
	char *str = "abcde";
	int len = 0;

	len = strlen(str);

	printf("%s, %d\n", str, len);

	return 0;
}

#endif	//strlen() --1


#if 0


int strlen(char *str)
{
	char *str1 = str;			//"abcde" 의 처음인 a의 주소값인 str을 포인터 변수 *

	while (*str++ != NULL)
	{}
	
	return str-str1 - 1;
}

int main()
{
	char *str = "abcde";
	int len = strlen(str);

	printf("%s, %d\n", str, len);

	return 0;
}

#endif	//strlen() --2	//int length 안쓰기


#if 0

//strcpy함수 만들기
//문자열을 복사하는 함수
//설계방법
//		함수 이름 결정				-strcpy()
//		함수 반환값 결정			-
//		함수 인자수와 형태 결정		- ~에서 ~로 복사 최소 2개의 인자


//1번

char* strcpy(char*a, char*b)
{
	int count = 0;

	while(*a != NULL)
	{
		*b = *a;
		b++;
		a++;
		count++;
	}
	return b - count;
}

int main()
{
	char a[5] = "abcd";
	char b[5] = {};
	char *A;
	A = strcpy(a, b);

	printf("%s\n%s\n%s\n",a, b, A);
	printf("%d\n%d", &b, A);
	return 0;
}

#endif	//strcpy() --1


#if 0

//2번

void strcpy(char*a, char*b)
{
	while (*a != NULL)
	{
		*b = *a;
		b++;
		a++;
	}
}

int main()
{
	char a[10] = "abcd";
	char b[10] = {};
	strcpy(a, b);

	printf("%s\n%s\n", a, b);
	return 0;
}

#endif	//strcpy() --2


#if 0

//strcat함수 만들기
//문자열을 이어붙는 함수
//설계방법
//		함수 이름 결정				-strcat()
//		함수 반환값 결정			-
//		함수 인자수와 형태 결정		-

void strcat(char*a, char*b)
{
	int count = 0;
	char *origin_b;

	while (*b != NULL)
	{
		b++;
		count++;
		origin_b = b - count;
	}
	while (1)
	{
		if (*a == NULL)
		{
			for (int i = 0; i <= count; i++)
			{
				*a = *origin_b;
				a++;
				origin_b++;
			}
			break;
		}
		else
		{
			a++;
		}
	}
}

int main()
{
	char a[] = "abcde";		//공간이 없어서 에러
	char b[] = "abcde";
	strcat(a, b);
	printf("%s\n", a);
	return 0;
}

#endif	//strcat() --1	//에러 - 공간 부족


#if 0

void strcat(char* a, char* b)
{
	while (*a != NULL)
	{
		a++;
	}
	while (*b != NULL)
	{
		*a = *b;
		a++;
		b++;
	}
}

int main()
{
	char a[50] = "abce";
	char b[10] = "efgh";
	strcat(a, b);
	printf("%s\n", a);
}

#endif	//strcat() --2


#if 0

//strstr함수 만들기
//문자열에서 문자가 저장된 주소를 출력하는 함수
//설계방법
//		함수 이름 결정				-strstr()
//		함수 반환값 결정			-char*
//		함수 인자수와 형태 결정		-

//1번

char* strstr(char *a, char *b)
{
	char *origin_a = a;
	char *out_a = a;

	while (1)
	{
		if (*a != *b)
		{
			a++;
		}
		if (*a == *b)
		{
			out_a = a;
			break;

		}
	}

	while (1)
	{
		a++;
		b++;
		if (*b == NULL)
		{
			break;
		}
		if (*a != *b)
		{
			out_a = NULL;
			break;
		}
	}
	return out_a;
}

int main()
{
	char a[50] = "abcde";
	char b[10] = "abc";
	char *A = strstr(a,b);
	printf("%p\n", A);
}

#endif	//strstr() --1	//에러 - abcabd에서 abd를 못가져옴


#if 0	

//2번 (1번 요약)

char* strstr(char *a, char *b)
{
	char *out_a = a;

	while (*a != *b)
	{
		a++;
	}

	out_a = a;
	
	while (1)
	{
		a++;
		b++;
		if (*b == NULL)
		{
			break;
		}
		if (*a != *b)
		{
			out_a = NULL;
			break;
		}
	}
	return out_a;
}

int main()
{
	char a[50] = "abcde";
	char b[10] = "ab";
	char *A = strstr(a, b);
	printf("%p\n", A);
}

#endif	//strstr() --2	//에러 - abcabd에서 abd를 못가져옴


#if 0
char* strstr(char*a, char*b)
{
	char* out_a = a;				//out_a는 (abcd,ad) 가 아닌 경우 반환될 a의 주소
	char* origin_b = b;				//*b를 리셋할때 필요한 원래의 b의 주소

	while (1)						//반복함 << 은근 중요
	{
		while (*a != *b)					//while은 여기부터
		{									//
			a++;							//
			out_a = a;						//여기까지		=>	 *b의 처음 값이 *a에 있다면 그 값을 out_a에 넣어줌 (=> *out_a와 *b를 같게 만들어줌)
			if (*out_a == NULL)						//같게 만든 후 b를 리셋하고 왔는데 *b와 같은값을 가진 *a이 없을때 NULL반환  (abcd, bd)
			{
				return NULL;
			}
		}

		if (*a == *b)						//a값과 b값이 같으면
		{
			a++;									// a와 b를 1씩 더함
			b++;

			if (*b == NULL)							//이 때 b가 끝까지 loop되서 NULL값이 되면
			{
				return out_a;								//out_a반환 (abcd, ab)  (abcd, cd)
			}
		}
		if (*a != *b)						//a값과 b값이 다르면
		{
			b = origin_b;							//b를 리셋시키고
			out_a = a;								//out_a를 재설정함	(abddc, dc)일 때 (dc,c) 이후 여길 지나면 (dc,dc)가 된다.
		}
	}
}

int main()
{
	char a[50] = "aaabcdabce";		//abddc	//abcabd	//abcd
	char b[10] = "aabcd";			//dc	//abd		//ad
	char *A = strstr(a, b);
	printf("%p\n%p\n", a, A);
}
#endif	//strstr() --3


#if 0
char* strstr(char*a, char*b)
{
	char* out_a = a;
	char* origin_b = b;
	char* origin_a = a;

	while (1)
	{
		while (*a != *b)
		{
			a++;
			out_a = origin_a;
			if (*out_a == NULL)
			{
				return NULL;
			}
		}

		if (*a == *b)
		{
			a++;
			b++;

			if (*b == NULL)
			{
				return out_a;
			}
		}
		if (*a != *b)
		{
			b = origin_b;
			out_a = origin_a;
		}
	}
}

int main()
{
	char a[50] = "aaabcdabce";		//abddc		//abcabd	//abcd
	char b[10] = "aabcd";			//dc		//abd		//ad
	char *A = strstr(a, b);
	printf("%p\n%p\n", a, A);
}
#endif	//교수님 조언


#if 0
char* strstr(char *a, char *b)
{
	while (1)
	{
		char *aa = a;
		char *bb = b;

		while (*aa == *bb)
		{
			aa++;
			bb++;
			if (*bb == NULL)
			{
				return a;
			}
			if (*aa != *bb)
			{
				aa = NULL;
				break;
			}
		}

		if (*a == NULL)
		{
			return NULL;
		}

		a++;
	}

}

int main()
{
	char a[50] = "abdabd";
	char b[10] = "bd";
	char *A = strstr(a, b);
	printf("%p\n%p\n", a, A);
}
#endif	//strstr() //예린이2


#if 0
char* strstr(char *a, char *b)  // 인수를 포인터로 받아 주소값을 읽을 수 있게 한다.
{
	char* p = b;  // 나중에 계속 b의 가르키는 주소가 바뀌기 때문에 b의 첫주소를 포인터 변수 p에 저장해 놓는다.
	int cnt = 0;   // count하는 변수하나를 지정한다.

	while (1)  // break가 나올 때까지 반복하는 반복문을 쓴다.
	{
		if (*b == *a)  // b의 주소에 있는 값과 a의 주소에 있는 값이 같으면 if문 안으로 들어간다.
		{
			b++; a++;  // 그 다음 값도 같은지 확인하기 위해 a와 b의 가르킨 주소를 하나 뒤로 넘긴다.
			cnt++;      // cnt는 나중에 리턴값을 위해 있는 것인데 마지막 a의 가르킨 주소가 

			if (*b == NULL)
			{
				break;
			}
		}
		else
		{
			a++;
			cnt = 0;
			b = p;

			if (*a == NULL)
			{
				return 0;
			}
		}
	}
	return a - cnt;
}

int main(void)
{
	char a[100] = "abcd";
	char b[10] = "bc";
	printf("%s", strstr(a, b));
	return 0;
}
#endif	//strstr() //예빈이


#if 0
char* test(char a, char x[], char f[])	//char x[]랑 char *x랑 같다		char x[1] == char*(x+1)
{
	int i, *j;
	//char e[] = "ABCDE";	//read only되는 메모리에 ABCDE를 저장하고 그걸 복사한 값을 e[]에다가 넣는다	<= e는 test함수가 사라지면 보호받지 못하는 메모리
	char* e = "ABCDE";		//read only되는 메모리에 ABCDE를 저장하고 그걸 가리키는 주소를 e에 넣는다

	a = 'R';
	x[2] = 'R';
	f[2] = 'R';

	return e;
}

int main()
{
	char a, *b;
	char i, *j;

	char c[5];
	char d[10];
	char e[6] = "ABCDE";
	char *f = "abcde";		//read only되는 메모리에 abcde를 저장하고 그걸 가리키는 주소값을 f에 저장

	j = test(a, e, f);
	printf("%s\n", f);
	printf("%s", j);
}
										//정리			test에서 main을 가리키는건 괜찮지만
										//				main에서 test를 가리키면 안괜찮음
#endif	//	수업
