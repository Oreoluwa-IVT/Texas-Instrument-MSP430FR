#include <msp430.h>
#include <driverlib.h> // Required for the LCD
#include "myGpio.h" // Required for the LCD
#include "myClocks.h" // Required for the LCD
#include "myLcd.h" // Required for the LCD
main()
{
    WDTCTL = WDTPW | WDTHOLD; // Stop WDT
    initGPIO(); // Initializes General Purpose
    // Inputs and Outputs for LCD
    initClocks(); // Initialize clocks for LCD
    myLCD_init(); // Prepares LCD to receive commands
    myLCD_showChar( 'H', 1 ); // Display "H" in space 1
    myLCD_showChar( 'E', 2 ); // Display "E" in space 2
    myLCD_showChar( 'L', 3 ); // Display "L" in space 3
    myLCD_showChar( 'L', 4 ); // Display "L" in space 4
    myLCD_showChar( 'O', 5 ); // Display "O" in space 5
    myLCD_showChar( ' ', 6 ); // Display blank space in space 6
    while(1);
}




//LCD_Files folder is needed for this code to run. See repository for details.
// Use the following steps to add it to you code using CCS (Code Composer Studio)
// 1. Right click on the project name in the Project Explorer window
// 2. Select "Show Build Settings"
// 3. Select "Include Options"
// 4. Select "Add Directory Path Icon"  
// 5. Browse to the folder and select it
// 6. Click "OK"
// 7. Click "OK" again/Apply and Close
// Build the project and it should work.

