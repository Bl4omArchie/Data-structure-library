#include "ll_tests.h"
#include "util.h"


int dll_routine() {
    dll_node linked_list_test;
    dll_init(&linked_list_test);

    // Insertion routine
    for (int i=0; i<100; i++)
        dll_insert_value_head(&linked_list_test, generate_random_number());

    for (int i=0; i<100; i++)
        dll_insert_value_tail(&linked_list_test, generate_random_number());

    return 1;
}

int main_dll_test() {
    dll_node linked_list;
    dll_init(&linked_list);
    dll_set_value(&linked_list, 0);

    for (uint64_t i=10000000; i>1; i--)
        dll_insert_value_tail(&linked_list, i);

    dll_free(&linked_list);

    return 1;
}