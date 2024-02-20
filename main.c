#include "includes/file_struct.h"
#include "includes/benchmark.h"

#include <stdio.h>
#include <sys/time.h>


int time_test() {
    int a = 0xabc4baf;
    int b = 0xabcffff;
    struct timeval tv_start, tv_end;

    printf ("%d, %d\n", a, b);
    printf ("%d", (a+b));

    gettimeofday(&tv_start, NULL);

    printf ("%d\n", predict_carry(a, b));

    gettimeofday(&tv_end, NULL);
    double mtime = (tv_end.tv_sec - tv_start.tv_sec) * 1000000.0 + (tv_end.tv_usec - tv_start.tv_usec) / 1000000.0; // in ms
    printf ("%f\n", mtime);

    
    gettimeofday(&tv_start, NULL);

    printf ("%d\n", predict_carry_v2(a, b));

    gettimeofday(&tv_end, NULL);
    mtime = (tv_end.tv_sec - tv_start.tv_sec) * 1000000.0 + (tv_end.tv_usec - tv_start.tv_usec) / 1000000.0; // in ms
    printf ("%f\n", mtime);
    
}

int main() {
    time_test();


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