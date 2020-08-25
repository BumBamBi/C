#include <stdio.h> //3������

#if 0

#include <math.h>

#define SAMPLING_RATE     44100				//���ø� ����Ʈ�� 44.1KHz
#define WAVE_TIME         1
#define FREQUENCY         262
#define WAVE_FILE         "C4.wav"         
#define AMPLITUDE         10000				//������ +- 10000

#define PI 3.14159265
#define DWORD unsigned int
#define NUM_CHANNEL         1
#define BYTES_PER_SAMPLE   2
#define BYTE_RATE         SAMPLING_RATE*NUM_CHANNEL*BYTES_PER_SAMPLE


struct WaveFormat {
	char RiffTag[4]; // "RIFF"
	DWORD FileLength; // File Size
	char PFormatTag[4]; // "WAVE"
						//===================================================== �θ� chunk.
	char SFormatTag[4]; // "fmt"
	DWORD FormatLength; // 16
	short DataFormat; // 1
	short NumChannels; // 1
	DWORD nSamplesPerSec; // 100
	DWORD nAvgBytesperSec; // nSamplesPerSec * BlockAlign
	short BlockAlign; // nChannel * bit / 8
	short wBitPerSample; // ���ô� ��Ʈ��
						 //===================================================== �ڽ� chunk.
	char DataTag[4]; // "data"
	DWORD DataLength; // Data Size
					  //===================================================== ����Ÿ chunk.
} PCMFormat;


void main()
{
	FILE *p_wfile;
	short int data[44100];
	float signal[3];
	int div[5] = { 1,2,4,8,16 };
	struct WaveFormat PCMWave = {
		/* Riff ȭ���� �ĺ��� */{ 'R','I','F','F' },
		/* Riffȭ������������ѱ��� */ sizeof(struct WaveFormat) + sizeof(data) - 8,
		/* Form Type�� ���Ѵ�. */{ 'W','A','V','E' },
		//-----------------------------   
		/* Format Chunk ���ڿ� */{ 'f','m','t','\x20' },
		/* Length of the fmt data */ 16,
		/* Format Tag:1 = PCM */ 1,
		/* Channel:1=mono, 2=streo */ 1,
		/* Samples per Second:44100 */ 44100,
		/* Sample rate * Block Align */ 88200,
		/* Channel * Bit / sample/8 */  2, // Block Align
		/* Bit/sample: 8 or 16 */ 16,
		//------------------------------
		/* data chunk��� ���� �˸� */{ 'd','a','t','a' },
		/* ���� ����Ÿ�� �� ũ�� */ sizeof(data) * 2 };					// �� 2���� ���� ����
	/* ���� Sample data : ���⼭ ���� ���� �������� ����. */

	p_wfile = fopen(WAVE_FILE, "wb");

	//   header ���� ����
	fwrite(&PCMWave, sizeof(struct WaveFormat), 1, p_wfile);

	//   ����ǥ, 2����ǥ, 4����ǥ, 8����ǥ, 16����ǥ
	int fdata[3][44100];										//�� signal �� �־��� �� fakedata�� fdata����
	int n = 0;													//���� n ���� �� 0���� �ʱ�ȭ
	int S1 = 207;												//���ļ� ���� S1, S2, S3 ���� �� �ʱ�ȭ
	int S2 = 440;
	int S3 = 900;

	for (int a = 0; a < 2; a++)													//�� 2�� �ݺ�
	{
		for (int i = 0; i < 10; i++)															//10ȸ �ݺ��Ѵ�
		{
			for (0.1 * i; n < 0.1*(i + 1) * 44100; n++, S1 = S1 + 27)									//i�� 0.1�ʾ� ���ļ� S1�� ����. 1ȸ �ݺ� ������ S1�� 27�� �����ϰ� n���� 1�� ����
			{
				signal[0] = AMPLITUDE*cos(2 * PI * S1 * n / 44100);										//S1�� signal[0]���� ����
				fdata[0][n] = (short)(signal[0]);														//�̸� fdata�� ����
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (0.2* i; n < 0.1*(i + 1) * 44100; n++, S2 = S2 + 38)							//���� ���� S2�� �������� 38��
			{
				signal[0] = AMPLITUDE*cos(2 * PI * S2 * n / 44100);
				fdata[0][n] = (short)(signal[0]);
			}
		}
		for (float i = 0; i < 2.5; i++)
		{
			for (0.4 * i; n < 0.1*(i + 1) * 44100; n++, S3 = S3 - 16)							//2.5ȸ�̹Ƿ� foat�� ���ְ� ���ҷ��� 16��
			{
				signal[0] = AMPLITUDE*cos(2 * PI * S3 * n / 44100);
				fdata[0][n] = (short)(signal[0]);
			}
		}
		for (int n = 0; n < 44100; n++)
		{
			data[n] = (short)((fdata[0][n] + fdata[1][n] + fdata[2][n]) / 3);					//data�� fdata������ �� �ְ� 3���� ����
		}
		fwrite(data, sizeof(short int), 44100, p_wfile);								//fwrite
	}

	fclose(p_wfile);
}
#endif

#if 1
int MyStrcat(char* a, char* b, char* c)	// �Լ� ���ڵ��� ���� char* �������� �޾ƿ�
{
	int n = 0;							//���� n ���� �� �ʱ�ȭ
	int nn = 0;							//���� nn ���� �� �ʱ�ȭ

	while (a[n] != NULL)				//a[n]�� ���� NULL�� �ƴϸ� �ݺ�
	{
		c[n] = a[n];						//c[n]�� a[n]�� ���� ����
		n++;								//n�� 1�� ����
	}

	while (b[nn] != NULL)				//b[nn]�� ���� NULL�� �ƴϸ� �ݺ�
	{
		c[n] = b[nn];						//c[n]�� ���� b[nn]�� ���� ����
		n++;								//n�� 1�� ����
		nn++;								//nn�� 1�� ����
	}

	printf("%s", c);					//c�� %s�� ���

	return 0;							//��ȯ�� 0
}

int main()
{
	char a[] = "�ȳ��ϼ���!";			//�պκ� ���ڿ� ���� �� �ʱ�ȭ
	char b[] = "���� �̱����Դϴ�.";	//�޺κ� ���ڿ� ���� �� �ʱ�ȭ
	char c[100] = {};					//������ ����� ���ڿ� ���� ����
	MyStrcat(a, b, c);					//�Լ� ȣ��
}
#endif // 2��


#if 0
void test(char (*p)[4][5])					//�Լ� ���ڷ� char (*p)[4][5]�� �ް�
{
	for (int i = 0; i < 3; i++)				//3�� �ݺ� (1����)
	{
		for (int j = 0; j < 4; j++)			//4�� �ݺ� (2����)
		{
			for (int k = 0; k < 5; k++)		//5�� �ݺ� (3����)
			{
				p[i][j][k] = 33;			//���� p[0][0][0] ���� ���ʴ�� p[3][4][5] ���� 33���� �����Ѵ�.
			}
		}
	}
}

int main()
{
	char data[3][4][5];			//�迭 ����

	char(*p)[4][5] = data;		//�迭 �����ͻ����� data������ �ʱ�ȭ
								//char (*p)[4][5]�� �� ������ 3���� �迭�̹Ƿ�
								//2���� �迭�� ���̴� (*p)[4]�� [5]��� ������ �ϳ� �� ����� ����̴�

	test(p);					//�Լ��� ȣ���Ѵ�



	for (int i = 0; i < 3; i++)				
	{
		for (int j = 0; j < 4; j++)			
		{
			for (int k = 0; k < 5; k++)		
			{
				printf("%d\n",p[i][j][k]);			//��°� Ȯ��
			}
		}
	}
}
#endif	//3��