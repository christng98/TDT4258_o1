/*

#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "ex2.h"


// ------------- ACTIONS ------------- //
//functions that use the other modules to do some sort of action
void startUpSong(int wave);
void updatewave(int *wave);
void makeSong(int *frecquencyVector, int sizeVectors, int *lengthFrequencyVector, int wave);
void playSong(buttonX, wave);
void buttonPressed(int buttonX, int *wave);

/*
name: startUpSong
purpose: plays a song when the microcontrollers is turned on 
argument(s): none
return value: none
*/
/*
void startUpSong(int wave)
{
	
	int sizeVectors = 3;
	int frequencies[3] = { Hl, Dl, F };
	int lengthPerfrequency[3] = { 60, 60, 60};
	
	makeSong(&frequencies, sizeVectors, &lengthPerfrequency, wave);

}
*/
/*
name: updatewave
purpose: changes the value of wave so the microcontroller uses another waveformat when playing songs. It also shows which wave that it uses by ligth up leds accordingly
argument(s): none
return value: none
*/
/*
void updatewave(int *wave)
{
	//*GPIO_PA_DOUT = 0xffff;
	*wave += 1;
	if(*wave == 4){
		*wave = 0;
	}
}
*/
/*
name: makeSong
purpose: makes a song of the frequencies and lengths given
argument(s):
	freqencyVector:
		range: contains 0 to infty frequencies
		purpose: hold the frequencies that will be played in spesified order
	sizeVectors:
		range: the size of the frequencyVector and lengthVector
		purpose: contains the size of the vectors so we will play all the frequencies, nothing more, nothing less.
	lengthVector:
		range: contains 0 to infty lengths
		purpose: hold the length of the frequencies that will be played in same order as the frequencies that are supposed to be played in that length.
	wave: 
		range: 0, 1, 2, 3
		purpose: determend which waveformat the sound will be played in
return value: none
*/
/*
void makeSong(int *frecquencyVector, int sizeVectors, int *lengthFrequencyVector, int wave)
{
	//play the song
	for (int i = 0; i < sizeVectors; i++) {
		makeSound(frecquencyVector[i], lengthFrequencyVector[i], wave);
	}
	//make sound to symbolixe the end of the song
	makeSound(frecquencyVector[sizeVectors - 1], lengthFrequencyVector[sizeVectors-1] * 2, wave);
}

*/
/*
name: playSong
purpose: play a song. Which song is determined by the argument.
argument(s):
	buttonX:
		range: BUTTON1, BUTTON2, BUTTON3, BUTTON4, BUTTON5, BUTTON6, BUTTON7, BUTTON8
		purpose: choose song to play
return value: none
*/
/*
void playSong(int buttonX, int wave){
	
	int sizeVectors_fail = 3;
	int frequencies_fail[3] = {A, F, Hl};
	int lengths_fail[3] = {70, 70, 100};

	int sizeVectors_win = 9;
	int frequencies_win[9] = {Hl, Cl, Dl, E, F, G, H, A, D};
	int lengths_win[9] = {130, 40, 40, 40, 40, 40, 130, 40, 120};

	int sizeVectors_twinkleTwinkleLittleStar = 14;
	int frequencies_twinkleTwinkleLittleStar[] = { E, E, C, C, D, D, C, H, H, A, A, G, G, F };
	int lengths_twinkleTwinkleLittleStar[] = { 80, 80, 80, 80, 80, 80, 160, 80, 80, 80, 80, 80, 80, 160 };

	int sizeVectors_londonBridge = 24;
	int frequencies_londonBridge[24] = { C, D, C, H, A, H, C, G, A, H, A, H, C, C, D, C, H, A, H, C, G, C, A, F };
	int lengths_londonBridge [24] = { 70, 70, 70, 70, 70, 70, 140, 70, 70, 140, 70, 70, 140, 70, 70, 70, 70, 70, 70, 140, 95, 95, 95};


	int sizeVectors_zelda = 11;
	int frequencies_zelda[11] = { E, G, Dl, E, G, Dl, E, G, D, C, G };
	int lengths_zelda[11] = { 70, 70, 140, 70, 70, 140, 70, 70, 70, 70, 70 };
	
	int sizeVectors_mikkelRev = 24;
	int frequencies_mikkelRev[24] = { E, G, Cl, E, G, Cl, F, A, C, A, A, G, E, G, Cl, E, G, Cl, Dl, E, F, Hl, Dl, Cl, };
	int lengths_mikkelRev[24] = { 70, 70, 140, 70, 70, 140, 70, 70, 70, 70, 140, 140, 70, 70, 140, 70, 70, 140, 70, 70, 70, 70, 140, 140 };

	int sizeVectors_mikkelRev = 24;
	int frequencies_mikkelRev[24] = { E, G, Cl, E, G, Cl, F, A, C, A, A, G, E, G, Cl, E, G, Cl, Dl, E, F, Hl, Dl, Cl, };
	int lengths_mikkelRev[24] = { 70, 70, 140, 70, 70, 140, 70, 70, 70, 70, 140, 140, 70, 70, 140, 70, 70, 140, 70, 70, 70, 70, 140, 140 };
	
	int sizeVectors_fullStep = 22;
	int frequencies_fullStep[22] = { E, F, G, A, H, C, D, Eh, Fh, Gh, Ah, Ah, Gh, Fh, Eh, D, C, H, A, G, F, E };
	int lengths_fullStep[22] = { 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40 };
	

	
	//Chooses which song to play
	switch(buttonX){
		case BUTTON2:
			makeSong(frequencies_fail, sizeVectors_fail, lengths_fail, wave);
			break;
		case BUTTON3:
			makeSong(frequencies_win, sizeVectors_win, lengths_win, wave);
			break;
		case BUTTON4:
			makeSong(frequencies_twinkleTwinkleLittleStar, sizeVectors_twinkleTwinkleLittleStar, lengths_twinkleTwinkleLittleStar, wave);
			break;
		case BUTTON5:
			makeSong(frequencies_londonBridge, sizeVectors_londonBridge, lengths_londonBridge, wave);
			break;
		case BUTTON6:
			makeSong(frequencies_zelda, sizeVectors_zelda , lengths_zelda, wave);
			break;
		case BUTTON7:
			makeSong(frequencies_mikkelRev, sizeVectors_mikkelRev, lengths_mikkelRev, wave);
			break;
		case BUTTON8:
			makeSong(frequencies_fullStep, sizeVectors_fullStep, lengths_fullStep, wave);
			break;
	}
}
*/
 /*
    name: buttonPressed
    purpose: Run different prosedures. Either it changes the wave used to play songs, or it plays a song.
    argument(s):
    buttonX:
    range: BUTTON1, BUTTON2, BUTTON3, BUTTON4, BUTTON5, BUTTON6, BUTTON7, BUTTON8
    purpose: choose which kind of prosedure will run, change wave or play a song

    return value: none
  */
/*
void buttonPressed(int buttonX, int *wave)
{
	//changing waveformat
	if(buttonX == BUTTON1){
		setLEDs_waveFormat(*wave);
		updatewave(wave);
		
	//playing a song
	}else{		
		setLEDs_songs(buttonX);
		playSong(buttonX, *wave);
	}
}

*/