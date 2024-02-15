#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

#include "file_struct.h"



typedef void (*bench_func_t)(int argc, char *argv[]);


void benchmark(bench_func_t func, int iter, int argc, char *argv[]);
uint64_t generateRandom64BitNumber();

void benchmark_file_list(uint64_t n);
void benchmark_insert(uint64_t num_element);
void benchmark_remove(DoublyLinkedList *to_remove);
void benchmark_lookup_element(DoublyLinkedList *to_find);

#endif