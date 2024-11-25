#ifndef SESSION_H
#define SESSION_H


#include "hardware.h"
#include "benchmark.h"
#include "util.h"


#define LOG_FILE "logs/log.txt"
#define REPORT_FILE "logs/report.csv"

// A session allows you yo properly make your benchmark. This manage the benchmark and the hardware profile properly 
typedef struct _bench_session {
    bench *array_bench;
    hprof *hardware_profile;
    int count_bench;
    int count_profile;
    const char *file_log;
    const char *file_report;
} b_session;


// High level function : use it for best practise
b_session *start_benchmark_session();
int end_benchmark_session(b_session *bs);

int add_bench(b_session *bs, bench *b);

int modify_log_file(b_session *bs, const char *filepath);
int modify_report_file(b_session *bs, const char *filepath);


#endif