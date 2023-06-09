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

#include <stdint.h>          /* For uint16_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"            /* variables/params used by user.c               */

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* Declaration des entrees et sorties*/
    /* TODO Initialize User Ports/Peripherals/Project here */
    /* Setup analog functionality and port direction */
    /* Initialize peripherals */

    TRISBbits.TRISB0 = 0; // Broche B0 en sortie
    TRISBbits.TRISB1 = 0; // Broche B1
    TRISBbits.TRISB2 = 0; // Broche B2
    TRISBbits.TRISB3 = 0; // Broche B3
    
    PORTBbits.RB0 = 0; // B0 LOW
    PORTBbits.RB1 = 0;
    PORTBbits.RB2 = 0;
    PORTBbits.RB3 = 0;
}
