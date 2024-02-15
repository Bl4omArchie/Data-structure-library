#include "../includes/benchmark.h"
#include "../includes/file_struct.h"


// Generate a random and positive 64 bits number
uint64_t generateRandom64BitNumber() {
    uint64_t randomNum = 0;
    randomNum |= (uint64_t)rand() << 60;
    randomNum |= rand();

    return randomNum;
}

// Repeat a function n times, print the total execution time 
void benchmark(bench_func_t func, int iter, int argc, char *argv[]) {
    struct timeval tv_start, tv_end;
    gettimeofday(&tv_start, NULL);

    for (int i=0; i<iter; i++)
        (func)(argc, argv);

    gettimeofday(&tv_end, NULL);
    double mtime = (tv_end.tv_sec - tv_start.tv_sec) * 1000000.0 + (tv_end.tv_usec - tv_start.tv_usec) / 1000000.0; // in ms
    printf ("Benchmark done in: %fs\n", mtime);
}