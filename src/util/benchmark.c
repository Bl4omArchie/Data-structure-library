#include <sys/time.h>
#include <time.h>

#include "benchmark.h"



// This benchmark is evaluating the time, ram and cpu consumption of the given function.


void init_bench(dll_bench *bench, const char *filename_dataset) {
    bench->root = new_dll(0);
    bench->size_dll = 0;
    bench->total_time = 0.0;
    bench->total_ram = 0.0;
    bench->total_cpu_time = 0.0;
    bench->filename_dataset = filename_dataset;
    bench->func_v = NULL;
    bench->func_i = NULL;
    bench->n_func_v = 0;
    bench->n_func_i = 0;
}

void load_function_v(dll_bench *bench, func_bench_v function, void *args) {
    if (bench == NULL)
        return;

    bench->n_func_v++;
    bench->func_v = (opevv*)realloc(bench->func_v, bench->n_func_v * sizeof(opevv));
    bench->func_v[bench->n_func_v-1].function = function;
    bench->func_v[bench->n_func_v-1].args = NULL;
    bench->func_v[bench->n_func_v-1].time = 0.0;
    bench->func_v[bench->n_func_v-1].ram = 0.0;
    bench->func_v[bench->n_func_v-1].cpu_time = 0.0;
}

void load_function_i(dll_bench *bench, func_bench_i function, void *args) {
    if (bench == NULL)
        return;

    bench->n_func_i++;
    bench->func_i = (opevi*)realloc(bench->func_i, bench->n_func_i * sizeof(opevi));
    bench->func_i[bench->n_func_i-1].function = function;
    bench->func_i[bench->n_func_i-1].args_ret = NULL;
    bench->func_i[bench->n_func_i-1].args = NULL;
    bench->func_i[bench->n_func_i-1].time = 0.0;
    bench->func_i[bench->n_func_i-1].ram = 0.0;
    bench->func_i[bench->n_func_i-1].cpu_time = 0.0;
}

void free_bench(dll_bench *bench) {
    if (bench == NULL)
        return;

    dll_free(bench->root);
    free(bench->func_v);
    free(bench);
}

// Make the benchmark for a function
void bench_func_v(opevv *func) {
    struct timeval start, end;
    clock_t c_start, c_end;
    long ram_before, ram_after;
    
    gettimeofday(&start, NULL);
    c_start = clock();
    ram_before = get_available_ram();

    func->function(func->args);
    
    ram_after = get_available_ram();
    c_end = clock();
    gettimeofday(&end, NULL);

    func->time = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
    func->cpu_time = ((double) (c_end - c_start)) / CLOCKS_PER_SEC * 1000;
    func->ram = ram_before - ram_after;
}

void bench_func_i(opevi *func) {
    struct timeval start, end;
    clock_t c_start, c_end;
    long ram_before, ram_after;
    
    gettimeofday(&start, NULL);
    c_start = clock();
    ram_before = get_available_ram();

    func->function(func->args);
    
    ram_after = get_available_ram();
    c_end = clock();
    gettimeofday(&end, NULL);

    func->time = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
    func->cpu_time = ((double) (c_end - c_start)) / CLOCKS_PER_SEC * 1000;
    func->ram = ram_before - ram_after;
}

// Execute the benchmark for every loaded function
void benchmark(dll_bench *bench) {
    
    for (int i=0; i < bench->n_func_v-1; i++) {
        bench_func_v(&bench->func_v[i]);

        printf ("%.2f", bench->func_v[i].time);
        printf ("%.2f", bench->func_v[i].ram);
        printf ("%.2f", bench->func_v[i].cpu_time);
    }

    for (int i=0; i < bench->n_func_i-1; i++) {
        bench_func_i(&bench->func_i[i]);

        printf ("%.2f", bench->func_i[i].time);
        printf ("%.2f", bench->func_i[i].ram);
        printf ("%.2f", bench->func_i[i].cpu_time);
    }
}