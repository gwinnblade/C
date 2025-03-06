#include <stdio.h>
// Напишите программу, которая меняет 1-й и 2-й биты числа.
// Например, число 13 в двоичной системе равно 0b01101.
// В результате надо получить 0b01011 или число 11 в десятичной системе. 
// Отсчет битов идет справа налево (от младших разрядов к старшим) начиная с нуля.  
int main()
{
    unsigned char data = 0b1101;
    unsigned char bit_1 = (data >> 1) & 1;
    unsigned char bit_2 = (data >> 2) & 1;
    unsigned char xor_of_bit = bit_1 ^ bit_2;
    unsigned char result = data ^ (xor_of_bit << 1 | xor_of_bit << 2);
    printf("Result: %d", result);
    return 0;
}
