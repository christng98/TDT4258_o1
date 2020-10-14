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
void
setup_GPIO ()
{
  //enable high frequency peripheral clock for the timer
  *CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO;	/* enable GPIO clock */

  //set lowest drive strength
  *GPIO_PA_CTRL = 1;		/* set lowest drive strength */

  //set pins A8-15 as output
  *GPIO_PA_MODEH = 0x55555555;	/* set pins A8-15 as output */

  //turn all LEDs off
  *GPIO_PA_DOUT = 0xff;	/* turn all LEDs off */

  //set buttons as output
  *GPIO_PC_MODEL = 0x33333333;	/*set buttons as output */

  //enable internal pull up
  *GPIO_PC_DOUT = 0xff;
}

 /*
    name: buttonPressed
    purpose: Run different prosedures. Either it changes the wave used to play songs, or it plays a song.
    argument(s):
    buttonX:
    range: BUTTON1, BUTTON2, BUTTON3, BUTTON4, BUTTON5, BUTTON6, BUTTON7, BUTTON8
    purpose: choose which kind of prosedure will run, change wave or play a song

    return value: none
  */
void
buttonPressed (int buttonX, int *wave)
{
  //changing waveformat
  if (buttonX == BUTTON1)
    {
      setLEDs_waveFormat (*wave);
      updatewave (wave);

      //playing a song
    }
  else
    {
      setLEDs_songs (buttonX);
      playSong (buttonX, *wave);
    }
}

void
setLEDs_waveFormat (int wave)
{
  switch (wave)
    {
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


void
setLEDs_songs (int buttonX)
{
  switch (buttonX)
    {
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

void
turnOffLEDs ()
{
  *GPIO_PA_DOUT = 0xffff;
}

/*
name: playSong
purpose: play a song. Which song is determined by the argument.
argument(s):
	buttonX:
		range: BUTTON1, BUTTON2, BUTTON3, BUTTON4, BUTTON5, BUTTON6, BUTTON7, BUTTON8
		purpose: choose song to play
return value: none
*/
void
playSong (int buttonX, int wave)
{

  int sizeVectors_fail = 3;
  int frequencies_fail[3] = { A, F, Hl };
  int lengths_fail[3] = { 70, 70, 100 };

  int sizeVectors_win = 9;
  int frequencies_win[9] = { Hl, Cl, Dl, E, F, G, H, A, D };
  int lengths_win[9] = { 130, 40, 40, 40, 40, 40, 130, 40, 120 };

  int sizeVectors_twinkleTwinkleLittleStar = 14;
  int frequencies_twinkleTwinkleLittleStar[] =
    { E, E, C, C, D, D, C, H, H, A, A, G, G, F };
  int lengths_twinkleTwinkleLittleStar[] =
    { 80, 80, 80, 80, 80, 80, 160, 80, 80, 80, 80, 80, 80, 160 };

  int sizeVectors_londonBridge = 24;
  int frequencies_londonBridge[24] =
    { C, D, C, H, A, H, C, G, A, H, A, H, C, C, D, C, H, A, H, C, G, C, A,
F };
  int lengths_londonBridge[24] =
    { 70, 70, 70, 70, 70, 70, 140, 70, 70, 140, 70, 70, 140, 70, 70, 70, 70,
70, 70, 140, 95, 95, 95 };


  int sizeVectors_zelda = 11;
  int frequencies_zelda[11] = { E, G, Dl, E, G, Dl, E, G, D, C, G };
  int lengths_zelda[11] = { 70, 70, 140, 70, 70, 140, 70, 70, 70, 70, 70 };

  int sizeVectors_mikkelRev = 24;
  int frequencies_mikkelRev[24] =
    { E, G, Cl, E, G, Cl, F, A, C, A, A, G, E, G, Cl, E, G, Cl, Dl, E, F, Hl,
Dl, Cl, };
  int lengths_mikkelRev[24] =
    { 70, 70, 140, 70, 70, 140, 70, 70, 70, 70, 140, 140, 70, 70, 140, 70, 70,
140, 70, 70, 70, 70, 140, 140 };

  int sizeVectors_fullStep = 22;
  int frequencies_fullStep[22] =
    { E, F, G, A, H, C, D, Eh, Fh, Gh, Ah, Ah, Gh, Fh, Eh, D, C, H, A, G, F,
E };
  int lengths_fullStep[22] =
    { 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
40, 40, 40, 40 };



  //Chooses which song to play
  switch (buttonX)
    {
    case BUTTON2:
      makeSong (frequencies_fail, sizeVectors_fail, lengths_fail, wave);
      break;
    case BUTTON3:
      makeSong (frequencies_win, sizeVectors_win, lengths_win, wave);
      break;
    case BUTTON4:
      makeSong (frequencies_twinkleTwinkleLittleStar,
		sizeVectors_twinkleTwinkleLittleStar,
		lengths_twinkleTwinkleLittleStar, wave);
      break;
    case BUTTON5:
      makeSong (frequencies_londonBridge, sizeVectors_londonBridge,
		lengths_londonBridge, wave);
      break;
    case BUTTON6:
      makeSong (frequencies_zelda, sizeVectors_zelda, lengths_zelda, wave);
      break;
    case BUTTON7:
      makeSong (frequencies_mikkelRev, sizeVectors_mikkelRev,
		lengths_mikkelRev, wave);
      break;
    case BUTTON8:
      makeSong (frequencies_fullStep, sizeVectors_fullStep, lengths_fullStep,
		wave);
      break;
    }
}
