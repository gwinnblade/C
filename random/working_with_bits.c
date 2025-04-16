#include <stdio.h>

unsigned char reverse_bits(unsigned char b) {
    unsigned char result = 0;
    for (int i = 0; i < 8; i++) {
        result |= ((b >> i) & 1) << (7 - i);
    }
    return result;
}

int main() {
    unsigned char byte = 0xA4;  
    printf("0x%02X -> 0x%02X\n", byte, reverse_bits(byte));  
    return 0;
}
