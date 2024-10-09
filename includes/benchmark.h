#ifndef BENCHMARK_H
#define BENCHMARK_H


#include "util.h"
#include "ll_struct.h"



typedef void (*func_bench)(void*);

typedef struct _operation_evaluation {
    func_bench to_bench;
    void *args;
    double time;
    double ram;
    double cpu_time;
} op_bench;


typedef struct _doubly_linked_list_evaluation {
    dll_node *root;
    size_t size_dll;
    double total_time;
    double total_ram;
    double total_cpu_time;
    op_bench *functions;
    int size_functions;
} dll_bench;


void init_bench(dll_bench *bench);
void benchmark(dll_bench *bench);
void benchmark_function(op_bench *func);
void load_function(dll_bench *bench, func_bench to_bench, void *args);
void free_bench(dll_bench *bench);




#endif