//The code needs the uart.h library for serial communication to work. 7
// Version 1.0.0 (Stable)
//there's a folder calle "User defined" in the respository. Make sure you add that as part of the project and link in the code composer studio. 
#include <msp430.h>
#include "uart.h"
#define ENABLE_PINS 0xFFFE // Enables inputs and outputs
void ADC_SETUP(void); // Used to setup ADC12 peripheral
long map(long value, long fromLow, long fromHigh, long toLow, long toHigh) {
    return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}

main()
{
    WDTCTL = WDTPW | WDTHOLD; // Stop WDT
    uart_init(CONFIG_A1, CLOCK_1MHZ);
    PM5CTL0 = ENABLE_PINS; // Enable inputs and outputs
    P1DIR = BIT0; // Set RED LED to output
    ADC_SETUP(); // Sets up ADC peripheral
    while(1)
    {
        ADC12CTL0 = ADC12CTL0 | ADC12ENC; // Enable conversion
        ADC12CTL0 = ADC12CTL0 | ADC12SC; // Start conversion
        // Looking for threshold of 50% of 3.3V
        // with binary equivalent of
        // 1000 0000 0000B = 0x8000
         int b = ADC12MEM0; // The value of the sensor is store in  the "ADC12mem0" register then stored in the variable "b".
         int output1 = map(b, 0,4096, 1,5); //The msp430 has a 12 bit ADC that is why the range is 4096. 
         // it was mapped to give an output range of 1-5v because it was specified on the datasheet that the output voltage 
         // would range from 1-5v.
         int output2 = map(output1,1,5, 0,3000); // The values were later mapped to 0-3000 because the pressure range is 0-3000psi.
      //   int output2 = 750*(output1-1);
         transmitMessage("Pressure: "); // The pressure is then printed to the terminal.
      //   transmitMessage("%d\r\n",output1);
         transmitMessage("%d\r\n",output2); // The pressure is then printed to the terminal.

        __delay_cycles(130000); //  Delay for a certain period of time . Not sure. but the value changes based on what you supply. Refer to the function definition.
       // transmitMessage("%d\n",a);
        if (ADC12MEM0 > 0x001) // If input > 1.65V
        {
            P1OUT = BIT0; // Turn on red LED
        }
        else // Else input <= 1.65V
        {
            P1OUT = 0x00; // Turn off red LED
        }
    }// end while(1)
}// end main()
//************************************************************************
//* Configure Analog-to-Digital Converter peripheral**********************
//************************************************************************
void ADC_SETUP(void)
{
#define ADC12_SHT_16 0x0200 // 16 clock cycles for sample and hold
#define ADC12_ON 0x0010 // Used to turn ADC12 peripheral on
#define ADC12_SHT_SRC_SEL 0x0200 // Selects source for sample & hold
#define ADC12_12BIT 0x0020 // Selects 12-bits of resolution
#define ADC12_P92 0x000A // Use input P9.2 for analog input
    ADC12CTL0 = ADC12_SHT_16 | ADC12_ON ; // Turn on, set sample & hold time
    ADC12CTL1 = ADC12_SHT_SRC_SEL; // Specify sample & hold clock source
    ADC12CTL2 = ADC12_12BIT; // 12-bit conversion results
    ADC12MCTL0 = ADC12_P92; // P9.2 is analog input
//Timer is incremental
}
//