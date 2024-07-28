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


#endif