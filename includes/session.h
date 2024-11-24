#ifndef SESSION_H
#define SESSION_H


#include "hardware.h"


#define LOG_FILE "logs/log.txt"
#define REPORT_FILE "logs/report.csv"

// A session allows you yo properly make your benchmark. This manage the benchmark and the hardware profile properly 
typedef struct _bench_session {
    bench *bench_log;
    hprof *profile;
    const char *log_file;
    const char *report_file;
} b_session;


// High level function : use it for best practise
b_session *start_benchmark_session();
void end_benchmark_session(b_session *bs);

int modify_log_file(b_session *bs, const char *filepath);
int modify_report_file(b_session *bs, const char *filepath)


#endif