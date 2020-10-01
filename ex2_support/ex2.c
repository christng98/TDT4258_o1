#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"

/*
 * The period between sound samples, in clock cycles 
 */
#define SAMPLE_PERIOD 317

/*
 * Declaration of peripheral setup functions 
 */
void setupTimer(uint32_t period);
void setupDAC();
void setupGPIO();
//void setupNVIC();
void MakeSound(int freq, int length);
void MakeSong(int *frecVec, int lengthFrecVec, int lengthnote);

/*
 * Your code will start executing here 
 */
int main(void)
{
	uint32_t button_in;
	//uint32_t button_out;

	setupGPIO();
	setupDAC();
	setupTimer(SAMPLE_PERIOD);

	/*
	 * Enable interrupt handling 
	 */
	//setupNVIC();
	
	 //*GPIO_PA_DOUT = 0x0700;
	 //int song[3]={220, 340, 440};
	 //int *songsamples;
	while (1){
		/*GPIO_PA_DOUT = 0x0700;
		button_in = *GPIO_PC_DIN;
		button_out = (button_in); //<< 8);
		*GPIO_PA_DOUT = button_out;
		*/
		
		button_in=*GPIO_PC_DIN;
		buttonPressed(button_in);
		
	}
}

void setupNVIC()
{

}


