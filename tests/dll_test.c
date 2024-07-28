#include "ll_tests.h"
#include "util.h"


int dll_routine() {
    Node_DLL linked_list_test;
    init_dll(&linked_list_test);

    // Insertion routine
    for (int i=0; i<100; i++) {
        insert_head_dll(&linked_list_test, generate_random_number());
    }

    for (int i=0; i<100; i++) {
        insert_tail_dll(&linked_list_test, generate_random_number());
    }

    return 1;
}

int main_dll_test() {
    Node_DLL linked_list;
    init_dll(&linked_list);
    set_value_dll(&linked_list, 0);

    for (uint64_t i=10000000; i>1; i--)
        insert_tail_dll(&linked_list, i);

    free_dll(&linked_list);

    return 1;
}