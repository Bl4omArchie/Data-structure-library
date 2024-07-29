#include "ll_struct.h"



void bdll_init(bdll_node *node) {
    node->head = NULL;
    node->tail = NULL;
    node->branch = NULL;
    node->value = 0;
}

void bdll_set_value(bdll_node *node, uint64_t value) {
    // If negative number you add, messed up your linked list will be. Are allowed positive numbers only !!!
    node->value = value & 0x7FFFFFFFFFFFFFFF;
}


int bdll_insert_branch(bdll_node *node, uint64_t value) {
    if (node == NULL)
        return -1;

    bdll_node *newNode = (bdll_node*)malloc(sizeof(bdll_node));
    bdll_init(newNode);
    bdll_set_value(newNode, value);
    
    if (node->branch != NULL) {
        node->branch->head = newNode;
        newNode->tail = node->branch;
    }
    else
        newNode->tail = node->tail;
    
    node->branch = newNode;

    return 1;
}

int bdll_insert_value_head(bdll_node *node, uint64_t value) {
    return 1;
}

int bdll_insert_value_tail(bdll_node *node, uint64_t value) {
    return 1;
}


int bdll_insert_node_branch(bdll_node *node, bdll_node *to_replace) {
    return 1;
}

int bdll_insert_node_head(bdll_node *node, bdll_node *to_replace) {
    return 1;
}

int bdll_insert_node_tail(bdll_node *node, bdll_node *to_replace) {
    return 1;
}


int bdll_remove_node(bdll_node *node) {
    return 1;
}

int bdll_remove_branch(bdll_node *node) {
    return 1;
}


int bdll_clear(bdll_node *node) {
    return 1;
}

int bdll_clear_branch(bdll_node *node) {
    return 1;
}

int bdll_clear_head(bdll_node *node) {
    return 1;
}

int bdll_clear_tail(bdll_node *node) {

    return 1;
}

int bdll_free(bdll_node *node) {
    return 1;
}

int bdll_free_branch(bdll_node *node) {
    return 1;
}

int bdll_free_head(bdll_node *node) {
    return 1;
}

int bdll_free_tail(bdll_node *node) {
    return 1;
}

void bdll_display_tail(bdll_node *node) {
    printf ("%ld", node->value);
}