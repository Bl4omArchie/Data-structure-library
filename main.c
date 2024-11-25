#include "benchmark.h"
#include "ll_struct.h" 
#include "ll_tests.h"
#include "bignum.h"
#include "util.h"


#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>



int test_ll() {
    if (run_all_dll())
        printf ("Test DLL completed!\n");
    else
        printf ("Test DLL failed!\n");

    if (run_all_bdll())
        printf ("Test BDLL completed!\n");
    else
        printf ("Test BDLL failed!\n");
}

int main() {
    display_specifications();

    

    
    bench *my_bench = bench_dll_insertion_tail(50, 5000000);
    printf ("%.4f seconds\n", my_bench->time);
    free(my_bench);
    
    return 1;
}