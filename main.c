#include "benchmark.h"
#include "ll_struct.h" 
#include "bignum.h"
#include "ll_tests.h" 
#include "util.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>



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

    //print_cpu_details();
    display_specifications();

    //const char *filename = "csv/test_linked_list.csv";
    //read_csv(filename);

    
    bench *my_bench = bench_dll_insertion();
    printf ("%.4f seconds\n", my_bench->time);
    free(my_bench);
    
    /*
    if (run_all_dll())
        printf ("Test DLL completed!\n");
    else
        printf ("Test DLL failed!\n");

    if (run_all_bdll())
        printf ("Test BDLL completed!\n");
    else
        printf ("Test BDLL failed!\n");
    */
    
    return 1;
}