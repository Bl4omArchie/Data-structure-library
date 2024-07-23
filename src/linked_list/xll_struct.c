#include "ll_struct.h"


void init_xll(Node_XLL *node) {
    node->value = 0;
    node->ht_node = NULL;
}

void set_value_xll(Node_XLL *node, uint64_t value) {
    // If negative number you add, messed up your linked list will be. Are allowed positive numbers only !!!
    node->value = value & 0x7FFFFFFFFFFFFFFF;
}

Node_XLL *xor_nodes(Node_XLL* node_a, Node_XLL* node_b) {
    return (Node_XLL*)((uintptr_t)node_a ^ (uintptr_t)node_b);
}

int insert_head_xll(Node_XLL *node, uint64_t value) {
    if (node == NULL)
        return -1;

    Node_XLL *new_node = (Node_XLL*)malloc(sizeof(Node_XLL));
    set_value_xll(new_node, value);
    return insert_node_head_xll(node, new_node);
}

int insert_tail_xll(Node_XLL *node, uint64_t value) {
    if (node == NULL)
        return -1;

    Node_XLL *new_node = (Node_XLL*)malloc(sizeof(Node_XLL));
    set_value_xll(new_node, value);
    return insert_node_tail_xll(node, new_node);
}

int insert_node_head_xll(Node_XLL *node, Node_XLL *to_insert) {
    if (node == NULL || to_insert == NULL)
        return -1;

    to_insert->ht_node = xor_nodes(NULL, node);
    if (node != NULL) {
        Node_XLL *next = xor_nodes(NULL, node->ht_node);
        node->ht_node = xor_nodes(to_insert, next);
    }

    return 1;
}

int insert_node_tail_xll(Node_XLL *node, Node_XLL *to_insert) {
    if (node == NULL || to_insert == NULL)
        return -1;

    to_insert->ht_node = xor_nodes(node, NULL);
    if (node != NULL) {
        Node_XLL *prev = xor_nodes(node->ht_node, NULL);
        node->ht_node = xor_nodes(prev, to_insert);
    }

    return 1;
}

int remove_node_XLL(Node_XLL *node) {
    if (node == NULL)
        return -1;

    Node_XLL *prev = xor_nodes(node->ht_node, NULL);
    Node_XLL *next = xor_nodes(NULL, node->ht_node);

    if (prev != NULL)
        prev->ht_node = xor_nodes(xor_nodes(prev->ht_node, node), next);
    
    if (next != NULL)
        next->ht_node = xor_nodes(prev, xor_nodes(next->ht_node, node));

    free(node);
    return 1;
}

int clear_xll_tail(Node_XLL *node) {
    while (node != NULL) {
        Node_XLL *next = xor_nodes(NULL, node->ht_node);
        node->value = 0;
        node = next;
    }
    return 1;
}

int free_tail_xll(Node_XLL *node) {

}

void display_xll(Node_XLL *node) {
    Node_XLL *prev = NULL;
    Node_XLL *curr = node;
    Node_XLL *next;

    while (curr != NULL) {
        printf("%ld", curr->value);
        next = xor_nodes(prev, curr->ht_node);
        prev = curr;
        curr = next;
    }
    printf("\n");
}