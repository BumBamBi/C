#include <stdio.h>

#if 0

int main()
{
	//char Ÿ���� 1byte�� �������

	char a1;					//���� ����
	char a2 = 'a';				//a�� �ƽ�Ű�ڵ带 ����
	char a3 = "a";				//�ǵ� �ȵǴ� 2���ڸ� 1���� �ڸ��� �������� �ϴ� �ȵ� (�������� �ǵ� �ּҰ��� ��)
	char a4 = "abcd";			//5���ڸ� 1���� �ڸ��� �������� �ϴ� �ȵ� (�������� �ǵ� �ּҰ��� ��)

	char b1[5];
	char b2[5] = { 'a','b','c','d','e' };		//�� ���ĺ��� �ƽ�Ű���� �� ����Ʈ�� �����
	char b3[5] = "abcd";						//X		""���� ���� �޸𸮿� ���� �� �� �޸𸮸� ����Ű�� �ּҰ��� ������ ������ 
												//		char 1byte 4���� �ƴ϶� 4byte 1�� �ʿ�
	char b4[] = "abcd";							//X		���� ��������
	char b5[];									//X

	char *c1;									//O
	char *c2 = "abcde";							//O
	char *c3 = { 'a','b','c','d','e' };			//X
	char *c4 = "";								//O		null�� ����
	char *c5 = '';								//X		'' �ȿ��� ���� ����ߵ�.		'a' �ص� �ȵ� *cp�� �ּҰ� �����ϴµ� 'a'�� �ƽ�Ű�ڵ� ����
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

#endif	//�⺻ ����


#if 0

//���ڿ��� ���̸� ��ȯ�ϴ� �Լ�(null����)
//�����
//			�Լ� �̸� ����				- strlen()
//			�Լ� ��ȯ�� ����			- unsigned int
//			�Լ� ���� ���� ���� ����	- ���� 1�� (���ڿ��� �Է¹��� ���� char*)	-���ڿ��� ���� �ʴ� ������ 4byte �̻�� �� ���� �����ؾ���
//		
//																			 ������ �뷮�� ���ڿ��� 2�� �ʿ�����, ��¼�� �����Ǹ� ���ʿ��� �۾�

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
	char *str1 = str;			//"abcde" �� ó���� a�� �ּҰ��� str�� ������ ���� *

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

#endif	//strlen() --2	//int length �Ⱦ���


#if 0

//strcpy�Լ� �����
//���ڿ��� �����ϴ� �Լ�
//������
//		�Լ� �̸� ����				-strcpy()
//		�Լ� ��ȯ�� ����			-
//		�Լ� ���ڼ��� ���� ����		- ~���� ~�� ���� �ּ� 2���� ����


//1��

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

//2��

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

//strcat�Լ� �����
//���ڿ��� �̾�ٴ� �Լ�
//������
//		�Լ� �̸� ����				-strcat()
//		�Լ� ��ȯ�� ����			-
//		�Լ� ���ڼ��� ���� ����		-

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
	char a[] = "abcde";		//������ ��� ����
	char b[] = "abcde";
	strcat(a, b);
	printf("%s\n", a);
	return 0;
}

#endif	//strcat() --1	//���� - ���� ����


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

//strstr�Լ� �����
//���ڿ����� ���ڰ� ����� �ּҸ� ����ϴ� �Լ�
//������
//		�Լ� �̸� ����				-strstr()
//		�Լ� ��ȯ�� ����			-char*
//		�Լ� ���ڼ��� ���� ����		-

//1��

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

#endif	//strstr() --1	//���� - abcabd���� abd�� ��������


#if 0	

//2�� (1�� ���)

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

#endif	//strstr() --2	//���� - abcabd���� abd�� ��������


#if 0
char* strstr(char*a, char*b)
{
	char* out_a = a;				//out_a�� (abcd,ad) �� �ƴ� ��� ��ȯ�� a�� �ּ�
	char* origin_b = b;				//*b�� �����Ҷ� �ʿ��� ������ b�� �ּ�

	while (1)						//�ݺ��� << ���� �߿�
	{
		while (*a != *b)					//while�� �������
		{									//
			a++;							//
			out_a = a;						//�������		=>	 *b�� ó�� ���� *a�� �ִٸ� �� ���� out_a�� �־��� (=> *out_a�� *b�� ���� �������)
			if (*out_a == NULL)						//���� ���� �� b�� �����ϰ� �Դµ� *b�� �������� ���� *a�� ������ NULL��ȯ  (abcd, bd)
			{
				return NULL;
			}
		}

		if (*a == *b)						//a���� b���� ������
		{
			a++;									// a�� b�� 1�� ����
			b++;

			if (*b == NULL)							//�� �� b�� ������ loop�Ǽ� NULL���� �Ǹ�
			{
				return out_a;								//out_a��ȯ (abcd, ab)  (abcd, cd)
			}
		}
		if (*a != *b)						//a���� b���� �ٸ���
		{
			b = origin_b;							//b�� ���½�Ű��
			out_a = a;								//out_a�� �缳����	(abddc, dc)�� �� (dc,c) ���� ���� ������ (dc,dc)�� �ȴ�.
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
#endif	//������ ����


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
#endif	//strstr() //������2


#if 0
char* strstr(char *a, char *b)  // �μ��� �����ͷ� �޾� �ּҰ��� ���� �� �ְ� �Ѵ�.
{
	char* p = b;  // ���߿� ��� b�� ����Ű�� �ּҰ� �ٲ�� ������ b�� ù�ּҸ� ������ ���� p�� ������ ���´�.
	int cnt = 0;   // count�ϴ� �����ϳ��� �����Ѵ�.

	while (1)  // break�� ���� ������ �ݺ��ϴ� �ݺ����� ����.
	{
		if (*b == *a)  // b�� �ּҿ� �ִ� ���� a�� �ּҿ� �ִ� ���� ������ if�� ������ ����.
		{
			b++; a++;  // �� ���� ���� ������ Ȯ���ϱ� ���� a�� b�� ����Ų �ּҸ� �ϳ� �ڷ� �ѱ��.
			cnt++;      // cnt�� ���߿� ���ϰ��� ���� �ִ� ���ε� ������ a�� ����Ų �ּҰ� 

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
#endif	//strstr() //������


#if 0
char* test(char a, char x[], char f[])	//char x[]�� char *x�� ����		char x[1] == char*(x+1)
{
	int i, *j;
	//char e[] = "ABCDE";	//read only�Ǵ� �޸𸮿� ABCDE�� �����ϰ� �װ� ������ ���� e[]���ٰ� �ִ´�	<= e�� test�Լ��� ������� ��ȣ���� ���ϴ� �޸�
	char* e = "ABCDE";		//read only�Ǵ� �޸𸮿� ABCDE�� �����ϰ� �װ� ����Ű�� �ּҸ� e�� �ִ´�

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
	char *f = "abcde";		//read only�Ǵ� �޸𸮿� abcde�� �����ϰ� �װ� ����Ű�� �ּҰ��� f�� ����

	j = test(a, e, f);
	printf("%s\n", f);
	printf("%s", j);
}
										//����			test���� main�� ����Ű�°� ��������
										//				main���� test�� ����Ű�� �ȱ�����
#endif	//	����
