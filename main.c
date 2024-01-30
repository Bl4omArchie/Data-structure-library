#include <stdio.h>
#include "src/file_struct.h"


int main() {
    DoublyLinkedList myList;
    init_linked_list(&myList);

    insert_data(&myList, -464646);
    printf ("%ld\n", myList.data);

    return 1;
}