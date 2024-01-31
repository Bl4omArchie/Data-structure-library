#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "includes/file_struct.h"

uint64_t generateRandom64BitNumber() {
    uint64_t randomNum = 0;

    randomNum |= (uint64_t)rand() << 60;
    randomNum |= rand();

    return randomNum;
}

void file_list(uint64_t n) {
    srand((unsigned int)time(NULL));
    clock_t start, end;
    double cpu_time_used;

    DoublyLinkedList myList;
    init_linked_list(&myList);
    set_data(&myList, generateRandom64BitNumber());

    start = clock();

    for (int i=0; i<n; i++)
        insert_data_tail(&myList, generateRandom64BitNumber());
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %.10f seconds\n", cpu_time_used);
}


int main() {
    file_list(100000000);
    return 1;
}