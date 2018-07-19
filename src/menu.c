#include "menu.h"

void initMenu() 
{
	int i = 0;
	EZDSP5535_SAR_init();
	// Startup adapted from Spectrum Digital library, oled_test.c
    EZDSP5535_OSD9616_init();
	
	// Deactivate Scrolling
    EZDSP5535_OSD9616_send(0x00,0x2e);  
    
    /* Fill page 1*/ 
    EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
    EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
    EZDSP5535_OSD9616_send(0x00,0xb0+1); // Set page for page 0 to page 5
    for(i=0;i<128;i++)
    {
    	EZDSP5535_OSD9616_send(0x40,0x00);
    }
    
    displayString(title, titleSize); 
    clearBottomCol();
    updateOled();
}

void updateButtonState(Int16 pressed) 
{
	if (pressed == SW1) {
		if (!sw1State) {
			sw1State = 1;
			sw1Event();
		}
	}
	else {
		sw1State = 0;
	}
	
	if (pressed == SW2) {
		if (!sw2State) {
			sw2State = 1;
			sw2Event();
		}
	}
	else {
		sw2State = 0;
	}
}

void sw1Event()
{
	menuIndex = (menuIndex + 1) % MENU_SIZE;
	updateOled();
}

void sw2Event()
{
	fxLevel[menuIndex] = (fxLevel[menuIndex] + 1) % FX_LEVELS;
	updateOled();
}


Int16 getFilterLevel(Opt o) 
{
	return fxLevel[(Int16)o];
}

void updateOled()
{
    clearBottomCol();
	displayString(options[menuIndex], option_lengths[menuIndex]);
	displayChar(' ');
	displayChar('0' + (char)fxLevel[menuIndex]);
}

void displayString(char *str, Int16 length) 
{
	int i;
	for (i = 0; i < length; i++) {
    	displayChar(str[i]);
	}
}

void clearBottomCol()
{
	int i = 0;
    EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
    EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
    EZDSP5535_OSD9616_send(0x00,0xb0); // Set page for page 0 to page 5
    for(i=0;i<128;i++)
    {
    	EZDSP5535_OSD9616_send(0x40,0x00);
    }
}

// Adapted from code example retrieved from: 
// https://e2e.ti.com/support/dsp/c5000/f/109/t/232343
void displayChar(char symbol) 
{
	
	unsigned int *chargen = &charset_6x8[(symbol&0xff)*3]; 
    unsigned int data[2];
    unsigned int i;
    
    for (i=0; i<3; i++) {                                                                    
        data[0] = chargen[i]>>8;
        data[1] = chargen[i]&0xff; 
        EZDSP5535_OSD9616_send(0x40,data[0]);
		EZDSP5535_OSD9616_send(0x40,data[1]);
    }      
}
