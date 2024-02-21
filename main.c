#include "includes/file_struct.h"
#include "includes/benchmark.h"

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

uint64_t bigEndianToLittleEndian(uint64_t bigEndianNumber) {
    return ((bigEndianNumber & 0x00000000000000FFULL) << 56) |
           ((bigEndianNumber & 0x000000000000FF00ULL) << 40) |
           ((bigEndianNumber & 0x0000000000FF0000ULL) << 24) |
           ((bigEndianNumber & 0x00000000FF000000ULL) << 8)  |
           ((bigEndianNumber & 0x000000FF00000000ULL) >> 8)  |
           ((bigEndianNumber & 0x0000FF0000000000ULL) >> 24) |
           ((bigEndianNumber & 0x00FF000000000000ULL) >> 40) |
           ((bigEndianNumber & 0xFF00000000000000ULL) >> 56);
}

int time_test() {
    uint64_t a = 0b1111111101101011111111111111111111111111111111111111111111110000;
    uint64_t b = 0b1111111110101111110110111111111111111111111111111111111111111111;
    struct timeval tv_start, tv_end;


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

    gettimeofday(&tv_start, NULL);
    printf ("%d\n", predict_carry_v3(a, b));
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