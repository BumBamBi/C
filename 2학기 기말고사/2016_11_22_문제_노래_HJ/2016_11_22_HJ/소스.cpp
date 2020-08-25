#include <stdio.h>
#include <math.h>

#define SAMPLING_RATE      10000
#define WAVE_TIME         1
#define FREQUENCY         262
#define WAVE_FILE         "C4.wav"         
#define AMPLITUDE         30000

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

#define C4 261.63
#define C4s 277
#define D4 293.65
#define D4s 311
#define E4 329.62
#define F4 349.22
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


void main()
{
	FILE *p_wfile;
	short int data[10000];
	float signal1[10];
	float signal2[10];
	float signal3[10];
	float signal4[10];
	float signal5[10];
	int n;
	int div = 8;
	struct WaveFormat PCMWave = {
		/* Riff 화일의 식별자 */{ 'R','I','F','F' },
		/* Riff화일의헤더제외총길이 */ sizeof(struct WaveFormat) + sizeof(data) - 8,
		/* Form Type을 말한다. */{ 'W','A','V','E' },
		//-----------------------------   
		/* Format Chunk 문자열 */{ 'f','m','t','\x20' },
		/* Length of the fmt data */ 16,
		/* Format Tag:1 = PCM */ 1,
		/* Channel:1=mono, 2=streo */ 1,
		/* Samples per Second:44100 */ 10000,
		/* Sample rate * Block Align */ 20000,
		/* Channel * Bit / sample/8 */  2, // Block Align
		/* Bit/sample: 8 or 16 */ 16,
		//------------------------------
		/* data chunk라는 것을 알림 */{ 'd','a','t','a' },
		/* 실제 데이타의 총 크기 */ sizeof(data) * 8 };
	/* 이하 Sample data : 여기서 부터 음성 데이터의 시작. */

	p_wfile = fopen(WAVE_FILE, "wb");

	//   header 정보 저장
	fwrite(&PCMWave, sizeof(struct WaveFormat), 1, p_wfile);

	//   온음표, 2분음표, 4분음표, 8분음표, 16분음표


	//   data 생성
	for (n = 0; n< (SAMPLING_RATE / div); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * E4 * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * D4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * C3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0]) / 4);
	}
	for (n = (SAMPLING_RATE / div); n< (SAMPLING_RATE * 2 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * E4 * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * D4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * G3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0]) / 4);
	}
	for (n = (SAMPLING_RATE * 2 / div); n< (SAMPLING_RATE * 3 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * G3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal4[0]) / 2);
	}
	for (n = (SAMPLING_RATE * 3 / div); n< (SAMPLING_RATE * 4 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * C4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * G3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal4[0]) / 2);
	}
	fwrite(data, sizeof(short int), SAMPLING_RATE / 2, p_wfile);
	//0.5

	for (n = 0; n< (SAMPLING_RATE / div); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * E4 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * A3s * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * F3 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * G2 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0]) / 4);
	}
	for (n = (SAMPLING_RATE / div); n< (SAMPLING_RATE * 2 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * F4 * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * F3 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * G2 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal3[0] + signal4[0]) / 3);
	}
	for (n = (SAMPLING_RATE * 2 / div); n< (SAMPLING_RATE * 3 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * D4 * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * B3 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * E3 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * C3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / 5);
	}
	for (n = (SAMPLING_RATE * 3 / div); n< (SAMPLING_RATE * 4 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * D4 * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * B3 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * E3 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * C3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / 5);
	}

	fwrite(data, sizeof(short int), SAMPLING_RATE / 2, p_wfile);
	//1.0

	for (n = 0; n< (SAMPLING_RATE * 2 / div); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * A4 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * E4 * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * C4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * F3 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * D3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / 5);
	}
	for (n = (SAMPLING_RATE * 2 / div); n< (SAMPLING_RATE); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * A4 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * D4s * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * B3 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * F3 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * G2 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / 5);
	}

	fwrite(data, sizeof(short int), SAMPLING_RATE / 2, p_wfile);
	//1.5///

	for (n = 0; n< (SAMPLING_RATE / div); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * E4 * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * D4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * E3 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * C3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / 5);
	}
	for (n = (SAMPLING_RATE / div); n< (SAMPLING_RATE * 2 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G3 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * E3 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * C3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal4[0] + signal5[0]) / 3);
	}
	for (n = (SAMPLING_RATE * 2 / div); n< (SAMPLING_RATE * 3 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * C4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * E3 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * C3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal4[0] + signal5[0]) / 3);
	}
	for (n = (SAMPLING_RATE * 3 / div); n< (SAMPLING_RATE * 4 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * B3 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * E3 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * C3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal4[0] + signal5[0]) / 3);
	}
	fwrite(data, sizeof(short int), SAMPLING_RATE / 2, p_wfile);
	//2.0///

	for (n = 0; n< (SAMPLING_RATE / div); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * E4 * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * C4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * G3 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * A2 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / 5);
	}
	for (n = (SAMPLING_RATE / div); n< (SAMPLING_RATE * 2 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * E4 * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * C4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * E3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0]) / 4);
	}
	for (n = (SAMPLING_RATE * 2 / div); n< (SAMPLING_RATE * 4 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * 523 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * A3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal4[0]) / 2);
	}

	fwrite(data, sizeof(short int), SAMPLING_RATE / 2, p_wfile);
	//2.5///

	for (n = 0; n< (SAMPLING_RATE / div); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * E5 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * A4 * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * F4s * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * C4 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * D3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / 5);
	}
	for (n = (SAMPLING_RATE / div); n< (SAMPLING_RATE * 2 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * E5 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * A4 * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * F4s * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * F3s * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0]) / 4);
	}
	for (n = (SAMPLING_RATE * 2 / div); n< (SAMPLING_RATE * 3 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * D5 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * C4 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0]) / 2);
	}
	for (n = (SAMPLING_RATE * 3 / div); n< (SAMPLING_RATE * 4 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * 523 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * C4 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0]) / 2);
	}
	fwrite(data, sizeof(short int), SAMPLING_RATE / 2, p_wfile);
	//3.0///

	for (n = 0; n< (SAMPLING_RATE / div); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * D5 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * G4s * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * F4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * G3s * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * A2s * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / 5);
	}
	for (n = (SAMPLING_RATE / div); n< (SAMPLING_RATE * 2 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * D5 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * G4s * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * F4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * F3 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0]) / 4);
	}
	for (n = (SAMPLING_RATE * 2 / div); n< (SAMPLING_RATE * 3 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * D5 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * G4s * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * F4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * G3s * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0]) / 4);
	}
	for (n = (SAMPLING_RATE * 3 / div); n< (SAMPLING_RATE * 4 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * C4 * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * G3s * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0]) / 2);
	}

	fwrite(data, sizeof(short int), SAMPLING_RATE / 2, p_wfile);
	//3.5///

	for (n = 0; n< (SAMPLING_RATE / div); n++)//솔
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * A4s * n / SAMPLING_RATE);
		signal2[0] = AMPLITUDE*cos(2 * PI * D4s * n / SAMPLING_RATE);
		signal3[0] = AMPLITUDE*cos(2 * PI * B3 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * F3 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * G2 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0] + signal4[0] + signal5[0]) / 5);
	}
	for (n = (SAMPLING_RATE / div); n< (SAMPLING_RATE * 2 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * A4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * F3 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * G2 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal4[0] + signal5[0]) / 3);
	}
	for (n = (SAMPLING_RATE * 2 / div); n< (SAMPLING_RATE * 3 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * F3 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * G2 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal4[0] + signal5[0]) / 3);
	}
	for (n = (SAMPLING_RATE * 3 / div); n< (SAMPLING_RATE * 4 / div); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * F4 * n / SAMPLING_RATE);
		signal4[0] = AMPLITUDE*cos(2 * PI * F3 * n / SAMPLING_RATE);
		signal5[0] = AMPLITUDE*cos(2 * PI * G2 * n / SAMPLING_RATE);
		data[n] = (short)((signal1[0] + signal4[0] + signal5[0]) / 3);
	}

	fwrite(data, sizeof(short int), SAMPLING_RATE / 2, p_wfile);
	//4.0


	fclose(p_wfile);
}