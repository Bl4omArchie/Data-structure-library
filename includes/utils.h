#ifndef UTIL_H
#define UTIL_H


#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



// ********** random.c **********
uint64_t generate_random_number();


// ********** read_csv.c **********
void read_csv(const char *path_file);



#endif