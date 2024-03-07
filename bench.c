#include "includes/benchmark.h"
#include "includes/file_struct.h"

#include <limits.h>


unsigned long long int add_64bit_numbers(uint64_t num1, uint64_t num2, int carry) {
    if (num1 > (ULLONG_MAX - num2))
        return ULLONG_MAX; 
    else
        return num1 + num2 + carry;
}

int main(int argc, char *argv[]) {
    srand((unsigned int)time(NULL));
    uint64_t a = 0xffffffffffffff;
    uint64_t b = 0xffffffffffffff;
    int c = 1;

    struct timeval tv_start, tv_end;
    gettimeofday(&tv_start, NULL);

    for (int i=0; i<100000000; i++)
        add_binary_optimized(a, b, c);

    gettimeofday(&tv_end, NULL);
    double mtime = (tv_end.tv_sec - tv_start.tv_sec) * 1000000.0 + (tv_end.tv_usec - tv_start.tv_usec) / 1000000.0; // in ms
    printf ("Benchmark done in: %fs\n", mtime);


    gettimeofday(&tv_start, NULL);
    for (int i=0; i<100000000; i++)
        add_64bit_numbers(a, b, c);
    gettimeofday(&tv_end, NULL);
    mtime = (tv_end.tv_sec - tv_start.tv_sec) * 1000000.0 + (tv_end.tv_usec - tv_start.tv_usec) / 1000000.0; // in ms
    printf ("Benchmark done in: %fs\n", mtime);

    return 1;
}