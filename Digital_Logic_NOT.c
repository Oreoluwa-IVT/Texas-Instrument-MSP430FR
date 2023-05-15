#include <msp430.h>
main()
{
    char a = 0b10101101; // Inputs from step 14
    char b = 0b01111111;
    char c = 0b00000000;
    char u, v, w, x, y, z; // Answers will go here
    // Bit wise Byte-wise
    u = ~a; // ~ 10101101 ! 10101101
    v = !a; // ---------- ----------
    // = 01010010 = 00000000
    w = ~b; // ~ 01111111 ! 01111111
    x = !b; // ---------- ----------
    // = 10000000 = 00000000
    y = ~c; // ~ 00000000 ! 00000000
    z = !c; // ---------- ----------
    // = 11111111 = 00000001
    while(1); // Stay here when done
}