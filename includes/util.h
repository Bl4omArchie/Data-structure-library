#ifndef UTIL_H
#define UTIL_H


#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



// ********** random.c **********
uint64_t generate_random_number();



// ********** hardware_info.c **********
long get_available_ram();
void display_specifications();



// ********** arithmetic.asm **********
extern uint64_t add_binary_optimized(uint64_t a, uint64_t b, int c);
extern uint64_t sub_binary_optimized(uint64_t a, uint64_t b, int c);


#endif