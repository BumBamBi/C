#include <stdio.h>
#include <math.h>

#define SAMPLING_RATE		10000		//���ø� ����Ʈ 10000
#define WAVE_TIME			1			//�Ҹ� ���� 1��
#define FREQUENCY			262
#define WAVE_FILE			"C4.wav"	//���� �̸�		
#define AMPLITUDE			30000		//������ �ִ�� ��

#define PI 3.14159265
#define DWORD unsigned int
#define NUM_CHANNEL			1
#define BYTES_PER_SAMPLE	2
#define BYTE_RATE			SAMPLING_RATE*NUM_CHANNEL*BYTES_PER_SAMPLE

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
	short int data[SAMPLING_RATE];	//�� ����
	float signal1;					//�� signal
	float signal2;
	float signal3;
	float signal4;

	float signal5;
	float signal6;
	float signal7;
	float signal8;

	int n;
	int div;
	struct WaveFormat PCMWave = {
		/* Riff ȭ���� �ĺ��� */{ 'R','I','F','F' },
		/* Riffȭ������������ѱ��� */ sizeof(struct WaveFormat) + sizeof(data) - 8,
		/* Form Type�� ���Ѵ�. */{ 'W','A','V','E' },
		//-----------------------------	
		/* Format Chunk ���ڿ� */{ 'f','m','t','\x20' },
		/* Length of the fmt data */ 16,
		/* Format Tag:1 = PCM */ 1,
		/* Channel:1=mono, 2=streo */ 1,
		/* Samples per Second:44100 */ SAMPLING_RATE,
		/* Sample rate * Block Align */ BYTE_RATE,
		/* Channel * Bit / sample/8 */  NUM_CHANNEL*BYTES_PER_SAMPLE, // Block Align
		/* Bit/sample: 8 or 16 */ 8 * BYTES_PER_SAMPLE,
		//------------------------------
		/* data chunk��� ���� �˸� */{ 'd','a','t','a' },
		/* ���� ����Ÿ�� �� ũ�� */ sizeof(data) * 60 };		//�Ҹ��� ���̸� �÷��ֱ� ���� ũ�� �÷���
	/* ���� Sample data : ���⼭ ���� ���� �������� ����. */

	p_wfile = fopen(WAVE_FILE, "wb");			//������ ����

	//	header ���� ����
	fwrite(&PCMWave, sizeof(struct WaveFormat), 1, p_wfile);

	//	����ǥ, 2����ǥ, 4����ǥ, 8����ǥ, 16����ǥ
	//div = 1;
	//div = 2;
	//div = 4;
	//div = 8;
	//div = 16;

	//	data ����
	for (n = 0; n< SAMPLING_RATE / 8; n++)			
	{
		signal1 = AMPLITUDE*cos(2 * PI * 392 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 493 * n / SAMPLING_RATE);
		signal3 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 130 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal3 + signal5) / 4);
	}

	for (n = SAMPLING_RATE / 8; n< SAMPLING_RATE / 4; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 392 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 493 * n / SAMPLING_RATE);
		signal3 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 195 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal3 + signal5) / 4);
	}

	for (n = SAMPLING_RATE / 4; n< 3 * SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 261 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5) / 2);
	}

	for (n = 3 * SAMPLING_RATE / 8; n< SAMPLING_RATE / 2; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 130 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5) / 2);
	}

	for (n = SAMPLING_RATE / 2; n< 5 * SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 440 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 587 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 123 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 220 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal5 + signal6) / 4);
	}

	for (n = 5 * SAMPLING_RATE / 8; n< 3 * SAMPLING_RATE / 4; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 293 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 123 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 220 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5 + signal6) / 3);
	}

	for (n = 3 * SAMPLING_RATE / 4; n< 7 * SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 349 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 587 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 164 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 207 * n / SAMPLING_RATE);
		signal7 = AMPLITUDE*cos(2 * PI * 293 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal5 + signal6 + signal7) / 5);
	}

	for (n = 7 * SAMPLING_RATE / 8; n< SAMPLING_RATE; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 391 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 164 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 207 * n / SAMPLING_RATE);
		signal7 = AMPLITUDE*cos(2 * PI * 293 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5 + signal6 + signal7) / 4);
	}

	//	data ����
	fwrite(data, sizeof(short int), SAMPLING_RATE, p_wfile);			//data ������ ����




	// 1���� ��



	//	data ����
	for (n = 0; n< SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 392 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 493 * n / SAMPLING_RATE);
		signal3 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 130 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal3 + signal5) / 4);
	}

	for (n = SAMPLING_RATE / 8; n< SAMPLING_RATE / 4; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 392 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 493 * n / SAMPLING_RATE);
		signal3 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 195 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal3 + signal5) / 4);
	}

	for (n = SAMPLING_RATE / 4; n< 3 * SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 261 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5) / 2);
	}

	for (n = 3 * SAMPLING_RATE / 8; n< SAMPLING_RATE / 2; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 130 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5) / 2);
	}

	for (n = SAMPLING_RATE / 2; n< 5 * SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 440 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 587 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 123 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 220 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal5 + signal6) / 4);
	}

	for (n = 5 * SAMPLING_RATE / 8; n< 3 * SAMPLING_RATE / 4; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 293 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 123 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 220 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5 + signal6) / 3);
	}

	for (n = 3 * SAMPLING_RATE / 4; n< 7 * SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 349 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 587 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 164 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 207 * n / SAMPLING_RATE);
		signal7 = AMPLITUDE*cos(2 * PI * 293 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal5 + signal6 + signal7) / 5);
	}

	for (n = 7 * SAMPLING_RATE / 8; n< SAMPLING_RATE; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 391 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 164 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 207 * n / SAMPLING_RATE);
		signal7 = AMPLITUDE*cos(2 * PI * 293 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5 + signal6 + signal7) / 4);
	}

	//	data ����
	fwrite(data, sizeof(short int), SAMPLING_RATE, p_wfile);			//data ������ ����

																		//	data ����
	for (n = 0; n< SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 392 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 493 * n / SAMPLING_RATE);
		signal3 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 130 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal3 + signal5) / 4);
	}

	for (n = SAMPLING_RATE / 8; n< SAMPLING_RATE / 4; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 392 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 493 * n / SAMPLING_RATE);
		signal3 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 195 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal3 + signal5) / 4);
	}

	for (n = SAMPLING_RATE / 4; n< 3 * SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 261 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5) / 2);
	}

	for (n = 3 * SAMPLING_RATE / 8; n< SAMPLING_RATE / 2; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 130 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5) / 2);
	}

	for (n = SAMPLING_RATE / 2; n< 5 * SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 440 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 587 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 123 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 220 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal5 + signal6) / 4);
	}

	for (n = 5 * SAMPLING_RATE / 8; n< 3 * SAMPLING_RATE / 4; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 293 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 123 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 220 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5 + signal6) / 3);
	}

	for (n = 3 * SAMPLING_RATE / 4; n< 7 * SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 349 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 587 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 164 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 207 * n / SAMPLING_RATE);
		signal7 = AMPLITUDE*cos(2 * PI * 293 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal5 + signal6 + signal7) / 5);
	}

	for (n = 7 * SAMPLING_RATE / 8; n< SAMPLING_RATE; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 391 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 164 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 207 * n / SAMPLING_RATE);
		signal7 = AMPLITUDE*cos(2 * PI * 293 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5 + signal6 + signal7) / 4);
	}

	//	data ����
	fwrite(data, sizeof(short int), SAMPLING_RATE, p_wfile);			//data ������ ����

																		//	data ����
	for (n = 0; n< SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 392 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 493 * n / SAMPLING_RATE);
		signal3 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 130 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal3 + signal5) / 4);
	}

	for (n = SAMPLING_RATE / 8; n< SAMPLING_RATE / 4; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 392 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 493 * n / SAMPLING_RATE);
		signal3 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 195 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal3 + signal5) / 4);
	}

	for (n = SAMPLING_RATE / 4; n< 3 * SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 261 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5) / 2);
	}

	for (n = 3 * SAMPLING_RATE / 8; n< SAMPLING_RATE / 2; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 659 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 130 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5) / 2);
	}

	for (n = SAMPLING_RATE / 2; n< 5 * SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 440 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 587 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 123 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 220 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal5 + signal6) / 4);
	}

	for (n = 5 * SAMPLING_RATE / 8; n< 3 * SAMPLING_RATE / 4; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 293 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 123 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 220 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5 + signal6) / 3);
	}

	for (n = 3 * SAMPLING_RATE / 4; n< 7 * SAMPLING_RATE / 8; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 349 * n / SAMPLING_RATE);
		signal2 = AMPLITUDE*cos(2 * PI * 587 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 164 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 207 * n / SAMPLING_RATE);
		signal7 = AMPLITUDE*cos(2 * PI * 293 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal2 + signal5 + signal6 + signal7) / 5);
	}

	for (n = 7 * SAMPLING_RATE / 8; n< SAMPLING_RATE; n++)
	{
		signal1 = AMPLITUDE*cos(2 * PI * 391 * n / SAMPLING_RATE);

		signal5 = AMPLITUDE*cos(2 * PI * 164 * n / SAMPLING_RATE);
		signal6 = AMPLITUDE*cos(2 * PI * 207 * n / SAMPLING_RATE);
		signal7 = AMPLITUDE*cos(2 * PI * 293 * n / SAMPLING_RATE);

		data[n] = (short)((signal1 + signal5 + signal6 + signal7) / 4);
	}

	//	data ����
	fwrite(data, sizeof(short int), SAMPLING_RATE, p_wfile);			//data ������ ����





	fclose(p_wfile);
}
