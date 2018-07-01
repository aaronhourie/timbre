
#include "stdio.h"
#include "ezdsp5535.h"
#include "ezdsp5535_i2s.h"
#include "csl_i2s.h"

extern void init_aic3204(void);
extern void close_aic3204(void);

void audioLoop(void);

void main()
{
	// Initialize chip.
    EZDSP5535_init( );
    // Initialize AIC3204 codec.
    init_aic3204();
    // Begin audio loop. 
    audioLoop();
}


void audioLoop() 
{
	Int16 sec, msec;
    Int16 sample, data1, data2;
	/* Play Loop for 5 seconds */
    for ( sec = 0 ; sec < 120 ; sec++ )
    {
        for ( msec = 0 ; msec < 1000 ; msec++ )
        {
            for ( sample = 0 ; sample < 48 ; sample++ )
            {
                /* Read 16-bit left channel Data */
                EZDSP5535_I2S_readLeft(&data1);
                
                /* Read 16-bit right channel Data */
                EZDSP5535_I2S_readRight(&data2);
                
                /* Write 16-bit left channel Data */
                EZDSP5535_I2S_writeLeft(data1);
                
                /* Write 16-bit right channel Data */
                EZDSP5535_I2S_writeRight(data2);
            }
        }
    }
    close_aic3204();
}