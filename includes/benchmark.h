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
    op_bench *all_functions[25];
    size_t number_functions;
} dll_bench;


void benchmark(dll_bench *bench);
void benchmark_function(op_bench *func);




#endif