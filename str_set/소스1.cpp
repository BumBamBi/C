#include<stdio.h>

int strlen(char*p)//문자열 길이 세는 함수
{
	int cnt = 0;
	while (*p != NULL)
	{
		cnt++;
		p++;
	}
	return cnt;
}

void strrev(char*str, int cnt)//문자열에 입력된 글자만큼 뒤집는 함수
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
	int cnt = strlen(str);//strlen를 실행한 후

	printf("원래 str : %s\n", str);

	strrev(str, cnt);//strlen에서 값을 가져온다.

	printf("뒤집은 restr : %s\n", str);

	return 0;
}
