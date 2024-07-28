#include "util.h"


// Generate a random and positive 64 bits number
uint64_t generate_random_number() {
    uint64_t randomNum = 0;
    randomNum |= (uint64_t)rand() << 60;
    randomNum |= rand();

    return randomNum;
}