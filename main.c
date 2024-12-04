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

void simple_benchmark() {
    benchmark *instance = start_benchmark();
    
    display_specifications(instance->hardware_profile);
    init_session(instance->arr_sessions[0], )

    for (int r=0; r<round; r++) {
        dll_node *node = new_dll(50);
        for (int i=0; i<iter; i++)
            dll_insert_value_head(node, generate_random_number());
        dll_free(node);
    }
    
    end_benchmark(instance);
}


int main() {
    uint64_t a, b, c = 0, 15, 10;

    //printf ("%ld\n", add_binary_optimized(10, 5));
    //printf ("%ld\n", sub_binary_optimized(10, 5));

    simple_benchmark();

    return 1;
}