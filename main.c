#include "includes/file_struct.h"
#include "includes/benchmark.h"

#include <stdio.h>




int main() {
    DoublyLinkedList myList;
    init_linked_list(&myList);

    set_data(&myList, 75345649876);
    insert_data_tail(&myList, 5434567);
    insert_data_tail(myList.tail, 9876543);

    add_tail(&myList);
    add_head(myList.tail);
    display_linked_list(myList);

    return 1;
}