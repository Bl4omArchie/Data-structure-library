#include "ll_struct.h" 
#include "ll_tests.h" 
#include "util.h"




int main() {
    
    display_specifications();
    
    if (main_bdll_test())
        printf ("End of DLL the test");

    return 1;
}