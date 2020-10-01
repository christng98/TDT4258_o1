#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"


void buttonPressed(int buttonX);
void setupDAC();
/*
 * TIMER1 interrupt handler 
 */
void __attribute__ ((interrupt)) TIMER1_IRQHandler()
{
	/*
	 * TODO feed new samples to the DAC remember to clear the pending
	 * interrupt by writing 1 to TIMER1_IFC 
	 */
	 *TIMER1_IFC = 1;
}

/*
 * GPIO even pin interrupt handler 
 */
void __attribute__ ((interrupt)) GPIO_EVEN_IRQHandler()
{
	/*
	 * TODO handle button pressed event, remember to clear pending
	 * interrupt 
	 */
	 *GPIO_IFC = *GPIO_IF;   //clears interrupt
	 setupDAC();
	 buttonPressed(*GPIO_PC_DIN);
}

/*
 * GPIO odd pin interrupt handler 
 */
void __attribute__ ((interrupt)) GPIO_ODD_IRQHandler()
{
	/*
	 * TODO handle button pressed event, remember to clear pending
	 * interrupt 
	 */
	 *GPIO_IFC = *GPIO_IF;   //clears interrupt
	 setupDAC();
	 buttonPressed(*GPIO_PC_DIN);
	 
}