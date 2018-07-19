
#include "stdio.h"
#include "ezdsp5535.h"
#include "ezdsp5535_i2s.h"
#include "csl_i2s.h"

#include "fraction.h"

#define SAMPLE_RATE_KHZ 48
#define MAXINT16 32767
#define WINBUFF_SIZE 6

extern void init_aic3204(void);
extern void close_aic3204(void);

Fraction impulse;

void initBuffer(void);
void insertSample(Int16);

void audioLoop(void);

Int16 overDrive(Int16);
Int16 tremolo(Int16, Int16, Int16) ;

Int16 winBuff[WINBUFF_SIZE];
Int16 curPos = 0;
Int16 bufferFull = 0;
Int16 running = 0;
Int16 tremoloFreq = 3;

/** generated using the sine_table.py script **/
Int16 tableSize = 64;
Int16 sineTable[64][2] = {
	{0, 1},
	{5, 51}, {8, 41}, {9, 31}, {31, 81},
	{33, 70}, {5, 9}, {59, 93}, {70, 99},
	{126, 163}, {74, 89}, {127, 144}, {85, 92},
	{111, 116}, {51, 52}, {179, 180}, {1, 1},
	{179, 180}, {51, 52}, {111, 116}, {85, 92},
	{127, 144}, {74, 89}, {126, 163}, {70, 99},
	{59, 93}, {5, 9}, {33, 70}, {31, 81},
	{9, 31}, {8, 41}, {5, 51}, {0, 1},
	{-5, 51}, {-8, 41}, {-9, 31}, {-31, 81},
	{-33, 70}, {-5, 9}, {-59, 93}, {-70, 99},
	{-126, 163}, {-74, 89}, {-127, 144}, {-85, 92},
	{-111, 116}, {-51, 52}, {-179, 180}, {-1, 1},
	{-179, 180}, {-51, 52}, {-111, 116}, {-85, 92},
	{-127, 144}, {-74, 89}, {-126, 163}, {-70, 99},
	{-59, 93}, {-5, 9}, {-33, 70}, {-31, 81},
	{-9, 31}, {-8, 41}, {-5, 51},
};

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

void insertData(Int16 data) 
{
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
	Int16 sec=0, msec=0;
    Int16 sample, data;
    
    while ( running ) {
    	for ( msec = 0; msec < 1000; msec++){
	        for ( sample = 0 ; sample < SAMPLE_RATE_KHZ ; sample++ )
	        {
	            /* Read 16-bit right channel Data */
	            EZDSP5535_I2S_readRight(&data);
	            
	//                insertData(data);
	//                for (i = 0; i < WINBUFF_SIZE; i++) {
	//                	
	//                	result += fMultInt(&impulse, winBuff[i]);
	//                }
	            
	            // data = overDrive(data);
	            
	            data = tremolo(data, sec, msec);
	            /* Write 16-bit right channel Data */
	            EZDSP5535_I2S_writeRight(data);
	            EZDSP5535_I2S_writeLeft(data);
	            
	        }
    	}
        sec++;
        if (sec*1000 < 0){
        	sec = 0;
        }
    }
    close_aic3204();
}

Int16 tremolo(Int16 data, Int16 sec, Int16 msec) 
{
	Int16 period = 1000/tremoloFreq;
	Int16 time = ((sec*1000) + msec) % period;
	Int16 phase = ((tableSize * time)/1000) * tremoloFreq;
	Int16 index = phase  % tableSize;
	Int16 n = sineTable[index][0];
	Int16 d = sineTable[index][1];
	Int16 retVal = ndMultInt(n, d, data);
	return retVal;
}

Int16 overDrive(Int16 data) 
{
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
