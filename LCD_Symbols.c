#include <msp430.h>
#include <driverlib.h> // Required for the LCD
#include "myGpio.h" // Required for the LCD
#include "myClocks.h" // Required for the LCD
#include "myLcd.h" // Required for the LCD
main()
{
    unsigned long i; // Use for delay
    WDTCTL = WDTPW | WDTHOLD; // Stop WDT
    initGPIO(); // Initializes General Purpose
    // Inputs and Outputs for LCD
    initClocks(); // Initialize clocks for LCD
    myLCD_init(); // Prepares LCD to receive commands
    while(1)
    {
        myLCD_showSymbol(LCD_TOGGLE,LCD_HRT,0); // Toggle heart symbol
        for(i=0 ; i<234567 ; i = i+1); // Delay
    }
}
