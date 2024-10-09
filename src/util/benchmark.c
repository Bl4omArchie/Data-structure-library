#include <sys/time.h>
#include <time.h>

#include "benchmark.h"



// This benchmark is evaluating the time, ram and cpu consumption of the given function.



void benchmark(dll_bench *bench) {
    for (int i=0; i < bench->number_functions-1; i++) {
        benchmark_function(bench->all_functions[i]);

        printf ("%.2f", bench->all_functions[i]->time);
        printf ("%.2f", bench->all_functions[i]->ram);
        printf ("%.2f", bench->all_functions[i]->cpu_time);
    }

}

void benchmark_function(op_bench *func) {
    struct timeval start, end;
    clock_t c_start, c_end;
    long ram_before, ram_after;
    
    gettimeofday(&start, NULL);
    c_start = clock();
    ram_before = get_available_ram();

    func->to_bench(func->args);
    
    ram_after = get_available_ram();
    c_end = clock();
    gettimeofday(&end, NULL);

    func->time = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
    func->cpu_time = ((double) (c_end - c_start)) / CLOCKS_PER_SEC * 1000;
    func->ram = ram_before - ram_after;
}