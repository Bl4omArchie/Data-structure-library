#include <stdio.h>
#include "src/file_struct.h"


int main() {
    DoublyLinkedList myList;
    init_list(&myList);

    insert_head(&myList, 569464);
    insert_head(&myList, 1561651);
    insert_head(&myList, 56489464);

    print_doubly_linked(&myList);

    return 1;
}