#include "includes/ll_struct.h" 
#include "includes/ll_tests.h" 




int main() {
    
    display_specifications();
    
    if (main_dll_test())
        printf ("End of DLL the test");

    return 1;
}