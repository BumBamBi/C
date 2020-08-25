#include<stdio.h>
#include <math.h>

#define SAMPLING_RATE      10000
#define WAVE_TIME         1
#define FREQUENCY         262
#define WAVE_FILE         "Song.wav"         
#define AMPLITUDE         30000
#define DISTANCE        8 //   온음표, 2분음표, 4분음표, 8분음표, 16분음표
#define TONE_NUMBER        5 //   음의 최대 갯수



#define PI 3.14159265
#define DWORD unsigned int
#define NUM_CHANNEL         1
#define BYTES_PER_SAMPLE   2
#define BYTE_RATE         SAMPLING_RATE*NUM_CHANNEL*BYTES_PER_SAMPLE

#define G2 97
#define A2 110
#define A2s 116
#define C3 130
#define C3s 138
#define D3 146
#define D3s 155
#define E3 164
#define F3 174
#define F3s 184
#define G3 195
#define G3s 207
#define A3 220
#define A3s 233
#define B3 246

#define C4 261
#define C4s 277
#define D4 293
#define D4s 311
#define E4 329
#define F4 349
#define F4s 369
#define G4 392
#define G4s 415
#define A4 440
#define A4s 466
#define B4 493

#define C5 523
#define C5s 554
#define D5 587
#define D5s 622
#define E5 659
#define F5 698
#define F5s 739
#define G5 783
#define G5s 830
#define A5 880
#define A5s 932
#define B5 987

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


char data[SAMPLING_RATE];


FILE *p_wfile;



struct WaveFormat PCMWave = {
	/* Riff 화일의 식별자 */{ 'R','I','F','F' },
	/* Riff화일의헤더제외총길이 */ sizeof(struct WaveFormat) + sizeof(data) - 8,
	/* Form Type을 말한다. */{ 'W','A','V','E' },
	//-----------------------------   
	/* Format Chunk 문자열 */{ 'f','m','t','\x20' },
	/* Length of the fmt data */ 16,
	/* Format Tag:1 = PCM */ 1,
	/* Channel:1=mono, 2=streo */ 1,
	/* Samples per Second:44100 */ SAMPLING_RATE,
	/* Sample rate * Block Align */ SAMPLING_RATE * 2,
	/* Channel * Bit / sample/8 */  2, // Block Align
	/* Bit/sample: 8 or 16 */ 16,
	//------------------------------
	/* data chunk라는 것을 알림 */{ 'd','a','t','a' },
	/* 실제 데이타의 총 크기 */ sizeof(data) * 8 };
/* 이하 Sample data : 여기서 부터 음성 데이터의 시작. */

void pla(int(*p)[TONE_NUMBER], char *data)
{

	double signal1[10];
	double signal2[10];
	double signal3[10];
	double signal4[10];
	double signal5[10];
	int div[DISTANCE];

	for (int i = 0; i < DISTANCE; i++)
	{
		if (p[i][0] == NULL)
		{
			div[i] = 0;
		}
		else if (p[i][1] == NULL)
		{
			div[i] = 1;
		}
		else if (p[i][2] == NULL)
		{
			div[i] = 2;
		}
		else if (p[i][3] == NULL)
		{
			div[i] = 3;
		}
		else if (p[i][4] == NULL)
		{
			div[i] = 4;
		}
		else
		{
			div[i] = 5;
		}
	}
	int i = 0;
	for (int n = 0; n< (SAMPLING_RATE / DISTANCE); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / div[i]);
	}
	i = 1;
	for (int n = (SAMPLING_RATE / DISTANCE); n< (SAMPLING_RATE * 2 / DISTANCE); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / div[i]);
	}
	i = 2;
	for (int n = (SAMPLING_RATE / DISTANCE); n< (SAMPLING_RATE * 3 / DISTANCE); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / div[i]);
	}
	i = 3;
	for (int n = (SAMPLING_RATE / DISTANCE); n< (SAMPLING_RATE * 4 / DISTANCE); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / div[i]);
	}
	i = 4;
	for (int n = (SAMPLING_RATE / DISTANCE); n< (SAMPLING_RATE * 5 / DISTANCE); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / div[i]);
	}
	i = 5;
	for (int n = (SAMPLING_RATE / DISTANCE); n< (SAMPLING_RATE * 6 / DISTANCE); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / div[i]);
	}
	i = 6;
	for (int n = (SAMPLING_RATE / DISTANCE); n< (SAMPLING_RATE * 7 / DISTANCE); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / div[i]);
	}
	i = 7;
	for (int n = (SAMPLING_RATE / DISTANCE); n< (SAMPLING_RATE * 8 / DISTANCE); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / div[i]);
	}

	fwrite(data, sizeof(short char), SAMPLING_RATE, p_wfile);

}

void main()
{

	p_wfile = fopen(WAVE_FILE, "wb");

	//   header 정보 저장
	fwrite(&PCMWave, sizeof(struct WaveFormat), 1, p_wfile);

	//   data 생성

	int string1[DISTANCE][TONE_NUMBER] = { { G4,E4,D4,C3,NULL },{ G4,E4,D4,G3,NULL } ,{ G4,G3,NULL,NULL,NULL },{ C4,G3,NULL,NULL,NULL },{ E4,A3s,F3,G2,NULL },{ F4,F3,G2,NULL,NULL },{ G4, D4, B3, E3, C3 },{ G4,D4,B3,E3,C3 } };

	pla(string1, &data[0]);



	int string2[DISTANCE][TONE_NUMBER] = { { A4, E4,C4,F3,D3 } ,{ A4, E4,C4,F3,D3 } ,{ A4,D4s,B3,F3,G2 } ,{ A4,D4s,B3,F3,G2 } ,{ G4,E4,D4,E3,C3 } ,{ G3,D3,C3,NULL,NULL } ,{ C4,E3,C3,NULL,NULL } ,{ B3,E3,C3,NULL,NULL } };

	pla(string2, &data[0]);


	fclose(p_wfile);
}

