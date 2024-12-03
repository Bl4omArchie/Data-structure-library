#include "benchmark.h"
#include "ll_struct.h" 
#include "ll_tests.h"
#include "bignum.h"
#include "utils.h"


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>




int test_ll() {
    if (run_all_dll())
        printf ("Test DLL completed!\n");
    else
        printf ("Test DLL failed!\n");

    if (run_all_bdll())
        printf ("Test BDLL completed!\n");
    else
        printf ("Test BDLL failed!\n");
    return 1;
}


int main() {
    uint64_t a, b, c;
    a = 0;
    b = 10;
    c = 5;

    printf ("%ld\n", add_binary_optimized(10, 5));
    printf ("%ld\n", sub_binary_optimized(10, 5));
    /*
    benchmark *instance = start_benchmark();
    display_specifications(&instance->hardware_profile);
    
    end_benchmark(instance);
    */
    return 1;
}