#ifndef BENCHMARK_H
#define BENCHMARK_H


#include "ll_struct.h"
#include "hardware.h"

#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>


// recorded info during the benchmark of a function for a single iteration
typedef struct _benchmark_context {
    struct timeval start;           // time when the chrono start
    struct timeval end;             // time when the chrono end
    clock_t c_start;                // same with clock time
    clock_t c_end;                  // ~
    long ram_before;                // ram consumption
    long ram_after;                 // ~
} bctx;

// a session is is the evaluation of one function.
// it consist of N rounds where we're iterates the function X times
// then for each rounds we take the average time it tooks to make each iteration
// in the end we have N averages time for X iteration each
typedef struct _session {
    bctx *bench_ctx;                // array of bctx
    int size_bench_ctx;             // current size of the array
    const char *operation;          // name of the evaluated operation (ie: insert, )
    int N;                          // rounds
    int X;                          // iterations 
} session;

// a benchmark is a set of session
// the benchmark purpose is to evaluate one function 
typedef struct _benchmark {
    session *arr_sessions;
    int size_sessions;
    hprof *hardware_profile;
    const char *file_log;
    const char *file_report;
} benchmark;


#define LOG_FILE "logs/log.txt"
#define REPORT_FILE "logs/report.csv"


// BENCHMARK 

benchmark *bench_dll_insertion_tail(int round, int iter);
benchmark *bench_dll_insertion_head(int round, int iter);


// ********* bench.c *********
benchmark *start_benchmark();
int end_benchmark(benchmark *b);

int add_session(benchmark *b, session *s);

int check_file_exists(const char* filename);
int modify_log_file(benchmark *b, const char *filepath);
int modify_report_file(benchmark *b, const char *filepath);


// ********* session.c *********
session *create_session();
int get_session(benchmark *b)
int init_session(session *s, int round, int iteration, const char *op);
int free_session(session *s);
int add_bench(session *s, benchmark *b);

bctx *create_bench_ctx();
void start_record(bctx *bench_ctx);
void end_record(bctx *bench_ctx);


// ********* log.c *********
// Write the result of a benchmark into a text file
int create_log(benchmark *b, const char *filepath, const char *message);

// Same thing that create_log() but in csv file
int fill_report(benchmark *b, const char *filepath);



#endif