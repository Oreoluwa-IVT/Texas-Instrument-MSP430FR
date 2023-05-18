//Code Description: This code simply turns on and blinks the two Onboard LEDs on the MSP430FR6989
#include <msp430.h>
int main(void){
    WDTCTL = WDTPW | WDTHOLD;   // Disables the MSP430 watchdog timer, to present a reset every 32ms
    PM5CTL0 &= ~LOCKLPM5; // Disable the GPIO power-on default high-impedance mode
    P1DIR |= BIT0; // Set P1.0 to output direction
    P9DIR |= BIT7; // Set P1.0 to output direction
    while(1)
    {
        P1OUT ^= BIT0; // This Toggles the P1.0 Led ON and OFF because of the XOR Operator "^"
        P9OUT ^= BIT7; // This Toggles the P9.7 Led ON and OFF because of the XOR Operator "^"
      //  P9OUT  |= BIT7; // This line of code would only turn on the LED because it simply just make BIT 7 High over and over again. unlike XOR

      // Explanation of XOR and Just OR Operator in the blink operation
      // If we used the XOR Operator
      // Initial registers for P9.7 would be                10000000 (because 1 XOR nothing is =1) LED comes on
      // 2nd time the while loop run the registers will be  10000000 (because 1 XOR 1 is =0)       LED goes off
      // 3rd  time the registers will be                    10000000 (because 0 XOR 1 is =1)       LED comes on
    }

}
