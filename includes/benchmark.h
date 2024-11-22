#ifndef BENCHMARK_H
#define BENCHMARK_H


#include "util.h"
#include "ll_struct.h"



/*
The point of this program is to create a framework where you can benchmark function.
First, init your benchmark, then load your function and finally, test every loaded functions.
The available function you can pass as parameter are :
- void returning : using load_function_v
- int returning : using load_function_i

With load_function_i you can retrieve the output
*/



typedef void (*func_bench_v)(void*);
typedef int (*func_bench_i)(int*);

typedef struct _operation_evaluation_void {
    func_bench_v function;
    void *args;
    double time;
    double ram;
    double cpu_time;
} opevv;

typedef struct _operation_evaluation_int {
    func_bench_i function;
    void *args_ret;
    void *args;
    double time;
    double ram;
    double cpu_time;
} opevi;


typedef struct _doubly_linked_list_evaluation {
    dll_node *root;                     //the first element of the doubly linked list
    size_t size_dll;                    //size of the dll
    double total_time;                  //total time to execute the whole benchmark
    double total_ram;                   //total ram
    double total_cpu_time;              //total cpu time
    const char *filename_dataset;       //a dataset
    opevv *func_v;                      //array of function returning void
    opevi *func_i;                      //array of function returning int
    int n_func_v;                       //number of v function
    int n_func_i;                       //number of i function
} dll_bench;


void init_bench(dll_bench *bench, const char *filename_dataset);
void load_function_v(dll_bench *bench, func_bench_v function, void *args);
void load_function_i(dll_bench *bench, func_bench_i function, void *args);

void bench_func_v(opevv *func);
void bench_func_i(opevi *func);

void benchmark(dll_bench *bench);


void free_bench(dll_bench *bench);



#endif