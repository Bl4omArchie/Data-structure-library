#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "src/file_struct.h"



int file_list(uint64_t n) {
    DoublyLinkedList benchmarkList;
    srand((unsigned int)time(NULL));
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for (int i=0; i<n; i++) {
        insert_head(&benchmarkList, rand());
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Time taken: %.10f seconds\n", cpu_time_used);
}


int main() {
    file_list(10000000);
    return 1;
}