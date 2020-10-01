#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"

/*
 * function to set up GPIO mode and interrupts
 */
void setupGPIO()
{

	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO;	/* enable GPIO clock */
	*GPIO_PA_CTRL = 2;	/* set high drive strength */
	*GPIO_PA_MODEH = 0x55555555;	/* set pins A8-15 as output */
	*GPIO_PA_DOUT = 0xffff;	     /* turn all LEDs off*/
	
	*GPIO_PC_MODEL = 0x33333333; /*set buttons as output*/
	*GPIO_PC_DOUT = 0xff; /*enable internal pull up*/
}

void buttonPressed(int buttonX)
{
	if (buttonX==0xfe) {
		MakeSound(10000/220, 2000);
	} else if (buttonX==0xfd) {
		MakeSound(10000/340, 5000);
	}
}
