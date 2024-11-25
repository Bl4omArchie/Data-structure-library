#ifndef BENCHMARK_H
#define BENCHMARK_H


#include "ll_struct.h"
#include "hardware.h"
#include "util.h"

#include <sys/time.h>
#include <time.h>


// The context benchmark is the data related to the calculation of the performance of a function
typedef struct _bench_context {
    struct timeval start;
    struct timeval end;
    clock_t c_start;
    clock_t c_end;
    long ram_before;
    long ram_after;
} bench_ctx;

// When you benchmark a function, the performance will be stored here
typedef struct _bench {
    double time;
    double ram;
    double cpu_time;
    bench_ctx *bctx;
} bench;

// See session.h for best practise


bench *create_bench();
bench_ctx *create_bench_ctx();
int end_benchmark(bench *b);

void start_record(bench_ctx *b_ctx);
void end_record(bench *b, bench_ctx *b_ctx);

bench *bench_dll_insertion_tail(int round, int iter);
bench *bench_dll_insertion_head(int round, int iter);


#endif