#include <msp430.h>
#define ENABLE_PINS 0xFFFE // Required to use inputs and outputs
#define UART_CLK_SEL 0x0080 // Specifies an accurate clock for UART
// peripheral
#define BR0_FOR_9600 0x34 // Value required to use 9600 baud
#define BR1_FOR_9600 0x00 // Value required to use 9600 baud
#define CLK_MOD 0x4911 // Microcontroller will "clean-up" clock signal
void select_clock_signals(void); // Assigns microcontroller clock signals
void assign_pins_to_uart(void); // P4.2 is for TXD, P4.3 is for RXD
void use_9600_baud(void); // UART operates at 9600 bits/second
main()
{
    WDTCTL = WDTPW | WDTHOLD; // Stop WDT
    PM5CTL0 = ENABLE_PINS; // Enable pins
    P1DIR = BIT0; // Make P1.0 an output for red LED
    P1OUT = 0x00; // Red LED initially off
    select_clock_signals(); // Assigns microcontroller clock signals
    assign_pins_to_uart(); // P4.2 is for TXD, P4.3 is for RXD
    use_9600_baud(); // UART operates at 9600 bits/second
    UCA0TXBUF = 0x56; // Send the UART message 0x56 out pin P4.2
    while(1) // Checking for incoming messages
    {
        if(UCA0IFG & UCRXIFG) // Received any new messages?
        {
            if(UCA0RXBUF == 0x56) // If the message is 0x56
            {
                P1OUT = BIT0; // Then, turn on red LED
            }
            else // Else, the message is not 0x56
            {
                P1OUT = 0x00; // Turn off the red LED
            }
            UCA0IFG = UCA0IFG & (~UCRXIFG); // Reset the UART receive flag
        }
    }// end while(1)
}// end main()
