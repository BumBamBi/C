#include <stdio.h> //3번문제

#if 0

#include <math.h>

#define SAMPLING_RATE     44100				//샘플링 레이트는 44.1KHz
#define WAVE_TIME         1
#define FREQUENCY         262
#define WAVE_FILE         "C4.wav"         
#define AMPLITUDE         10000				//진폭은 +- 10000

#define PI 3.14159265
#define DWORD unsigned int
#define NUM_CHANNEL         1
#define BYTES_PER_SAMPLE   2
#define BYTE_RATE         SAMPLING_RATE*NUM_CHANNEL*BYTES_PER_SAMPLE


struct WaveFormat {
	char RiffTag[4]; // "RIFF"
	DWORD FileLength; // File Size
	char PFormatTag[4]; // "WAVE"
						//===================================================== 부모 chunk.
	char SFormatTag[4]; // "fmt"
	DWORD FormatLength; // 16
	short DataFormat; // 1
	short NumChannels; // 1
	DWORD nSamplesPerSec; // 100
	DWORD nAvgBytesperSec; // nSamplesPerSec * BlockAlign
	short BlockAlign; // nChannel * bit / 8
	short wBitPerSample; // 샘플당 비트수
						 //===================================================== 자식 chunk.
	char DataTag[4]; // "data"
	DWORD DataLength; // Data Size
					  //===================================================== 데이타 chunk.
} PCMFormat;


void main()
{
	FILE *p_wfile;
	short int data[44100];
	float signal[3];
	int div[5] = { 1,2,4,8,16 };
	struct WaveFormat PCMWave = {
		/* Riff 화일의 식별자 */{ 'R','I','F','F' },
		/* Riff화일의헤더제외총길이 */ sizeof(struct WaveFormat) + sizeof(data) - 8,
		/* Form Type을 말한다. */{ 'W','A','V','E' },
		//-----------------------------   
		/* Format Chunk 문자열 */{ 'f','m','t','\x20' },
		/* Length of the fmt data */ 16,
		/* Format Tag:1 = PCM */ 1,
		/* Channel:1=mono, 2=streo */ 1,
		/* Samples per Second:44100 */ 44100,
		/* Sample rate * Block Align */ 88200,
		/* Channel * Bit / sample/8 */  2, // Block Align
		/* Bit/sample: 8 or 16 */ 16,
		//------------------------------
		/* data chunk라는 것을 알림 */{ 'd','a','t','a' },
		/* 실제 데이타의 총 크기 */ sizeof(data) * 2 };					// 총 2초의 사운드 파일
	/* 이하 Sample data : 여기서 부터 음성 데이터의 시작. */

	p_wfile = fopen(WAVE_FILE, "wb");

	//   header 정보 저장
	fwrite(&PCMWave, sizeof(struct WaveFormat), 1, p_wfile);

	//   온음표, 2분음표, 4분음표, 8분음표, 16분음표
	int fdata[3][44100];										//각 signal 을 넣어줄 변 fakedata인 fdata생성
	int n = 0;													//변수 n 생성 후 0으로 초기화
	int S1 = 207;												//주파수 값인 S1, S2, S3 생성 후 초기화
	int S2 = 440;
	int S3 = 900;

	for (int a = 0; a < 2; a++)													//총 2번 반복
	{
		for (int i = 0; i < 10; i++)															//10회 반복한다
		{
			for (0.1 * i; n < 0.1*(i + 1) * 44100; n++, S1 = S1 + 27)									//i가 0.1초씩 주파수 S1을 넣음. 1회 반복 끝나면 S1은 27씩 증가하고 n값은 1씩 증가
			{
				signal[0] = AMPLITUDE*cos(2 * PI * S1 * n / 44100);										//S1이 signal[0]값에 들어가고
				fdata[0][n] = (short)(signal[0]);														//이를 fdata에 저장
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (0.2* i; n < 0.1*(i + 1) * 44100; n++, S2 = S2 + 38)							//이하 같고 S2의 증가량이 38임
			{
				signal[0] = AMPLITUDE*cos(2 * PI * S2 * n / 44100);
				fdata[0][n] = (short)(signal[0]);
			}
		}
		for (float i = 0; i < 2.5; i++)
		{
			for (0.4 * i; n < 0.1*(i + 1) * 44100; n++, S3 = S3 - 16)							//2.5회이므로 foat를 써주고 감소량이 16임
			{
				signal[0] = AMPLITUDE*cos(2 * PI * S3 * n / 44100);
				fdata[0][n] = (short)(signal[0]);
			}
		}
		for (int n = 0; n < 44100; n++)
		{
			data[n] = (short)((fdata[0][n] + fdata[1][n] + fdata[2][n]) / 3);					//data에 fdata값들을 다 넣고 3으로 나눔
		}
		fwrite(data, sizeof(short int), 44100, p_wfile);								//fwrite
	}

	fclose(p_wfile);
}
#endif

#if 1
int MyStrcat(char* a, char* b, char* c)	// 함수 인자들을 전부 char* 형식으로 받아옴
{
	int n = 0;							//변수 n 생성 후 초기화
	int nn = 0;							//변수 nn 생성 후 초기화

	while (a[n] != NULL)				//a[n]의 값이 NULL이 아니면 반복
	{
		c[n] = a[n];						//c[n]에 a[n]의 값을 대입
		n++;								//n에 1을 더함
	}

	while (b[nn] != NULL)				//b[nn]의 값이 NULL이 아니면 반복
	{
		c[n] = b[nn];						//c[n]의 값에 b[nn]의 값을 대입
		n++;								//n에 1을 더함
		nn++;								//nn에 1을 더함
	}

	printf("%s", c);					//c를 %s로 출력

	return 0;							//반환값 0
}

int main()
{
	char a[] = "안녕하세요!";			//앞부분 문자열 생성 후 초기화
	char b[] = "저는 이광우입니다.";	//뒷부분 문자열 생헝 후 초기화
	char c[100] = {};					//복사후 저장될 문자열 공간 생성
	MyStrcat(a, b, c);					//함수 호출
}
#endif // 2번


#if 0
void test(char (*p)[4][5])					//함수 인자로 char (*p)[4][5]를 받고
{
	for (int i = 0; i < 3; i++)				//3번 반복 (1차원)
	{
		for (int j = 0; j < 4; j++)			//4번 반복 (2차원)
		{
			for (int k = 0; k < 5; k++)		//5번 반복 (3차원)
			{
				p[i][j][k] = 33;			//따라서 p[0][0][0] 부터 차례대로 p[3][4][5] 까지 33값을 대입한다.
			}
		}
	}
}

int main()
{
	char data[3][4][5];			//배열 선언

	char(*p)[4][5] = data;		//배열 포인터생성후 data값으로 초기화
								//char (*p)[4][5]로 준 이유는 3차원 배열이므로
								//2차원 배열때 쓰이던 (*p)[4]에 [5]라는 차원을 하나 더 얹어준 모양이다

	test(p);					//함수를 호출한다



	for (int i = 0; i < 3; i++)				
	{
		for (int j = 0; j < 4; j++)			
		{
			for (int k = 0; k < 5; k++)		
			{
				printf("%d\n",p[i][j][k]);			//출력값 확인
			}
		}
	}
}
#endif	//3번