#include "util.h"



#include <sys/time.h>
#include <time.h>



// This benchmark is evaluating the time, ram and cpu consumption of the given function.



void benchmark(func_bench to_bench, void *args) {
    struct timeval start, end;
    clock_t c_start, c_end;
    long ram_before, ram_after;
    
    gettimeofday(&start, NULL);
    c_start = clock();
    ram_before = get_available_ram();

    to_bench(args);
    
    ram_after = get_available_ram();
    c_end = clock();
    gettimeofday(&end, NULL);

    double execution_time = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
    double cpu_time_used = ((double) (c_end - c_start)) / CLOCKS_PER_SEC * 1000;
    double ram_used = ram_before - ram_after;

    printf("Execution time: %.2f ms\n", execution_time);
    printf("CPU cycle time: %.2f ms\n", cpu_time_used);
    printf("RAM used: %.3f GB\n", ram_used);
}