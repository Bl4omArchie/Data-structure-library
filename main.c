#include "ll_struct.h" 
#include "ll_tests.h" 
#include "util.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>


#include <cpuinfo.h>


int main() {

    print_cpu_details();
    display_specifications();
    benchmark(test_memory, NULL);

    return 1;
}