#include <msp430.h> // Need this to easily stop watchdog
//**************************************************************************
// Function Prototype
//**************************************************************************
signed int cubed(signed char); // Has an input of type signed char
// Has an output of type signed int
//**************************************************************************
// Main program is here
//**************************************************************************
main()
{
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    signed int answer=0; // We will store the result of the
    // cubed function in this variable
    answer = cubed(6); // This is the function call. It
    // sends the value of 6 to the function
    // and will put the function's output
    // into the variable called answer
    while(1); // Stay here forever after done
}//end main()
//**************************************************************************
// Function Defintion
//**************************************************************************
signed int cubed (signed char x) // Has an input of type signed char that
{ // will be called "x" in the function
    // It also has an output of type signed int
    signed int result=0; // Clear a variable to hold the result
    result = x*x*x; // result will be cubed value of input "x"
    return result; // send contents of result back to answer
}
