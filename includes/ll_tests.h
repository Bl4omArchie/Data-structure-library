#ifndef LL_TESTS_H
#define LL_TESTS_H


#include "ll_struct.h"

#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>


// ********* DLL tests ********* 
void test_dll_init();
void test_dll_set_value();
void test_dll_insert_value_head();
void test_dll_insert_value_tail();
void test_dll_insert_node_head();
void test_dll_insert_node_tail();
void test_dll_remove_node();
void test_dll_clear();
void test_dll_free();
int run_all();


// ********* BDLL tests *********
int bdll_routine();
int main_bdll_test();





#endif