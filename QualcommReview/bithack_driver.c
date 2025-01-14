#include <stdio.h>
#include "bithack.h"


int main()
{
    printf("In bithack driver running tests.\n");

    // Test 1 - count number of bits on
    uint32_t x = 0xFFFFFFFF;
    int bits_on = count_bits_on(x);
    printf("bits_on = %i value = %ui\n", bits_on, x);

    // Test 2 - check if the number is negative
    int32_t y = 10;
    int flag = isNegative(y);
    if (flag)
        printf("Number %i is Negative\n", y);
    else
        printf("Number %i is Postive\n", y);

    printBinary(10);

    // Test 3 - check if power of 2 -> brute force check.
   /*
    for (int i = 0; i < UINT32_MAX; i++) {

        int pow2 = isPower2(i);

        if (pow2) {
            printf("%i is power of 2\n", i);
            printBinary(i);
        }
    }
    */

    //Test 3.5 - check if power of 2->brute force check (1 number only).
    uint32_t power_test = 256;
    int pow2 = isPower2(power_test);

    if (pow2) {
        printf("%i is power of 2\n", power_test);
        printBinary(power_test);
    }
    else
        printf("%i is NOT power of 2\n", power_test);

    // Test 4 - Bit insertion.
    uint32_t test_bit = 8;
    int location = 2;

    // Test 5 - Inserting bit.
    uint32_t output = turn_bit_on(test_bit, location);

    printf("Info before: ");
    printBinary(test_bit);

    printf("Info after: ");
    printBinary(output);

    // Test 6 - Printing in hex.
    printHex(0xabcdefe1);

    // Test 7 - Reversing bytes.
    uint32_t test_bit2 = 0x04030201;
    printf("%0x\n", reverseBytes(test_bit2));

    return 0;
}