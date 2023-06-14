#include <msp430.h>
#include <driverlib.h> // Required for the LCD
#include "myGpio.h" // Required for the LCD
#include "myClocks.h" // Required for the LCD
#include "myLcd.h" // Required for the LCD
main()
{
    unsigned long i,j; // Use for delays and for loops
    WDTCTL = WDTPW | WDTHOLD; // Stop WDT
    initGPIO(); // Initializes General Purpose
    // Inputs and Outputs for LCD
    initClocks(); // Initialize clocks for LCD
    myLCD_init(); // Prepares LCD to receive commands
    while(1)
    {
        myLCD_showChar( ' ', 1 );
        myLCD_showChar( ' ', 2 );
        myLCD_showChar( ' ', 3 );
        myLCD_showChar( ' ', 4 );
        myLCD_showChar( ' ', 5 );
        myLCD_showChar( '3', 6 );
        for(i=0;i<987654;i=i+1);
        myLCD_showChar( '2', 6 );
        for(i=0;i<987654;i=i+1);
        myLCD_showChar( '1', 6 );
        for(i=0;i<987654;i=i+1);
        myLCD_showChar( 'B', 1 );
        myLCD_showChar( 'U', 2 );
        myLCD_showChar( 'D', 3 );
        myLCD_showChar( 'N', 4 );
        myLCD_showChar( 'I', 5 );
        myLCD_showChar( 'K', 6 );
        for(i=0;i<987654;i=i+1);
        myLCD_showChar( 'S', 1 );
        myLCD_showChar( 'A', 2 );
        myLCD_showChar( 'Y', 3 );
        myLCD_showChar( 'S', 4 );
        myLCD_showChar( ' ', 5 );
        myLCD_showChar( ' ', 6 );
        for(i=0;i<987654;i=i+1);
        myLCD_showChar( ' ', 1 );
        myLCD_showChar( ' ', 2 );
        myLCD_showChar( ' ', 3 );
        myLCD_showChar( ' ', 4 );
        myLCD_showChar( 'H', 5 );
        myLCD_showChar( 'I', 6 );
        for(i=0;i<654321;i=i+1);
        myLCD_showChar( ' ', 1 );
        myLCD_showChar( ' ', 2 );
        myLCD_showChar( ' ', 3 );
        myLCD_showChar( ' ', 4 );
        myLCD_showChar( 'H', 5 );
        myLCD_showChar( 'I', 6 );
        for(i=0;i<654321;i=i+1);
        myLCD_showChar( 'H', 4 );
        myLCD_showChar( 'I', 5 );
        myLCD_showChar( ' ', 6 );
        for(i=0;i<654321;i=i+1);
        myLCD_showChar( 'H', 3 );
        myLCD_showChar( 'I', 4 );
        myLCD_showChar( ' ', 5 );
        for(i=0;i<654321;i=i+1);
        myLCD_showChar( 'H', 2 );
        myLCD_showChar( 'I', 3 );
        myLCD_showChar( ' ', 4 );
        for(i=0;i<654321;i=i+1);
        myLCD_showChar( 'H', 1 );
        myLCD_showChar( 'I', 2 );
        myLCD_showChar( ' ', 3 );
        for(i=0;i<654321;i=i+1);
        myLCD_showChar( 'I', 1 );
        myLCD_showChar( ' ', 2 );
        for(i=0;i<654321;i=i+1);
        myLCD_showChar( ' ', 1 );
        for(i=0;i<987654;i=i+1);
        myLCD_showChar( 'G', 1 );
        myLCD_showChar( 'O', 2 );
        for(i=0;i<987654;i=i+1);
        for(j=0;j<6;j=j+1)
        {
            myLCD_showChar( 'V', 1 );
            myLCD_showChar( 'A', 2 );
            myLCD_showChar( 'L', 3 );
            myLCD_showChar( 'P', 4 );
            myLCD_showChar( 'O', 5 );
            myLCD_showChar( ' ', 6 );
            for(i=0;i<98765;i=i+1);
            myLCD_showChar( ' ', 1 );
            myLCD_showChar( ' ', 2 );
            myLCD_showChar( ' ', 3 );
            myLCD_showChar( ' ', 4 );
            myLCD_showChar( ' ', 5 );
            for(i=0;i<98765;i=i+1);
        }
        for(i=0;i<987654;i=i+1);
    }
}

