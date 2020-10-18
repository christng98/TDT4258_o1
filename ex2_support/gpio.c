#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "ex2.h"

 /*
    name: setup_GPIO
    purpose: sets up GPIO mode and interrupts by configure registers. 
    argument(s): none
    return value: none
  */
void setup_GPIO()
{
	//enable high frequency peripheral clock for the timer
	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO;

	//set lowest drive strength
	*GPIO_PA_CTRL = 1;

	//set pins A8-15 as output
	*GPIO_PA_MODEH = 0x55555555;

	//turn all LEDs off
	*GPIO_PA_DOUT = 0xffff;

	//set buttons as output
	*GPIO_PC_MODEL = 0x33333333;

	//enable internal pull up
	*GPIO_PC_DOUT = 0xff;
}

 
/*
	name: setLEDs_waveFormat
	purpose: Lighting LEDs to indicate which waveform is being used.
	argument(s):
		wave:
			range: 0, 1, 2, 3
			purpose: define which waveform is being used
	return value: none
*/

void setLEDs_waveFormat(int wave)
{
	// choosing which LEDs to light, and lighting them
	switch (wave) {
	case 3:
		*GPIO_PA_DOUT = (0x00ff);
		break;
	case 2:
		*GPIO_PA_DOUT = (0x03ff);
		break;
	case 1:
		*GPIO_PA_DOUT = (0x0fff);
		break;
	case 0:
		*GPIO_PA_DOUT = (0x3fff);
		break;
	case 4:
		*GPIO_PA_DOUT = (0x3fff);
		break;
	}
}

/*
	name: setLEDs_songs
	purpose: Lighting a LED to indicate which song is being played.
	argument(s):
			buttonX:
				range: BUTTON2, BUTTON3, BUTTON4, BUTTON5, BUTTON6, BUTTON7, BUTTON8
				purpose: Identify which song is being played so that the corresponding LED can be lit.
	return value: none
*/
void setLEDs_songs(int buttonX)
{
	// choosing which LED to light, and lighting it
	switch (buttonX) {
	case BUTTON2:
		*GPIO_PA_DOUT = LED2;
		break;
	case BUTTON3:
		*GPIO_PA_DOUT = LED3;
		break;
	case BUTTON4:
		*GPIO_PA_DOUT = LED4;
		break;
	case BUTTON5:
		*GPIO_PA_DOUT = LED5;
		break;
	case BUTTON6:
		*GPIO_PA_DOUT = LED6;
		break;
	case BUTTON7:
		*GPIO_PA_DOUT = LED7;
		break;
	case BUTTON8:
		*GPIO_PA_DOUT = LED8;
		break;
	}
}

/*
	name: turnOffLEDs
	purpose: Turn off all the LEDs.
	argument(s): none
	return value: none
*/
void turnOffLEDs()
{
	*GPIO_PA_DOUT = 0xffff;
}


 /*
    name: buttonPressed
    purpose: Run different procedures. Either it changes the wave used to play songs, or it plays a song.
    argument(s):
    	buttonX:
    		range: BUTTON1, BUTTON2, BUTTON3, BUTTON4, BUTTON5, BUTTON6, BUTTON7, BUTTON8
    		purpose: choose which kind of procedure will run, change wave or play a song
  	  wave:
		range: 0, 1, 2, 3
		purpose: determend which waveformat to play the song in
    

    return value: none
  */
/* TODO sjekk dette, for denne funksjonen er definert 2 ganger. (HADDE OPRINNELIG BRUKT SONGS.C FILEN ISTEDET FOR ACTIONS.C (DA VAR FREMDELES BUTTONPRESSED FUNKSJONEN HER), MEN ENDRA DET TILBAKE)
void buttonPressed(int buttonX, int *wave)
{
	//changing waveformat
	if (buttonX == BUTTON1) {
		updatewave(wave);
		setLEDs_waveFormat(*wave);
		Delay_C(10);
	}
	//playing a song
	else {
		//setLEDs_songs(buttonX);
		setLEDs_waveFormat(*wave);
		playSong(buttonX, *wave);
	}
}*/



/*
	name: Time
	purpose: Count the time specified by uS TODO: uS ???? Skjønner at det er en parameter, men hva står uS for? er det mulig med et bedre forklart navn eller forklaring til variablene?
	JEG TROR DET STÅR FOR TID I MIKRO SEKUNDER (10^-6 sekunder =\MU sekunder)
	argument(s):
			uS:
				range: 0 to 4294967296
				purpose: Specify the value to count up to
	
	return value: none
*/
void time_microSeconds(uint32_t uS)
{
	uint32_t i, s = 0;

	for (i = 0; i < uS; i++)
		s++;
}

/*
	name: Delay_C TODO: hvorfor delay_C og ikke bare delay? Konvensjonen er at funksjoner starter med små bokstaver
	purpose: Delay by mS times 10 milliseconds.
	argument(s):
			mS:
				range: 0 to 4294967296
				purpose: Specify the delay in milliseconds.
	return value: none
*/
void delay_C(uint32_t mS)
{
	uint32_t i;
	for (i = 0; i < mS; i++) {
		time_microSeconds(10000);
	};
}
