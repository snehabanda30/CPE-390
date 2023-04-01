#include <iostream> 
#include <iomanip> 
#include <cmath> 

int main () {
    uint8_t a = 255; 
    uint32_t b = 4'200'000'000U; 
    float f = 1.2345678f; // 32 bits
    f = 12.345678f; 
    f = 1.23456678e-38f; 
    double d = 1.23456789012345;
    /*
    sign = 1 0/1 
    exponent= 8 bits where is the binary place 
    mantissa = 24 bits digits of the number 
        1xxxxxxxxxxxxxxxxxxxx
    0 01111111 
    int8_t a = -128..127
    */
}