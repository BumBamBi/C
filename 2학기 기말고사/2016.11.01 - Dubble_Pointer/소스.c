#include<stdio.h>

int main()
{
	char* fruits[] = { "apple", "melon", "orange", "blueberry" };		//공간 낭비 X -> 데이터 공간 효율성↑

	char* fruits[][10] = { "apple", "melon", "orange", "blueberry" };		//공간의 낭비 발생 -> apple0xxxx
}