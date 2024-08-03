#include "ll_tests.h"
#include "util.h"


#define K_100 100000   // 100_000
#define M_1 1000000     // 1_000_000 millions
#define M_10 10000000   // 10_000_000 millions
#define M_100 100000000 // 100_000_000 millions


// In scenario one, a dll is initialized and a bunch of data in inserted in head then cleared. Then the same for tail and finally we refill head and tail and free the whole linked list 
void scenario_one(void *args) {
    dll_node linked_list_test;
    dll_init(&linked_list_test);

    for (int i=0; i<M_10; i++)
        dll_insert_value_head(&linked_list_test, generate_random_number());

    dll_clear_head(&linked_list_test);


    for (int i=0; i<M_10; i++)
        dll_insert_value_tail(&linked_list_test, generate_random_number()); 

    dll_clear_tail(&linked_list_test);


    for (int i=0; i<M_10; i++)
        dll_insert_value_head(&linked_list_test, generate_random_number()); 
    for (int i=0; i<M_10; i++)
        dll_insert_value_tail(&linked_list_test, generate_random_number()); 
    dll_free(&linked_list_test);
}

// Same scenario but insert node instead of values
void scenario_two(void *args) {
    dll_node head_element;
    dll_node next_element;
    dll_init(&head_element);

    for (int i=0; i<M_10; i++) {
        dll_init(&next_element);
        dll_set_value(&next_element, generate_random_number());
        dll_insert_node_tail(&head_element, &next_element);
    }

    dll_clear_tail(&head_element);

    /*
    for (int i=0; i<M_10; i++) {
        dll_init(&next_element);
        dll_set_value(&next_element, generate_random_number());
        dll_insert_node_head(&head_element, &next_element);
    }

    dll_clear_head(&head_element);


    for (int i=0; i<M_10; i++) {
        dll_init(&next_element);
        dll_set_value(&next_element, generate_random_number());
        dll_insert_node_head(&head_element, &next_element);
    }
    for (int i=0; i<M_10; i++) {
        dll_init(&next_element);
        dll_set_value(&next_element, generate_random_number());
        dll_insert_node_tail(&head_element, &next_element);
    }
    */

    dll_free(&head_element);
}


void test_memory(void *args) {
    dll_node node;
    dll_init(&node);

    for (int i=0; i<175000000; i++)
        dll_insert_value_tail(&node, 10);
}