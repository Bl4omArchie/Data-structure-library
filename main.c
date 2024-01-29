#include <stdio.h>
#include "src/file_struct.h"


int main() {
    DoublyLinkedList myList;

    init_linked_list(&myList);
    insert_data_head(&myList, 65468498);

    return 1;
}