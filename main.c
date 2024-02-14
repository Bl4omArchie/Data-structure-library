#include "includes/file_struct.h"
#include "includes/benchmark.h"

#include <stdio.h>




int main() {
    DoublyLinkedList myList, end;
    init_linked_list(&myList);
    init_linked_list(&end);

    set_data(&myList, 1);
    set_data(&end, 4);
    
    insert_data_tail(&myList, 2);
    insert_data_tail(myList.tail, 3);
    insert_element_tail(myList.tail->tail, &end);


    printf ("%ld\n", find_tail(&myList)->data);

    add_tail_range(&myList, myList, end);
    display_linked_list(myList);

    return 1;
}