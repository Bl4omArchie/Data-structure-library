#include "ll_tests.h"
#include "util.h"



void test_bdll_init() {
    bdll_node *node = bdll_init(65537);
    assert(node->head == NULL);
    assert(node->tail == NULL);
    assert(node->branch == NULL);
    assert(node->value == 65537);
}

void test_bdll_set_value() {
    bdll_node *node = bdll_init(65537);
    assert(node->value == 65537);
    
    bdll_set_value(node, 0);
    assert(node->value == 0);
    
    bdll_set_value(node, UINT64_MAX+1);
    assert(node->value == 0);
}

void test_bdll_insert_value_head() {
    bdll_node *node = bdll_init(5);
    
    assert(bdll_insert_value_head(node, 65537) == 1);
    assert(node->head->value == 65537);
    
    assert(bdll_insert_value_head(node, 20) == 1);
    assert(node->head->value == 20);
}

void test_bdll_insert_value_tail() {
    bdll_node *node = bdll_init(5);
    
    assert(bdll_insert_value_tail(node, 65537) == 1);
    assert(node->tail->value == 65537);
    
    assert(bdll_insert_value_tail(node, 20) == 1);
    assert(node->tail->value == 20);
}

void test_bdll_insert_value_branch() {

}

void test_bdll_insert_node_head() {
    bdll_node *node1 = bdll_init(10);
    bdll_node *node2 = bdll_init(65537);
    
    assert(bdll_insert_node_head(node1, node2) == 1);
    assert(node1->head->value == 65537);
}

void test_bdll_insert_node_tail() {
    bdll_node *node1 = bdll_init(10);
    bdll_node *node2 = bdll_init(65537);

    assert(bdll_insert_node_tail(node1, node2) == 1);
    assert(node1->tail->value == 65537);
}

void test_bdll_insert_node_branch() {

}

void test_bdll_remove_node() {
    bdll_node *node1 = bdll_init(128);

    bdll_insert_value_tail(node1, 256);
    bdll_insert_value_tail(node1, 512);
    
    assert(bdll_remove_node(node1->tail) == 1);
    assert(node1->tail->value == 256);
}

void test_bdll_remove_branch() {

}

void test_bdll_clear() {
    bdll_node *node = bdll_init(65537);

    bdll_insert_value_head(node, 65537);
    bdll_insert_value_head(node, 20);

    assert(bdll_clear(node) == 1);
    assert(node->value == 0);
    assert(node->head->value == 0);
    assert(node->head->head->value == 0);
}

void test_bdll_clear_branch() {

}

void test_bdll_free() {
    bdll_node *node = bdll_init(65537);
    
    bdll_insert_value_tail(node, 20);
    bdll_insert_value_tail(node, 10);
    
    assert(bdll_free(node) == 1);
}

void test_bdll_free_branch() {

} 

int run_all_bdll() {
    test_bdll_init();
    test_bdll_set_value();
    test_bdll_insert_value_head();
    test_bdll_insert_value_tail();
    test_bdll_insert_value_branch();
    test_bdll_insert_node_head();
    test_bdll_insert_node_tail();
    test_bdll_insert_node_branch();
    //test_bdll_remove_node();
    //test_bdll_clear();
    //test_bdll_clear_branch();
    //test_bdll_free();
    //test_bdll_free_branch();

    return 1;
}