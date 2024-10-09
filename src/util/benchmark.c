#include <sys/time.h>
#include <time.h>

#include "benchmark.h"



// This benchmark is evaluating the time, ram and cpu consumption of the given function.


void init_bench(dll_bench *bench) {
    dll_init(bench->root);
    bench->size_dll = 0;
    bench->total_time = 0.0;
    bench->total_ram = 0.0;
    bench->total_cpu_time = 0.0;
    bench->functions = NULL;
    bench->size_functions = 0;
}

void load_function(dll_bench *bench, func_bench to_bench, void *args) {
    if (bench == NULL)
        return;

    bench->size_functions++;
    bench->functions = (op_bench*)realloc(bench->functions, bench->size_functions * sizeof(op_bench));
    bench->functions[bench->size_functions-1].to_bench = to_bench;
    bench->functions[bench->size_functions-1].args = args;
    bench->functions[bench->size_functions-1].time = 0.0;
    bench->functions[bench->size_functions-1].ram = 0.0;
    bench->functions[bench->size_functions-1].cpu_time = 0.0;
}

void free_bench(dll_bench *bench) {
    

}

void benchmark(dll_bench *bench) {
    for (int i=0; i < bench->size_functions-1; i++) {
        benchmark_function(&bench->functions[i]);

        printf ("%.2f", bench->functions[i].time);
        printf ("%.2f", bench->functions[i].ram);
        printf ("%.2f", bench->functions[i].cpu_time);
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