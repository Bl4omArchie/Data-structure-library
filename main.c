#include "includes/file_struct.h"
#include "includes/benchmark.h"

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>



int time_test() {
    uint64_t a = 0b1111111101101011111111111111111111111111111111111111111111110000;
    uint64_t b = 0b1111111110101111110110111111111111111111111111111111111111111111;
    struct timeval tv_start, tv_end;


    gettimeofday(&tv_start, NULL);

    //function to test
    printf ("%d\n", predict_carry(a, b));

    gettimeofday(&tv_end, NULL);
    double mtime = (tv_end.tv_sec - tv_start.tv_sec) * 1000000.0 + (tv_end.tv_usec - tv_start.tv_usec) / 1000000.0; // in ms
    printf ("%f\n", mtime);
}


void add_tail_test() {
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
}

int main() {


    return 1;
}