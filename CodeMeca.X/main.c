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
#include <stdio.h>
#include <stdlib.h>
#include <libpic30.h>

/* Global Variable Declaration                                                */
/* i.e. uint16_t <variable_name>; */
/* Main Program                                                               */
int16_t main(void)
{
    ConfigureOscillator(); //timer (system.c)
    InitApp(); // I/O (user.c)

    //Create Bit-Shifting variable
    unsigned char i=0;

    TRISB = 0x00; // Output pins
    PORTB = 0x00; // All PORTB initialised to be OFF
    
    void forward(i)
    {
        int j;
        for (j=0; j<48; j++)
        {
        PORTB = (1<<i);
        i++;              // Advance to the next output pin
        __delay_ms(100);   // StepDelay
        if (i==4)
            i=0;
        }
    }
   
    void backward(i)
    {
        int j;
        for (j=0,i=0; j<48; j++)
        {
        PORTB = (8>>i);
        i++;
        __delay_ms(100);
        if (i==4)
             i=0;
}
    }
    while(1)
    {
        forward(100);
        __delay_ms(100);
        backward(100);
    }
}
