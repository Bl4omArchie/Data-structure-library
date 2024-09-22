#ifndef UTIL_H
#define UTIL_H


#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



typedef void (*func_bench)(void*);


// ********** random.c **********
uint64_t generate_random_number();



// ********** hardware_info.c **********

int get_procs_nb();
double get_ram();
double get_available_ram();
void print_cpu_details();
void display_specifications();



// ********** benchmark.c **********
void benchmark(func_bench to_bench, void *args);



// ********** arithmetic.asm **********
extern uint64_t add_binary_optimized(uint64_t a, uint64_t b, int c);
extern uint64_t sub_binary_optimized(uint64_t a, uint64_t b, int c);


#endif