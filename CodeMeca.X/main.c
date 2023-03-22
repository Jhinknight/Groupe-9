/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif


#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
//#include <REG2051.H> //driver
#define stepper P1

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/


void delay() //timer
{
	unsigned char i,j,k;
	for(i=0;i<6;i++) {
		for(j=0;j<255;j++)
			for(k=0;k<255;k++);
	}
}

/* i.e. uint16_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/


//Moteur pas à pas connecté aux port 1.0 et 1.3
int16_t main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();

    while(1)
    {
		stepper = 0x0C;
		delay();
		stepper = 0x06;
		delay();
		stepper = 0x03;
		delay();
		stepper = 0x09;
		delay();
    }
}
