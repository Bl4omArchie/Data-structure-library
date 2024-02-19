#include "includes/file_struct.h"
#include "includes/benchmark.h"

#include <stdio.h>




int main() {
    DLL myList, start, end;
    init_linked_list(&myList);
    init_linked_list(&start);
    init_linked_list(&end);

    set_data(&myList, 0);
    set_data(&start, 1);
    set_data(&end, 5);
    

    insert_element_tail(&myList, &end);
    insert_data_tail(&myList, 4);
    insert_data_tail(&myList, 3);
    insert_data_tail(&myList, 2);
    insert_element_tail(&myList, &start);
    
    

    add_tail_range(&myList, start, end);
    display_linked_list(myList);

    return 1;
}