#ifndef BENCHMARK_H
#define BENCHMARK_H


#include "ll_struct.h"
#include "hardware.h"
#include "util.h"


#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>


// recorded info during the benchmark of a function for a single iteration
typedef struct _benchmark_context {
    struct timeval start;
    struct timeval end;
    clock_t c_start;
    clock_t c_end;
    long ram_before;
    long ram_after;
} bctx;

// a session is is the evaluation of one function.
// it consist of N rounds where we're iterates the function X times
// then for each rounds we take the average time it tooks to make each iteration
// in the end we have N averages time for X iteration each
typedef struct _session {
    bctx *bench_ctx;
    int size_bench_ctx;
    const char *operation;
    int N;
    int X;
} session;

// a benchmark is a set of session
// the benchmark purpose is to evaluate one function 
typedef struct _benchmark {
    session *arr_sessions;
    int size_sessions;
    const char *file_log;
    const char *file_report;
} benchmark;



bench *create_bench();
int end_benchmark(bench *b);

bench_ctx *create_bench_ctx();

void start_record(bench *b);
void end_record(bench *b);

bench *bench_dll_insertion_tail(int round, int iter);
bench *bench_dll_insertion_head(int round, int iter);



// Write the result of a benchmark into a text file
int create_log(bench *b, const char *filepath, const char *message);

// Same thing that create_log() but in csv file
int fill_report(bench *b, const char *filepath);



#endif