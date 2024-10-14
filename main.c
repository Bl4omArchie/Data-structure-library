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

    
    //dll_bench my_bench;
    //init_bench(&my_bench, "tests/csv/test_linked_list.csv");
    
    if (run_all())
        printf ("Test completed!\n");
    else
        printf ("Test failed!\n");
    
    return 1;
}