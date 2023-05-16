#include <msp430.h> // Allows us to use "short-cut" names
#define ENABLE_RED 0xFFFE // Used to enable microcontroller's pins
#define DEVELOPMENT 0x5A80 // Used to disable some of the security
// features while we are still learning
main() // All C programs have a main function
{
    WDTCTL = DEVELOPMENT; // Disables some security features
    PM5CTL0 = ENABLE_RED; // Enables the pins
    P9DIR = BIT6; // P9.6 this line will automatically make pin P9.6 an output pin
    long x = 0; // Will be used to slow down blinking
    while(1) // Continuously repeat everything below
    {
        for(x=0 ; x < 30000 ; x=x+1); // Count from 0 to 30,000 for a delay
        P9OUT = BIT6; // This makes the pin P9.6 go high
        for(x=0 ; x < 30000 ; x=x+1); // Count from 0 to 30,000 for a delay
        P9OUT = 0x00; // This makes the pin P9.6 go low
    }
}
//Explanation
//Bit0 → 0000 0001 B → 0x01
//Bit1 → 0000 0010 B → 0x02
//Bit2 → 0000 0100 B → 0x04
//Bit3 → 0000 1000 B → 0x08
//Bit4 → 0001 0000 B → 0x10
//Bit5 → 0010 0000 B → 0x20
//Bit6 → 0100 0000 B → 0x40
//Bit7 → 1000 0000 B → 0x80

//P1DIR = P1DIR | BIT0;  here pin P1.0 is made an output 
//P1DIR = P1DIR | BIT4;  here pin P1.4 is made an output 
//P1DIR = P1DIR | BIT7;  here pin P1.7 is made an output 
