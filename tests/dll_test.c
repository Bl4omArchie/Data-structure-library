#include "ll_tests.h"
#include "util.h"



void test_memory(void *args) {
    dll_node node;
    dll_init(&node);

    for (int i=0; i<175000000; i++)
        dll_insert_value_tail(&node, generate_random_number());
}