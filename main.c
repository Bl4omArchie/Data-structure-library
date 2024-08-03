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
    
    display_specifications();
    
    benchmark(test_memory, NULL);

    return 1;
}