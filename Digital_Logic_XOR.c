#include <msp430.h>
main()
{
    char a = 0b00000000;
    char b = 0b11111111;
    char c = 0b00000001;
    char d = 0b00000010;
    char e = 0b10000000;
    char f = 0b11110000;
    char s, t, u, v, w, x, y, z; // Answers will go here
    s = a ^ c; // Toggle last bit
    t = b ^ c; // Toggle last bit
    u = a ^ d; // Toggle next-to-last bit
    v = b ^ d; // Toggle next-to-last bit
    w = a ^ e; // Toggle first bit
    x = b ^ e; // Toggle first bit
    y = a ^ f; // Toggle first 4 bits
    z = b ^ f; // Toggle first 4 bits
    while(1); // Stay here when done
}
