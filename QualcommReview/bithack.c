#include "bithack.h"
#include <stdio.h>

int count_bits_on(uint32_t x) {
    int bits_on = 0;
    uint32_t mask = 1; // last bit on
    for (int i = 0; i < 32; i++) {
        int last_bit = x & mask;
        bits_on += last_bit;
        x = x >> 1;
    }
    return bits_on;
}

// returns 0 if positive and 1 if negative
int isNegative(int32_t x) {
    int32_t mask = 1 << 31;
    int first_bit = x & mask;
    return first_bit >> 31;
}

int isPower2(int32_t x) { 
    if (count_bits_on(x) == 1)
        return 1;
    return 0;
}

void printBinary(uint32_t x) {
    int bits_on = 0;
    uint32_t mask = 1 << 31; // last bit on
    printf("x = 0x%0x : mask = 0x%0x \n", x, mask);
    for (int i = 0; i < 32; i++) {
        uint32_t first_bit = x & mask;
        printf("%u", first_bit >> 31); //lsb -? least significan bit
        x = x << 1;
    }
    printf("\n");
}

uint32_t turn_bit_on(const uint32_t x, int bit_num) {
    uint32_t y = x;
    uint32_t mask = 1 << (bit_num);
    y = x | mask;
    return y;
}

// Returns byte 0,1,2, or 3.
uint8_t return_byte(uint32_t x, int byte_num) {
    int byte = 0;
    uint32_t mask = 0xFF;
    byte = (x >> (byte_num * 8)) & mask;
    return byte;
}

// 0x%0x
void printHex(uint32_t x) {
    printf("Hex = 0x");
    for (int i = 3; i >= 0; i--) {
        uint8_t temp = return_byte(x, i);
        printf("%0x", temp);
    }
    printf("\n");
}

uint32_t reverseBytes(uint32_t x) {
    uint32_t byte0 = x & 0xFF;
    uint32_t byte1 = (x & 0xFF00) >> 8;
    uint32_t byte2 = (x & 0xFF0000) >> 16;
    uint32_t byte3 = (x & 0xFF000000) >> 24;
    uint32_t out = (byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3);
    return out;
}
