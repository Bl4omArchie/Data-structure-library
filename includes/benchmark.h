#ifndef BENCHMARK_H
#define BENCHMARK_H


#include "util.h"
#include "ll_struct.h"



typedef struct _bench {
    double time;
    double ram;
    double cpu_time;
} bench;

typedef struct _bench_context {
    struct timeval start;
    struct timeval end;
    clock_t c_start;
    clock_t c_end;
    long ram_before;
    long ram_after;
} bench_ctx;


bench *create_bench();
bench_ctx *create_bench_ctx();

void start_bench(bench_ctx *b_ctx);
void end_bench(bench *b, bench_ctx *b_ctx);

bench *bench_dll_insertion();

int bench_dll_minimal();
int bench_dll_medium();
int bench_dll_maximal();



#endif