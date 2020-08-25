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

void play(int(*p)[TONE_NUMBER]);

short data[SAMPLING_RATE];
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
	/* 실제 데이타의 총 크기 */ sizeof(data) * 4 };
/* 이하 Sample data : 여기서 부터 음성 데이터의 시작. */


void main()
{

	p_wfile = fopen(WAVE_FILE, "wb");

	//   header 정보 저장
	fwrite(&PCMWave, sizeof(struct WaveFormat), 1, p_wfile);

	//   data 생성

	int string1[DISTANCE][TONE_NUMBER] = { { G4,E4,D4,C3,NULL },{ G4,E4,D4,G3,NULL } ,{ G4,G3,NULL,NULL,NULL },{ C4,G3,NULL,NULL,NULL },{ E4,A3s,F3,G2,NULL },{ F4,F3,G2,NULL,NULL },{ G4, D4, B3, E3, C3 },{ G4,D4,B3,E3,C3 } };

	play(string1);

	int string2[DISTANCE][TONE_NUMBER] = { { A4, E4,C4,F3,D3 } ,{ A4, E4,C4,F3,D3 } ,{ A4,D4s,B3,F3,G2 } ,{ A4,D4s,B3,F3,G2 } ,{ G4,E4,D4,E3,C3 } ,{ G3,D3,C3,NULL,NULL } ,{ C4,E3,C3,NULL,NULL } ,{ B3,E3,C3,NULL,NULL } };

	play(string2);

	int string3[DISTANCE][TONE_NUMBER] = { { G4,E4,C4,G3,A2 } ,{ G4,E4,C4,E3,NULL },{ C5,A3,NULL,NULL,NULL } ,{ C5,A3,NULL,NULL,NULL } ,{ E5,A4,F4s,C4,D3 } ,{ E5,A4,F4s,F3s,NULL } ,{ D5,C4,NULL,NULL,NULL } ,{ C5,C4,NULL,NULL,NULL } };

	play(string3);

	int string4[DISTANCE][TONE_NUMBER] = { { D5,G4s,F4,G3s,A2s } ,{ D5,G4s,F4,F3,NULL } ,{ D5,G4s,F4,G3s,NULL } ,{ C4,G3s,NULL,NULL,NULL } ,{ A4s,D4s,B3,F3,G2 } ,{ A4,F3,G2,NULL,NULL } ,{ G4,F3,G2,NULL,NULL } ,{ F4,F3,G2,NULL,NULL } };

	play(string4);

	fclose(p_wfile);
}

void play(int(*p)[TONE_NUMBER])
{

	float signal1;
	float signal2;
	float signal3;
	float signal4;
	float signal5;
	int div[DISTANCE];
	int i, n;

#if 1
	for (i = 0; i < DISTANCE; i++)
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
#endif	// div[]  ==> signal 나눌 값인 div 설정


#if 1
	i = 0;

	for (n = 0; n< (SAMPLING_RATE / DISTANCE); n++)//솔
	{
		if (p[i][0]) signal1 = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE); else signal1 = 0.0;
		if (p[i][1]) signal2 = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE); else signal2 = 0.0;
		if (p[i][2]) signal3 = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE); else signal3 = 0.0;
		if (p[i][3]) signal4 = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE); else signal4 = 0.0;
		if (p[i][4]) signal5 = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE); else signal5 = 0.0;
		data[n] = (short)((signal1 + signal2 + signal3 + signal4 + signal5) / div[i]);
	}
	i++;
	for (n = (SAMPLING_RATE / DISTANCE); n< (SAMPLING_RATE * 2 / DISTANCE); n++)//솔
	{
		if (p[i][0]) signal1 = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE); else signal1 = 0.0;
		if (p[i][1]) signal2 = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE); else signal2 = 0.0;
		if (p[i][2]) signal3 = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE); else signal3 = 0.0;
		if (p[i][3]) signal4 = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE); else signal4 = 0.0;
		if (p[i][4]) signal5 = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE); else signal5 = 0.0;
		data[n] = (short)((signal1 + signal2 + signal3 + signal4 + signal5) / div[i]);
	}
	i++;
	for (n = (SAMPLING_RATE * 2 / DISTANCE); n< (SAMPLING_RATE * 3 / DISTANCE); n++)//솔
	{
		if (p[i][0]) signal1 = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE); else signal1 = 0.0;
		if (p[i][1]) signal2 = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE); else signal2 = 0.0;
		if (p[i][2]) signal3 = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE); else signal3 = 0.0;
		if (p[i][3]) signal4 = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE); else signal4 = 0.0;
		if (p[i][4]) signal5 = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE); else signal5 = 0.0;
		data[n] = (short)((signal1 + signal2 + signal3 + signal4 + signal5) / div[i]);
	}
	i++;
	for (n = (SAMPLING_RATE * 3 / DISTANCE); n< (SAMPLING_RATE * 4 / DISTANCE); n++)//솔
	{
		if (p[i][0]) signal1 = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE); else signal1 = 0.0;
		if (p[i][1]) signal2 = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE); else signal2 = 0.0;
		if (p[i][2]) signal3 = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE); else signal3 = 0.0;
		if (p[i][3]) signal4 = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE); else signal4 = 0.0;
		if (p[i][4]) signal5 = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE); else signal5 = 0.0;
		data[n] = (short)((signal1 + signal2 + signal3 + signal4 + signal5) / div[i]);
	}
	i++;
	for (n = (SAMPLING_RATE * 4 / DISTANCE); n< (SAMPLING_RATE * 5 / DISTANCE); n++)//솔
	{
		if (p[i][0]) signal1 = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE); else signal1 = 0.0;
		if (p[i][1]) signal2 = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE); else signal2 = 0.0;
		if (p[i][2]) signal3 = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE); else signal3 = 0.0;
		if (p[i][3]) signal4 = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE); else signal4 = 0.0;
		if (p[i][4]) signal5 = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE); else signal5 = 0.0;
		data[n] = (short)((signal1 + signal2 + signal3 + signal4 + signal5) / div[i]);
	}
	i++;
	for (n = (SAMPLING_RATE * 5 / DISTANCE); n< (SAMPLING_RATE * 6 / DISTANCE); n++)//솔
	{
		if (p[i][0]) signal1 = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE); else signal1 = 0.0;
		if (p[i][1]) signal2 = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE); else signal2 = 0.0;
		if (p[i][2]) signal3 = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE); else signal3 = 0.0;
		if (p[i][3]) signal4 = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE); else signal4 = 0.0;
		if (p[i][4]) signal5 = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE); else signal5 = 0.0;
		data[n] = (short)((signal1 + signal2 + signal3 + signal4 + signal5) / div[i]);
	}
	i++;
	for (n = (SAMPLING_RATE * 6 / DISTANCE); n< (SAMPLING_RATE * 7 / DISTANCE); n++)//솔
	{
		if (p[i][0]) signal1 = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE); else signal1 = 0.0;
		if (p[i][1]) signal2 = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE); else signal2 = 0.0;
		if (p[i][2]) signal3 = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE); else signal3 = 0.0;
		if (p[i][3]) signal4 = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE); else signal4 = 0.0;
		if (p[i][4]) signal5 = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE); else signal5 = 0.0;
		data[n] = (short)((signal1 + signal2 + signal3 + signal4 + signal5) / div[i]);
	}
	i++;
	for (n = (SAMPLING_RATE * 7 / DISTANCE); n< (SAMPLING_RATE * 8 / DISTANCE); n++)//솔
	{
		if (p[i][0]) signal1 = AMPLITUDE*cos(2 * PI * p[i][0] * n / SAMPLING_RATE); else signal1 = 0.0;
		if (p[i][1]) signal2 = AMPLITUDE*cos(2 * PI * p[i][1] * n / SAMPLING_RATE); else signal2 = 0.0;
		if (p[i][2]) signal3 = AMPLITUDE*cos(2 * PI * p[i][2] * n / SAMPLING_RATE); else signal3 = 0.0;
		if (p[i][3]) signal4 = AMPLITUDE*cos(2 * PI * p[i][3] * n / SAMPLING_RATE); else signal4 = 0.0;
		if (p[i][4]) signal5 = AMPLITUDE*cos(2 * PI * p[i][4] * n / SAMPLING_RATE); else signal5 = 0.0;
		data[n] = (short)((signal1 + signal2 + signal3 + signal4 + signal5) / div[i]);
	}
#endif	// 8분음표 길이로 signal을 data에 넣음


	fwrite(data, sizeof(short int), SAMPLING_RATE, p_wfile);

}