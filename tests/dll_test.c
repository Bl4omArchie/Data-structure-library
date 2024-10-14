#include "ll_tests.h"
#include "util.h"



void test_dll_init() {
    dll_node node;
    dll_init(&node, 65537);
    assert(node.head == NULL);
    assert(node.tail == NULL);
    assert(node.value == 65537);
}

void test_dll_set_value() {
    dll_node node;
    dll_init(&node, 65537);
    assert(node.value == 65537);
    
    dll_set_value(&node, 0);
    assert(node.value == 0);
    
    dll_set_value(&node, UINT64_MAX);
    assert(node.value == UINT64_MAX);
}

void test_dll_insert_value_head() {
    dll_node node;
    dll_init(&node, 5);
    
    assert(dll_insert_value_head(&node, 65537) == 1);
    assert(node.head->value == 65537);
    
    assert(dll_insert_value_head(&node, 20) == 1);
    assert(node.head->value == 20);
}

void test_dll_insert_value_tail() {
    dll_node node;
    dll_init(&node, 5);
    
    assert(dll_insert_value_tail(&node, 65537) == 1);
    assert(node.tail->value == 65537);
    
    assert(dll_insert_value_tail(&node, 20) == 1);
    assert(node.tail->value == 20);
}

void test_dll_insert_node_head() {
    dll_node node1, node2;
    dll_init(&node1, 10);
    dll_init(&node2, 65537);
    assert(dll_insert_node_head(&node1, &node2) == 1);
    assert(node1.head->value == 65537);
}

void test_dll_insert_node_tail() {
    dll_node node1, node2;
    dll_init(&node1, 10);
    dll_init(&node2, 65537);
    assert(dll_insert_node_tail(&node1, &node2) == 1);
    assert(node1.tail->value == 65537);
}

void test_dll_remove_node() {
    dll_node node;
    dll_init(&node, 65537);
    dll_insert_value_head(&node, 65537);
    assert(dll_remove_node(&node) == 1);
    assert(node.head == NULL);
}

void test_dll_clear() {
    dll_node node;
    dll_init(&node, 65537);
    dll_insert_value_head(&node, 65537);
    dll_insert_value_head(&node, 20);
    assert(dll_clear(&node) == 1);
    assert(node.head == NULL);
}

void test_dll_free() {
    dll_node node;
    dll_init(&node, 65537);
    dll_insert_value_head(&node, 65537);
    dll_insert_value_head(&node, 20);
    assert(dll_free(&node) == 1);
    assert(node.head == NULL);
}

int run_all() {
    test_dll_init();
    test_dll_set_value();
    test_dll_insert_value_head();
    test_dll_insert_value_tail();
    test_dll_insert_node_head();
    test_dll_insert_node_tail();
    //test_dll_remove_node();
    //test_dll_clear();
    //test_dll_free();

    return 1;
}