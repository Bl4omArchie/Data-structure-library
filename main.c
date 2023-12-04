#include <stdio.h>
#include "src/file_struct.h"


int main() {
    DoublyLinkedList myList;
    init_list(&myList);

    insert_head(&myList, 1);
    insert_head(&myList, 1011100);
    insert_head(&myList, 101010);

    return 1;
}