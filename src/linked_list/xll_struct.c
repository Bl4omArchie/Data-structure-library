#include "ll_struct.h"


void init_xll(Node_XLL *node) {
    node->ht_node = NULL;
    node->value = 0;
}

void set_value_xll(Node_XLL *node, uint64_t value) {
    // If negative number you add, messed up your linked list will be. Are allowed positive numbers only !!!
    node->value = value & 0x7FFFFFFFFFFFFFFF;
}

Node_XLL *xor_nodes(Node_XLL* node_a, Node_XLL* node_b) {
    return (Node_XLL*)((uintptr_t)(node_a) ^ (uintptr_t)(node_b));    
}


int insert_node_head_xll(Node_XLL *node, Node_XLL *to_insert) {
    if (node->ht_node == NULL)
        return -1;
}

int insert_node_tail_xll(Node_XLL *node, Node_XLL *to_insert) {

}

int insert_value_head_xll(Node_XLL *node, uint64_t value) {
    
}
int insert_value_tail_xll(Node_XLL *node, uint64_t value) {
    
}

int remove_Node_XLL(Node_XLL *node) {
    
}

int clear_xll(Node_XLL *node) {
    
}
int clear_head_xll(Node_XLL *node) {
    
}
int clear_tail_xll(Node_XLL *node) {
    
}

int free_xll(Node_XLL *node) {
    
}
int free_head_xll(Node_XLL *node) {
    
}
int free_tail_xll(Node_XLL *node) {
    
}

void display_xll(Node_XLL node) {
    
}