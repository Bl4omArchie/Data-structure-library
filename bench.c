#include "includes/benchmark.h"
#include "includes/file_struct.h"




int main() {
    srand((unsigned int)time(NULL));

    DoublyLinkedList myList;
    init_linked_list(&myList);
    set_data(&myList, generateRandom64BitNumber());


    benchmark(&insert_data_tail, 1000, 2, &myList, generateRandom64BitNumber());

    return 1;
}