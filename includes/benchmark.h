#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

#include "file_struct.h"


// I'm trying to make a small framework for benchmarking
typedef void (*bench_func_t)(int argc, char *argv[]);

struct Benchmark {
    double recorded_time;
    bench_func_t func;
};

void file_list(uint64_t n);

void add_benchmark(struct Benchmark *evaluation, bench_func_t *bench_to_insert);
void start_benchmark(struct Benchmark *evaluation, int argc, char *argv[]);
void benchmark_insert(uint64_t num_element);
void benchmark_remove(DoublyLinkedList *to_remove);
void benchmark_lookup_element(DoublyLinkedList *to_find);

#endif