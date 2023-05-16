#include <msp430.h> //msp430 library. Contains all the functions that the msp430 can understand.
#define OUT 0x1111 // pin configured as output (All pins in that port will be outputs)
#define HIGH 0x1111// pin enters a high state (All pins in that port will be high)
#define LOW 0xEEEE // pin enters a low state (All pins in that port will be low)
#define ENABLE_RED 0xFFFE // Used to enable microcontroller's pins //
#define DEVELOPMENT 0x5A80 // Used to disable some of the security

main() // All C programs have a main function
{
    WDTCTL = DEVELOPMENT; // Disables some security features
    PM5CTL0 = ENABLE_RED; // PM5CTL0 is a register in the MSP430FR6989 microcontroller that controls the power mode and the pin functionality
    P1DIR = HIGH; // Make a pin an output
    P4DIR = HIGH;
    long x = 0; // Will be used to slow down blinking
    while(1) // Continuously repeat everything below
    {
        for(x=0 ; x < 30000 ; x=x+1); // Count from 0 to 30,000 for a delay
        P1OUT = HIGH; // Turn red LED light on  //P1OUT is a register that controls the state of the pin.
        P4OUT = HIGH; 
        for(x=0 ; x < 30000 ; x=x+1); 
        // Count from 0 to 30,000 for a delay
        P1OUT = LOW; // Turn off the red LED light 
        P4OUT = LOW;
        //P1OUT is a register that controls the state of the pin.
               
    }
}
