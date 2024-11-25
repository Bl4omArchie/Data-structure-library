#ifndef REPORT_H
#define REPORT_H


#include "benchmark.h"

#include <sys/stat.h>



int create_log(bench *b, const char *filepath, const char *message);
int fill_report(bench *b, const char *filepath);

void read_csv(const char *path_file);

#endif