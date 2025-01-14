#ifndef BITHACK_H
#define BITHACK_H

#include <stdint.h>

// Reverses the order of the bytes x = [a,b,c,d] -> [d,c,b,a].
uint32_t reverseBytes(uint32_t x);

// Prints the hex value.
void printHex(uint32_t x);

// Returns the byte from the given byte_num input. 0 = lsb.
uint8_t return_byte(uint32_t x, int byte_num);

// Turns on a bit at whatever location specifies. 0 = lsb.
uint32_t turn_bit_on(const uint32_t x, int bit_num);

// Prints the int in binary format.
void printBinary(uint32_t x);

// Returns 1 if input is a power of 2, otherwise 0.
int isPower2(int32_t x);

// Checks if the input is negative or positive. Returns 0 for positive.
int isNegative(int32_t x);

// Counts the number of bits that are on.
int count_bits_on(uint32_t x);

#endif