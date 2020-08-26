#include<stdio.h>
#include<math.h>
#define PI 3.14159265


/*
void main()
{
	short signal;
	short signal1;
	short signal2;
	short signal3;
	short signal4;
	

	FILE *fp;

	fp = fopen("signal.txt", "wb");

	for (int n = 0; n < 1000; n++)
	{
		signal1 = (short)100 * cos(2 * PI*n / 1000);
		signal2 = (short)-100 * cos(2 * PI * 3 * n / 1000) / 3;
		signal3 = (short)100 * cos(2 * PI * 5 * n / 1000) / 5;
		signal4 = (short)-100 * cos(2 * PI * 7 * n / 1000) / 7;
		signal = (short)(signal1 + signal2 + signal3 + signal4);
		fprintf(fp, "%d\r\n", signal);
	}

	fclose(fp);
}

*/

int main()
{
	short signal;


	FILE *fp;

	fp = fopen("signal_A.txt", "wb");

	for (int n = 0; n < 44100; n++)
	{
		signal = (short)30000 * cos(2 * PI * 462 * n / 44100);
		fprintf(fp, "%d\r\n", signal);
	}

	fclose(fp);
}