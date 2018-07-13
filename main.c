
#include "stdio.h"
#include "ezdsp5535.h"
#include "ezdsp5535_i2s.h"
#include "csl_i2s.h"

#include "fraction.h"


#define MAXINT16 32767
#define WINBUFF_SIZE 8

extern void init_aic3204(void);
extern void close_aic3204(void);

Fraction impulse;

void initBuffer(void);
void insertSample(Int16);

void audioLoop(void);

Int16 overDrive(Int16 data);

Int16 winBuff[WINBUFF_SIZE];
Int16 curPos = 0;
Int16 bufferFull = 0;
Int16 running = 0;

void main()
{
	impulse.n = 1;
	impulse.d = WINBUFF_SIZE;
	// Initialize chip.
    EZDSP5535_init( );
    // Initialize AIC3204 codec.
    init_aic3204();
    running = 1;
    // Begin audio loop. 
    audioLoop();
}

void insertData(Int16 data) {
	// If the buffer has still not been filled.
	if (!bufferFull) {
		// Add the sample to the buffer
		winBuff[curPos] = data;
		// Increment the cursor.
		curPos += 1;
		// If the cursor reaches the end
		if (curPos == WINBUFF_SIZE) {
			// Start cursor over, mark buffer as full.
			curPos = 0;
			bufferFull = 1;
		}
	}
	else {
		winBuff[curPos] = data;
		curPos = (curPos + 1) % WINBUFF_SIZE;
	}
}

void audioLoop() 
{
	Int16 msec;
    Int16 sample, data;
    
    while ( running ) {
        for ( msec = 0 ; msec < 1000 ; msec++ )
        {
            for ( sample = 0 ; sample < 48 ; sample++ )
            {
                /* Read 16-bit right channel Data */
                EZDSP5535_I2S_readRight(&data);
                
//                insertData(data);
//                for (i = 0; i < WINBUFF_SIZE; i++) {
//                	
//                	result += fMultInt(&impulse, winBuff[i]);
//                }
                
                data = overDrive(data);
                /* Write 16-bit right channel Data */
                EZDSP5535_I2S_writeRight(data);
                EZDSP5535_I2S_writeLeft(data);
                
            }
        }
    }
    close_aic3204();
}

Int16 overDrive(Int16 data) {
	if (data <= MAXINT16/3) {
		return data*2;
	}
	else if (data <= (MAXINT16/3) * 2) {
		return (3-(2-(3*data))*(2-3*data)) / 3;
	}
	else {
		return MAXINT16;
	}
}
