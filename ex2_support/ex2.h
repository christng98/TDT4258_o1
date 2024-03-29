#ifndef ex2
#define ex2

//The period between sound samples, in clock cycles
#define SAMPLE_PERIOD 318

// ------------- DAC ------------- //
//preperation functions
void setup_DAC();
void startDAC();
void stopDAC();

//functions that generate sounds
void makeSound_square(int freqency, int length);
void makeSound_sawtooth(int freqency, int length);
void makeSound_triangle(int freqency, int length);
void makeSound_sinus(int freqency, int length);

// ------------- actions ------------- //
//functions that use the other modules to do some sort of action
void playSound(int freqency, int length, int wave);
void startUpSong();
void updateWaveFormat();
void makeSong(int *frecquencyVector, int sizeVectors,
	      int *lengthFrequencyVector, int wave);
void buttonPressed(int buttonX);
void playSong(int buttonX, int wave);

// ------------- GPIO ------------- //
//preperation function
void setup_GPIO();

//LEDs functions
void turnOffLEDs();
void setLEDs_waveFormat(int wave);

// ------------- TIMER ------------- //
//preperation function
void setup_timer(uint16_t period);

//delay functions
void delayMicroSeconds(uint32_t microSeconds);
void delayMilliSeconds(uint32_t milliSeconds);

// ------------- INTERRUPTS ------------- //
//preperation function
void setup_interruptGPIO();	//setup NVIC
void setup_interrupt();		//setup NVIC
void setup_NVIC();
void setup_sleep();

//notes
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
#define BUTTON0 0xff
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

//wave format
#define SQUARE 0
#define SAWTOOTH 1
#define TRIANGLE 2
#define SINUS 3

#endif
