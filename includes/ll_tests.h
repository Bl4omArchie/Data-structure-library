#ifndef LL_TESTS_H
#define LL_TESTS_H


#include "ll_struct.h"


// ********* DLL tests ********* 
int dll_routine();
int main_dll_test();


// ********* BDLL tests *********
int bdll_routine();
int main_bdll_test();


// ********* Util *********
uint64_t generate_random_number();
uint64_t get_maximal_element();


#endif