#include "ll_tests.h"



// Generate a random and positive 64 bits number
uint64_t generateRandom64BitNumber() {
    uint64_t randomNum = 0;
    randomNum |= (uint64_t)rand() << 60;
    randomNum |= rand();

    return randomNum;
}