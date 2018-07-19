#ifndef MENU_H_
#define MENU_H_

#pragma DATA_SECTION(charset_6x8, ".gcharrom")
    
#include "stdio.h"
#include "ezdsp5535.h"
#include "ezdsp5535_sar.h"
#include "ezdsp5535_lcd.h"

#define MENU_SIZE 3
#define FX_LEVELS 3

static Int16 sw1State = 0;
static Int16 sw2State = 0;
static Int16 menuIndex = 0;
static Int16 fxLevel[MENU_SIZE] = {0, 0, 0};

static unsigned int charset_6x8[256*3];  

static char *title = "Timbre";
static char titleSize = 6;

static char *options[MENU_SIZE] = {
	"OVERDRIVE",
	"TREMOLO",
	"LOW-PASS"
};

static Int16 option_lengths[MENU_SIZE] = {9, 7, 8};
	

typedef enum opt {
	OPT_OVERDRIVE = 0,
	OPT_TREMOLO = 1,
	OPT_LOWPASS = 2
} Opt;


void initMenu();
void updateButtonState(Int16 pressed);
void sw1Event();
void sw2Event();
Int16 getFilterLevel(Opt o);
void updateOled();
void clearBottomCol();
void displayString(char *str, Int16 length);
void displayChar(char symbol);

#endif /*MENU_H_*/
