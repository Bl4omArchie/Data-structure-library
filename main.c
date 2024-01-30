#include <stdio.h>
#include "includes/file_struct.h"


int main() {
    DoublyLinkedList myList, *head;
    init_linked_list(&myList);

    set_data(&myList, 4584799946);
    insert_data_tail(&myList, 674868);

    head = find_head(&myList);

    clear_head_linked_list(&myList);

    return 1;
}