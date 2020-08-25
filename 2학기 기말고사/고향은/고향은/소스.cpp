
#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define DWORD unsigned int

#define sample 44100

struct WaveFormat {
	char RiftTag[4];      //"RIFF"
	DWORD FileLength;      //File Size
	char PFormatTag[4];      //"WAVE"
							 //=============================== 부모 chunk.
	char SFormatTag[4];      //"fmt"
	DWORD FormatLength;      //16
	short DataFormat;      //1
	short NumChannels;      //1
	DWORD nSamplesPerSec;   //100
	DWORD nAvgBytesperSec;   //nSamplesPerSec * BlockAlign
	short BlockAlign;      //nChannel * bit / 8
	short wBitPerSample;   //샘플당 비트수
						   //================================== 자식 chunk.
	char DataTag[4];      // "data"
	DWORD DataLength;      //Data Size
						   //================================== 데이타 chunk.
} PCMFormat;

void make_wave();

void main()
{
	make_wave();
}




void make_wave() {
	FILE *fp, *fpOut;
	short data[352800];		//44100*8
	float signal[4];
	int n, k;

	struct WaveFormat PCMWave =
	{
		{ 'R','I','F','F' }, sizeof(struct WaveFormat) + sizeof(data) - 8,
		{ 'W','A','V','E' },
		{ 'f','m','t','\x20' },16,1,1,44100,88200,2,16,
		{ 'd','a','t','a' },sizeof(data)
	};



	fp = fopen("signal.wav", "wb");

	for (n = 0; n < sample / 4; n++) { //솔
		signal[0] = 5000 * cos(2 * PI * 65.4 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 329.6 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 392.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample / 4; n < sample / 2; n++) {
		signal[0] = 5000 * cos(2 * PI * 98.0 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 392.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1]);
	}
	for (n = sample /   2; n < sample / 4 * 3; n++) {//솔
		signal[0] = 5000 * cos(2 * PI * 82.4 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 329.6 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 392.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample / 4 * 3; n < sample; n++) {
		signal[0] = 5000 * cos(2 * PI * 98.0 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 392.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1]);
	}
	for (n = sample; n < sample * 5 / 4; n++) {//미
		signal[0] = 5000 * cos(2 * PI * 65.4 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 196.0 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 329.6 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 5 / 4; n < sample * 6 / 4; n++) {//파
		signal[0] = 5000 * cos(2 * PI * 98.0 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 196.0 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 349.2 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 6 / 4; n < sample * 7 / 4; n++) {//솔
		signal[0] = 5000 * cos(2 * PI * 82.4 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 329.6 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 392.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 7 / 4; n < sample * 8 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 98.0 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 392.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1]);
	}

	for (n = sample * 8 / 4; n < sample * 9 / 4; n++) { //라
		signal[0] = 5000 * cos(2 * PI * 65.4 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 349.6 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 440.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}

	for (n = sample * 9 / 4; n < sample * 10 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 110.0 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 349.6 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 440.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}

	for (n = sample * 10 / 4; n < sample * 11 / 4; n++) { //라
		signal[0] = 5000 * cos(2 * PI * 87.3 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 349.2 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 440.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 11 / 4; n < sample * 12 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 110.0 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 349.2 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 440.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 12 / 4; n < sample * 13 / 4; n++) { //솔
		signal[0] = 5000 * cos(2 * PI * 65.4 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 329.6 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 392.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 13 / 4; n < sample * 14 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 98.0 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 329.6 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 392.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 14 / 4; n < sample * 15 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 82.4 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 329.6 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 392.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 15 / 4; n < sample * 16 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 98.0 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 329.6 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 392.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}

	for (n = sample * 16 / 4; n < sample * 17 / 4; n++) { //솔
		signal[0] = 5000 * cos(2 * PI * 65.4 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 329.6 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 391.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}

	for (n = sample * 17 / 4; n < sample * 18 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 97.9 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 261.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 329.6 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 391.0 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}

	for (n = sample * 18 / 4; n < sample * 19 / 4; n++) { //도
		signal[0] = 5000 * cos(2 * PI * 82.4 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 329.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 391.0 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 523.2 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 19 / 4; n < sample * 20 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 97.9 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 329.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 391.9 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 523.2 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 20 / 4; n < sample * 21 / 4; n++) { //미
		signal[0] = 5000 * cos(2 * PI * 65.4 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 391.9 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 523.3 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 659.2 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 21 / 4; n < sample * 22 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 97.9 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 391.9 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 523.3 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 659.2 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 22 / 4; n < sample * 23 / 4; n++) {//레
		signal[0] = 5000 * cos(2 * PI * 82.4 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 391.9 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 523.3 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 587.3 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 23 / 4; n < sample * 24 / 4; n++) {//도
		signal[0] = 5000 * cos(2 * PI * 98.0 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 329.6 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 391.0 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 523.2 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}

	for (n = sample * 24 / 4; n < sample * 25 / 4; n++) { //레
		signal[0] = 5000 * cos(2 * PI * 97.9 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 391.9 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 493.8 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 587.3 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}

	for (n = sample * 25 / 4; n < sample * 26 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 146.8 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 391.9 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 493.8 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 587.3 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}

	for (n = sample * 26 / 4; n < sample * 27 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 123.4 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 391.9 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 493.8 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 587.3 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 27 / 4; n < sample * 28 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 146.8 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 391.9 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 493.8 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 587.3 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 28 / 4; n < sample * 29 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 97.9 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 391.9 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 493.8 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 587.3 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 29 / 4; n < sample * 30 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 146.8 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 391.9 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 493.8 * n / sample);
		signal[3] = 5000 * cos(2 * PI * 587.3 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2] + signal[3]);
	}
	for (n = sample * 30 / 4; n < sample * 31 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 123.4 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 391.9 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 493.8 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2]);
	}
	for (n = sample * 31 / 4; n < sample * 32 / 4; n++) {
		signal[0] = 5000 * cos(2 * PI * 146.8 * n / sample);
		signal[1] = 5000 * cos(2 * PI * 391.9 * n / sample);
		signal[2] = 5000 * cos(2 * PI * 493.8 * n / sample);
		data[n] = (short)(signal[0] + signal[1] + signal[2]);
	}





	fwrite(&PCMWave, sizeof(struct WaveFormat), 1, fp);
	fwrite(data, sizeof(data), 1, fp);
	fclose(fp);

}


//261.63 = 도 329.63 = 미 392 = 솔