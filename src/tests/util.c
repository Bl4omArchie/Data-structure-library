#include "ll_tests.h"


#include <sys/sysinfo.h>


// Generate a random and positive 64 bits number
uint64_t generate_random_number() {
    uint64_t randomNum = 0;
    randomNum |= (uint64_t)rand() << 60;
    randomNum |= rand();

    return randomNum;
}

uint64_t get_maximal_element() {
    struct sysinfo sys_info;

    if (sysinfo(&sys_info) != 0)
        perror("sysinfo");
    
    return (sys_info.totalram / sizeof(Node_DLL)) / 2;
}