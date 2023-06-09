#include <msp430.h>
#define RED_LED 0x0001 // P1.0 is the Red LED
#define DEVELOPMENT 0x5A80 // Stop the watchdog timer
#define ENABLE_PINS 0xFFFE // Required to use inputs and outputs
#define ACLK 0x0100 // Timer_A ACLK source
#define UP 0x0010 // Timer_A UP mode
#define TAIFG 0x0001 // Used to look at the Timer A Interrupt FlaG
main()
{
    WDTCTL = DEVELOPMENT; // Stop the watchdog timer
    PM5CTL0 = ENABLE_PINS; // Enable inputs and outputs
    TA0CCR0 = 20000; // We will count up from 0 to 20000
    TA0CTL = ACLK | UP; // Use ACLK, for UP mode
    P1DIR = RED_LED; // Set Red LED as an output
    while(1)
    {
        if(TA0CTL & TAIFG) // IF timer has counted to 20000
        { 
            P1OUT ^= RED_LED; // Then, toggle red P1.0 LED
            TA0CTL &= ~TAIFG; // Count again
        }
    }
}