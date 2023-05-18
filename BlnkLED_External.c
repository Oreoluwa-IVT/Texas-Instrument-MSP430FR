//Code Description: This code simply turns on and blinks the two Onboard LEDs on the MSP430FR6989
#include <msp430.h>
void delay(void);
int main(void){
    WDTCTL = WDTPW | WDTHOLD;   // Disables the MSP430 watchdog timer, to present a reset every 32ms
    PM5CTL0 &= ~LOCKLPM5; // Disable the GPIO power-on default high-impedance mode
    P1DIR |= BIT0; // Set P1.0 to output direction
    P9DIR |= BIT7; // Set P1.0 to output direction
        long x;
        P1OUT ^= BIT0; // This Toggles the P1.0 Led ON and OFF because of the XOR Operator "^"
        P9OUT ^= BIT7; // This Toggles the P9.7 Led ON and OFF because of the XOR Operator "^"
        while(1) // Continuously repeat everything below
        {
            for(x=0 ; x < 30000 ; x=x+1); // Count from 0 to 30,000 for a delay
            P1OUT = 0x01; // This makes the pin P1.0 go high
            P9OUT = 0x80; // This makes the pin P9.7 go high
            for(x=0 ; x < 30000 ; x=x+1); // Count from 0 to 30,000 for a delay
            P1OUT = 0x00; // This makes the pin P1.0 go low
            P9OUT = 0x00; // This makes the pin P9.7 go low

        }
}



