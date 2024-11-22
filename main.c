#include "benchmark.h"
#include "ll_struct.h" 
#include "ll_tests.h" 
#include "util.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>



int main() {

    //print_cpu_details();
    display_specifications();

    //const char *filename = "csv/test_linked_list.csv";
    //read_csv(filename);

    dll_node *new_node = new_dll(0);
    
    dll_bench my_bench;
    init_bench(&my_bench, "tests/csv/test_linked_list.csv");
    load_function_i(&my_bench, dll_insert_value_head, new_node, 50);
    benchmark(&my_bench);
    
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