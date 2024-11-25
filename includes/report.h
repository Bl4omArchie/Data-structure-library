#ifndef REPORT_H
#define REPORT_H


#include "benchmark.h"

#include <sys/stat.h>


// Write the result of a benchmark into a text file
int create_log(bench *b, const char *filepath, const char *message);

// Same thing that create_log() but in csv file
int fill_report(bench *b, const char *filepath);

void read_csv(const char *path_file);

#endif