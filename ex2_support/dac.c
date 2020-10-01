#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "efm32gg.h"

void setupDAC()
{
	 
	 *CMU_HFPERCLKEN0 |= (1<<17);
	 *DAC0_CTRL = 0x50010;
	 *DAC0_CH0CTRL = 1;
	 *DAC0_CH1CTRL = 1;
}

void MakeSound(int freq, int length)
{ 
	int count = 1;    //tell antall tiks
	int dacvolt = 0;  //defines strength of sound
	length=length*1000; //tonens lengde=spesifisert lengde * 1ms
	while(count < length){
		int countperiod = 44100/freq;
		if (count % (countperiod/2) == 0){   
			if(dacvolt == 100){
				dacvolt = 0;
			} else{
				dacvolt = 100;
			}
			*DAC0_CH0DATA = dacvolt;  //skriver voltverdien til utgangen
			*DAC0_CH1DATA = dacvolt;
		}
		
		count++;
	}
}

void MakeSong(int *frecVec, int lengthFrecVec, int lengthnote){
	for (int i = 0; i<lengthFrecVec; i++){
		MakeSound(frecVec[i],lengthnote);
	}
}

/*void wait(time){
	counter=0;
	while(counter < time){
		counter++
	}
}*/

