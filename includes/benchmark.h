#ifndef BENCHMARK_H
#define BENCHMARK_H


#include "util.h"
#include "ll_struct.h"

#include <sys/time.h>
#include <time.h>

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


#define LOG_FILE "logs/log.txt"


bench *create_bench();
bench_ctx *create_bench_ctx();

void start_bench(bench_ctx *b_ctx);
void end_bench(bench *b, bench_ctx *b_ctx);

bench *bench_dll_insertion_tail(int round, int iter);
bench *bench_dll_insertion_head(int round, int iter);


int create_log(bench *b, const char *message);


#endif