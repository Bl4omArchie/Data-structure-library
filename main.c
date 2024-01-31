#include <stdio.h>
#include <time.h>
#include "includes/file_struct.h"


uint64_t generateRandom64BitNumber() {
    uint64_t randomNum = 0;

    randomNum |= (uint64_t)rand() << 60;
    randomNum |= rand();

    return randomNum;
}

int main() {
    DoublyLinkedList myList;
    init_linked_list(&myList);
    set_data(&myList, generateRandom64BitNumber());

    srand(time(NULL));

    uint64_t N = 100000000;
    for (int i=0; i<N; i++)
        insert_data_tail(&myList, generateRandom64BitNumber());

    return 1;
}