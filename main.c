#include <stdio.h>
#include "src/file_struct.h"


int main() {
    DoublyLinkedList myList;
    init_linked_list(&myList);

    set_data(&myList, 4584799946);
    insert_data_tail(&myList, 674868);

    //printf ("%ld", find_head(myList.tail)->data);

    return 1;
}