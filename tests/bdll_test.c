#include "ll_tests.h"
#include "util.h"



void test_bdll_init() {
    bdll_node *node1 = bdll_init(65537);
    assert(node1->head == NULL);
    assert(node1->tail == NULL);
    assert(node1->branch == NULL);
    assert(node1->value == 65537);

    // Free before exiting
    bdll_free(node1);  
}

void test_bdll_set_value() {
    bdll_node *node1 = bdll_init(65537);
    assert(node1->value == 65537);
    
    bdll_set_value(node1, 0);
    assert(node1->value == 0);
    
    bdll_set_value(node1, UINT64_MAX+1);
    assert(node1->value == 0);

    // Free before exiting
    bdll_free(node1);  
}

void test_bdll_insert_value_head() {
    bdll_node *node1 = bdll_init(5);
    
    assert(bdll_insert_value_head(node1, 65537) == 1);
    assert(node1->head->value == 65537);
    
    assert(bdll_insert_value_head(node1, 20) == 1);
    assert(node1->head->value == 20);

    // NULL test
    assert(bdll_insert_value_head(NULL, 0) == -1);
    // Free before exiting
    bdll_free(node1);  
}

void test_bdll_insert_value_tail() {
    bdll_node *node1 = bdll_init(5);
    
    assert(bdll_insert_value_tail(node1, 65537) == 1);
    assert(node1->tail->value == 65537);
    
    assert(bdll_insert_value_tail(node1, 20) == 1);
    assert(node1->tail->value == 20);

    // NULL test
    assert(bdll_insert_value_tail(NULL, 0) == -1);
    // Free before exiting
    bdll_free(node1);  
}

void test_bdll_insert_value_branch() {
    bdll_node *node1 = bdll_init(10);
    
    assert(bdll_insert_value_branch(node1, 65537) == 1);
    assert(node1->branch->value == 65537);
    
    assert(bdll_insert_value_tail(node1, 20) == 1);
    assert(node1->tail->value == 20);

    // NULL test
    assert(bdll_insert_value_branch(NULL, 0) == -1);
    // Free before exiting
    bdll_free(node1);
}

void test_bdll_insert_node_head() {
    bdll_node *node1 = bdll_init(10);
    bdll_node *node2 = bdll_init(65537);
    
    assert(bdll_insert_node_head(node1, node2) == 1);
    assert(node1->head->value == 65537);

    // NULL test
    assert(bdll_insert_node_head(NULL, NULL) == -1);
    assert(bdll_insert_node_head(NULL, node1) == -1);
    assert(bdll_insert_node_head(node1, NULL) == -1);
    // Free before exiting
    bdll_free(node1);
}

void test_bdll_insert_node_tail() {
    bdll_node *node1 = bdll_init(10);
    bdll_node *node2 = bdll_init(65537);

    assert(bdll_insert_node_tail(node1, node2) == 1);
    assert(node1->tail->value == 65537);

    // NULL test
    assert(bdll_insert_node_tail(NULL, NULL) == -1);
    assert(bdll_insert_node_tail(NULL, node1) == -1);
    assert(bdll_insert_node_tail(node1, NULL) == -1);
    // Free before exiting
    bdll_free(node1);
}

void test_bdll_insert_node_branch() {
    bdll_node *node1 = bdll_init(10);
    bdll_node *node2 = bdll_init(65537);

    assert(bdll_insert_node_branch(node1, node2) == 1);
    assert(node1->branch->value == 65537);

    // NULL test
    assert(bdll_insert_node_branch(NULL, NULL) == -1);
    assert(bdll_insert_node_branch(NULL, node1) == -1);
    assert(bdll_insert_node_branch(node1, NULL) == -1);
    // Free before exiting
    bdll_free(node1);
}

void test_bdll_remove_node() {
    bdll_node *node1 = bdll_init(128);

    bdll_insert_value_tail(node1, 256);
    bdll_insert_value_tail(node1, 512);
    
    assert(bdll_remove_node(node1->tail) == 1);
    assert(node1->tail->value == 256);

    // NULL test
    assert(bdll_remove_node(NULL) == -1);
    // Free before exiting
    bdll_free(node1);
}

void test_bdll_clear() {
    bdll_node *node1 = bdll_init(1);

    bdll_insert_value_tail(node1, 30);
    bdll_insert_value_tail(node1, 20);

    assert(bdll_clear(node1) == 1);
    assert(node1->value == 0);
    assert(node1->tail->value == 0);
    assert(node1->tail->tail->value == 0);


    bdll_insert_value_tail(node1, 30);
    bdll_insert_value_tail(node1, 20);
    bdll_insert_value_branch(node1->tail, 10); 

    assert(bdll_clear(node1) == 1);
    assert(node1->tail->branch->value == 0);

    // NULL test : this one is 
    assert(bdll_clear(NULL) == 1);
    // Free before exiting
    bdll_free(node1);
}

void test_bdll_free() {
    bdll_node *node1 = bdll_init(65537);
    bdll_insert_value_tail(node1, 20);
    bdll_insert_value_tail(node1, 10);
    
    assert(bdll_free(node1) == 1);

    node1 = bdll_init(65537);
    bdll_insert_value_tail(node1, 20);
    bdll_insert_value_tail(node1, 10);
    bdll_insert_value_branch(node1->tail, 5);

    assert(bdll_free(node1) == 1);

    // NULL test
    assert(bdll_free(NULL) == -1);
}

void test_bdll_free_branch() {
    bdll_node *node1 = bdll_init(65537);
    bdll_insert_value_tail(node1, 20);
    bdll_insert_value_tail(node1, 10);
    
    assert(bdll_free_branch(node1) == -1);

    node1 = bdll_init(65537);
    bdll_insert_value_tail(node1, 30);
    bdll_insert_value_branch(node1, 10);
    bdll_insert_value_tail(node1->branch, 20);
    bdll_insert_value_branch(node1->branch->tail, 5);

    assert(bdll_free_branch(node1) == 1);

    // NULL test
    assert(bdll_free_branch(NULL) == -1);
} 

int run_all_bdll() {
    test_bdll_init();
    test_bdll_free();
    test_bdll_free_branch();
    test_bdll_set_value();
    test_bdll_insert_value_head();
    test_bdll_insert_value_tail();
    test_bdll_insert_value_branch();
    test_bdll_insert_node_head();
    test_bdll_insert_node_tail();
    test_bdll_insert_node_branch();
    test_bdll_remove_node();
    test_bdll_clear();

    return 1;
}