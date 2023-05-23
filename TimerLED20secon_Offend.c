#include <msp430.h>
#define RED_LED 0x0001 // P1.0 is the red LED
#define DEVELOPMENT 0x5A80 // Stop the watchdog timer
#define ENABLE_PINS 0xFFFE // Required to use inputs and outputs
#define ACLK 0x0100 // Timer_A ACLK source
#define UP 0x0010 // Timer_A UP mode
#define TAIFG 0x0001 // Used to look at Timer A Interrupt FlaG
main()
{
    unsigned char intervals=0; // Count number of 50,000 counts
    WDTCTL = DEVELOPMENT; // Stop the watchdog timer
    PM5CTL0 = ENABLE_PINS; // Enable inputs and outputs
    TA0CCR0 = 50000; // We will count up from 0 to 50000
    TA0CTL = ACLK | UP; // Use ACLK, for UP mode
    P1DIR = RED_LED; // Set red LED as an output
    while(1)
    {
        if(TA0CTL & TAIFG) // If timer has counted to 50,000
        {
            intervals = intervals + 1; // Update number of 50,000 counts
            TA0CTL = TA0CTL & (~TAIFG); // Count again
            P1OUT |= BIT0; // Then, toggle red P1.0 LED
            if (intervals == 15) // If counted 10*50,000 = 500,000
            {
            //    intervals = 0; // Reset interval count
            P1OUT = 0x00; // Then, toggle red P1.0 LED
            while(2);
            }
            }
        }

}
//The ACLK counts every 25µs so if I want to count for 20seconds
// 20seconds / 20µs = 800,000
// this means we need to count up to 800,000 to attain 20seconds
// since  our TA0CCR0 IS set to count up to 50,000
// 50000x16 time will count 800,000
