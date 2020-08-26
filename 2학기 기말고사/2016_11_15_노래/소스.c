#include <stdio.h>
#include <math.h>

#define SAMPLING_RATE      44100
#define WAVE_TIME         1
#define FREQUENCY         262
#define WAVE_FILE         "C4.wav"         
#define AMPLITUDE         32000

#define PI 3.14159265
#define DWORD unsigned int
#define NUM_CHANNEL         1
#define BYTES_PER_SAMPLE   2
#define BYTE_RATE         SAMPLING_RATE*NUM_CHANNEL*BYTES_PER_SAMPLE

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
	float signal1[10];
	float signal2[10];
	float signal3[10];
	int n;
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
		/* ���� ����Ÿ�� �� ũ�� */ sizeof(data) * 60 };
	/* ���� Sample data : ���⼭ ���� ���� �������� ����. */

	p_wfile = fopen(WAVE_FILE, "wb");

	//   header ���� ����
	fwrite(&PCMWave, sizeof(struct WaveFormat), 1, p_wfile);

	//   ����ǥ, 2����ǥ, 4����ǥ, 8����ǥ, 16����ǥ


	//   data ����
	for (n = 0; n< (44100 / 4) - 100; n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * E4 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * C4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}
	for (n = (44100 / 4) - 100; n< 44100 * 2 / 4; n++)
	{
		data[n] = 0;
	}
	for (n = 44100 * 2 / 4; n< 44100 * 3 / 4; n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * E4 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * C4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}
	for (n = 44100 * 3 / 4; n < 44100 * 4 / 4; n++)
	{
		data[n] = 0;
	}
	fwrite(data, sizeof(short int), 44100, p_wfile);
	//1.0

	for (n = 0; n < (44100 / 4); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * E4 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * E4 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * C4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}
	for (n = (44100 / 4); n < 44100 * 2 / 4; n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * F4 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * F4 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * D4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}
	for (n = 44100 * 2 / 4; n < 44100 * 4 / 4; n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * D4 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * C4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}

	fwrite(data, sizeof(short int), 44100, p_wfile);
	//1.5

	for (n = 0; n< (44100 / 2) - 100; n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * A4 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * F4 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * C4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}
	for (n = (44100 / 2) - 100; n< 44100 * 1 / 2; n++)
	{
		data[n] = 0;
	}
	for (n = 44100 * 1 / 2; n< 44100 * 2 / 2; n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * A4 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * F4 * n / 44100);
		signal3[0] = 0;
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}
	fwrite(data, sizeof(short int), 44100, p_wfile);
	//2.0
	for (n = 0; n< (44100); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * E4 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * C4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}

	fwrite(data, sizeof(short int), 44100, p_wfile);
	//2.5

	for (n = 0; n< (44100 / 2); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * G4 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * E4 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * C4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}

	for (n = 44100 * 1 / 2; n< 44100 * 2 / 2; n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * C5 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * G4 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * C4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}
	fwrite(data, sizeof(short int), 44100, p_wfile);
	//3.0

	for (n = 0; n < (44100 / 4); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * E5 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * C5 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * A4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}
	for (n = (44100 / 4); n < 44100 * 2 / 4; n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * E5 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * C5 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * E4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}
	for (n = 44100 * 2 / 4; n < 44100 * 3 / 4; n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * D5 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * A4 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * G4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}
	for (n = 44100 * 3 / 4; n < 44100 * 4 / 4; n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * C5 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * G4 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * G4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}

	fwrite(data, sizeof(short int), 44100, p_wfile);
	//3.5

	for (n = 0; n< (44100); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * D5 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * A4 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * F4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}

	fwrite(data, sizeof(short int), 44100, p_wfile);
	//4.0
	for (n = 0; n< (44100); n++)
	{
		signal1[0] = AMPLITUDE*cos(2 * PI * D5 * n / 44100);
		signal2[0] = AMPLITUDE*cos(2 * PI * A4 * n / 44100);
		signal3[0] = AMPLITUDE*cos(2 * PI * F4 * n / 44100);
		data[n] = (short)((signal1[0] + signal2[0] + signal3[0]) / 3);
	}

	fwrite(data, sizeof(short int), 44100, p_wfile);
	//4.5

	fclose(p_wfile);
}
