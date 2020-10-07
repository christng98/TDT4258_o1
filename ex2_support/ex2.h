#ifndef ex2
#define ex2

#define SAMPLE_PERIOD 318	//The period between sound samples, in clock cycles

/*dac*/
void setup_DAC();
void startDAC();
void stopDAC();
void startUpSong(int wave);
void updatewave(int *wave);
//void ChooseWave(int *frecVec, int lengthFrecVec, int lengthnote);
void makeSound(int freqency, int length, int wave);
void makeSong(int *frecquencyVector, int sizeVectors, int *lengthFrequencyVector, int wave);

void makeSound_square(int freqency, int length);
void makeSound_saberthoot(int freqency, int length);
void makeSound_triangle(int freqency, int length);
void makeSound_sinus(int freqency, int length);

/*
void makeSongT(int *frecVec, int lengthFrecVec, int lengthnote);
void makeSoundS(int freqency, int length);
void makeSongS(int *frecVec, int lengthFrecVec, int lengthnote);
void makeSoundSin(int freqency, int length);
void makeSongSin(int *frecVec, int lengthFrecVec, int lengthnote);
*/

 /*GPIO*/ 
void setup_GPIO();
void buttonPressed(int buttonX, int *wave);
void setLigths(int buttonX);
void turnOffLigths();
void playSong(int buttonX, int wave);

/*timer*/
void setup_timer(uint16_t period);

/*interrupt*/
void setup_NVIC();
void setup_interruptGPIO();
void setup_Sleep();
void setup_disableRam();

/*notes used in songs*/
#define Hl 123
#define Cl 131
#define Dl 147
#define E 165
#define F 175
#define G 196
#define A 220
#define H 267
#define C 262
#define D 294
#define Eh 330
#define Fh 349
#define Gh 392
#define Ah 440

//button push
#define BUTTON1 0xfe
#define BUTTON2 0xfd
#define BUTTON3 0xfb
#define BUTTON4 0xf7
#define BUTTON5 0xef
#define BUTTON6 0xdf
#define BUTTON7 0xbf
#define BUTTON8 0x7f

//led ligth
#define LED1 0xfeff
#define LED2 0xfdff
#define LED3 0xfbff
#define LED4 0xf7ff
#define LED5 0xefff
#define LED6 0xdfff
#define LED7 0xbfff
#define LED8 0x7fff

#endif
