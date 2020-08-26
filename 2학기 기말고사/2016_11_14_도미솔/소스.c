//도미솔

#include <stdio.h>
#include <math.h>

#define SAMPLING_RATE		44100
#define WAVE_TIME			1
#define FREQUENCY			262
#define WAVE_FILE			"도미솔.wav"			
#define AMPLITUDE			32000

#define PI 3.14159265
#define DWORD unsigned int
#define NUM_CHANNEL			1
#define BYTES_PER_SAMPLE	2
#define BYTE_RATE			SAMPLING_RATE*NUM_CHANNEL*BYTES_PER_SAMPLE

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
	short int data[SAMPLING_RATE];

	int n;
	int div;

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
		/* Sample rate * Block Align */ BYTE_RATE,
		/* Channel * Bit / sample/8 */  NUM_CHANNEL*BYTES_PER_SAMPLE, // Block Align
		/* Bit/sample: 8 or 16 */ 8 * BYTES_PER_SAMPLE,
		//------------------------------
		/* data chunk라는 것을 알림 */{ 'd','a','t','a' },
		/* 실제 데이타의 총 크기 */ BYTES_PER_SAMPLE*SAMPLING_RATE*WAVE_TIME*NUM_CHANNEL };
	/* 이하 Sample data : 여기서 부터 음성 데이터의 시작. */

	p_wfile = fopen(WAVE_FILE, "wb");

	//	header 정보 저장
	fwrite(&PCMWave, sizeof(struct WaveFormat), 1, p_wfile);

	//	온음표, 2분음표, 4분음표, 8분음표, 16분음표
	//div = 1;
	div = 2;
	//div = 4;
	//div = 8;
	//div = 16;

	//	data 생성

	//도미솔
	for (n = 0; n < SAMPLING_RATE / 2; n++)
	{
		short int signal1[SAMPLING_RATE];
		short int signal2[SAMPLING_RATE];
		short int signal3[SAMPLING_RATE];

		signal1[n] = AMPLITUDE*cos(2 * PI * 261.63 * n / SAMPLING_RATE);
		signal2[n] = AMPLITUDE*cos(2 * PI * 329.63 * n / SAMPLING_RATE);
		signal3[n] = AMPLITUDE*cos(2 * PI * 392 * n / SAMPLING_RATE);

		data[n] = ((short)signal1[n] + (short)signal2[n] + (short)signal3[n]) / 3;
	}

	//	data 저장
	fwrite(data, sizeof(short int), SAMPLING_RATE / div, p_wfile);

	for (n = 0; n < SAMPLING_RATE / 2; n++)
	{
		short int signal1[SAMPLING_RATE];
		short int signal2[SAMPLING_RATE];
		short int signal3[SAMPLING_RATE];

		signal1[n] = AMPLITUDE*cos(2 * PI * 261.63 * n / SAMPLING_RATE);
		signal2[n] = AMPLITUDE*cos(2 * PI * 329.63 * n / SAMPLING_RATE);
		signal3[n] = AMPLITUDE*cos(2 * PI * 392 * n / SAMPLING_RATE);

		data[n] = ((short)signal1[n] + (short)signal2[n] + (short)signal3[n]) / 3;
	}

	//	data 저장
	fwrite(data, sizeof(short int), SAMPLING_RATE / div, p_wfile);

	for (n = 0; n < SAMPLING_RATE / 2; n++)
	{
		short int signal1[SAMPLING_RATE];
		short int signal2[SAMPLING_RATE];
		short int signal3[SAMPLING_RATE];

		signal1[n] = AMPLITUDE*cos(2 * PI * 261.63 * n / SAMPLING_RATE);
		signal2[n] = AMPLITUDE*cos(2 * PI * 329.63 * n / SAMPLING_RATE);
		signal3[n] = AMPLITUDE*cos(2 * PI * 392 * n / SAMPLING_RATE);

		data[n] = ((short)signal1[n] + (short)signal2[n] + (short)signal3[n]) / 3;
	}

	//	data 저장
	fwrite(data, sizeof(short int), SAMPLING_RATE / div, p_wfile);

	fclose(p_wfile);
}