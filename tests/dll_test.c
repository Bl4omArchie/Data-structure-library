#include "ll_tests.h"
#include "util.h"



void test_dll_init() {
    dll_node *node1 = dll_init(65537);
    assert(node1->head == NULL);
    assert(node1->tail == NULL);
    assert(node1->value == 65537);
    
    // Free before exiting
    dll_free(node1);  
}

void test_dll_set_value() {
    dll_node *node1 = dll_init(65537);
    assert(node1->value == 65537);
    
    dll_set_value(node1, 0);
    assert(node1->value == 0);
    
    dll_set_value(node1, UINT64_MAX+1);
    assert(node1->value == 0);

    //NULL test
    assert(dll_set_value(NULL, 0) == -1);

    // Free before exiting
    dll_free(node1);
}

void test_dll_insert_value_head() {
    dll_node *node1 = dll_init(5);
    
    assert(dll_insert_value_head(node1, 65537) == 1);
    assert(node1->head->value == 65537);
    
    assert(dll_insert_value_head(node1, 20) == 1);
    assert(node1->head->value == 20);

    //NULL test
    assert(dll_insert_value_head(NULL, 0) == -1);

    // Free before exiting
    dll_free(node1);
}

void test_dll_insert_value_tail() {
    dll_node *node1 = dll_init(5);
    
    assert(dll_insert_value_tail(node1, 65537) == 1);
    assert(node1->tail->value == 65537);
    
    assert(dll_insert_value_tail(node1, 20) == 1);
    assert(node1->tail->value == 20);

    //NULL test
    assert(dll_insert_value_tail(NULL, 0) == -1);

    // Free before exiting
    dll_free(node1);
}

void test_dll_insert_node_head() {
    dll_node *node1 = dll_init(10);
    dll_node *node2 = dll_init(65537);
    
    assert(dll_insert_node_head(node1, node2) == 1);
    assert(node1->head->value == 65537);
    
    //NULL test
    assert(dll_insert_node_head(NULL, NULL) == -1);
    assert(dll_insert_node_head(node1, NULL) == -1);
    assert(dll_insert_node_head(NULL, node1) == -1);
    
    // Free before exiting
    dll_free(node1);
}

void test_dll_insert_node_tail() {
    dll_node *node1 = dll_init(10);
    dll_node *node2 = dll_init(65537);

    assert(dll_insert_node_tail(node1, node2) == 1);
    assert(node1->tail->value == 65537);

    //NULL test
    assert(dll_insert_node_tail(NULL, NULL) == -1);
    assert(dll_insert_node_tail(NULL, node1) == -1);
    assert(dll_insert_node_tail(node1, NULL) == -1);

    // Free before exiting
    dll_free(node1);
}

void test_dll_remove_node() {
    dll_node *node1 = dll_init(128);

    dll_insert_value_tail(node1, 256);
    dll_insert_value_tail(node1, 512);
    
    assert(dll_remove_node(node1->tail) == 1);
    assert(node1->tail->value == 256);
    assert(dll_insert_value_tail(NULL, 10) == -1);

    // Free before exiting
    dll_free(node1);
}

void test_dll_clear() {
    dll_node *node1 = dll_init(65537);

    dll_insert_value_head(node1, 65537);
    dll_insert_value_head(node1, 20);

    assert(dll_clear(node1) == 1);
    assert(node1->value == 0);
    assert(node1->head->value == 0);
    assert(node1->head->head->value == 0);

    //NULL test
    assert(dll_insert_value_head(NULL, 10) == -1);

    // Free before exiting
    dll_free(node1);
}

void test_dll_free() {
    dll_node *node1 = dll_init(65537);
    
    dll_insert_value_tail(node1, 20);
    dll_insert_value_tail(node1, 10);
    assert(dll_free(node1) == 1);

    //NULL test
    assert(dll_free(NULL) == -1);
}

int run_all_dll() {
    test_dll_free();
    test_dll_init();
    test_dll_set_value();
    test_dll_insert_value_head();
    test_dll_insert_value_tail();
    test_dll_insert_node_head();
    test_dll_insert_node_tail();
    test_dll_remove_node();
    test_dll_clear();

    return 1;
}