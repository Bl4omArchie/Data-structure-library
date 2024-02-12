#include "../includes/benchmark.h"
#include "../includes/file_struct.h"



uint64_t generateRandom64BitNumber() {
    uint64_t randomNum = 0;
    randomNum |= (uint64_t)rand() << 60;
    randomNum |= rand();

    return randomNum;
}

void file_list(uint64_t n) {
    DoublyLinkedList myList;
    init_linked_list(&myList);
    set_data(&myList, generateRandom64BitNumber());

    
    srand((unsigned int)time(NULL));
    struct timeval tv_start, tv_end;
    gettimeofday(&tv_start, NULL);

    for (int i=0; i<n; i++)
        insert_data_tail(&myList, generateRandom64BitNumber());

    gettimeofday(&tv_end, NULL);
    double mtime = (tv_end.tv_sec - tv_start.tv_sec) * 1000000.0 + (tv_end.tv_usec - tv_start.tv_usec) / 1000000.0; // in ms
    printf ("Benchmark done in: %fs\n", mtime);
}