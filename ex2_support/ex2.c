#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "ex2.h"

 /*
name: main
purpose: program the microcontroller runs. Sets up nessesary settings, checks for buttonpresses
argument(s): none
return value: none
*/
int main(void)
{
	int *wave;
	*wave = 0;
	uint32_t button_in;
	
	//setup configurations	
	setup_GPIO();
	setup_DAC();
	setup_timer(SAMPLE_PERIOD);
	
	startUpSong(*wave);

	//operate on buttonpress
	while (1) {
		button_in = *GPIO_PC_DIN;
		buttonPressed(button_in, &wave);

	}
}
