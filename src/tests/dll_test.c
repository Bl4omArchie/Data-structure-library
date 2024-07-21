#include "dll_tests.h"


// Generate a random and positive 64 bits number
uint64_t generateRandom64BitNumber() {
    uint64_t randomNum = 0;
    randomNum |= (uint64_t)rand() << 60;
    randomNum |= rand();

    return randomNum;
}

int dll_routine() {
    Node_DLL linked_list_test;
    init_dll(&linked_list_test);

    // Insertion routine
    for (int i=0; i<100; i++) {
        insert_head_dll(&linked_list_test, generateRandom64BitNumber());
    }

    for (int i=0; i<100; i++) {
        insert_tail_dll(&linked_list_test, generateRandom64BitNumber());
    }
}