#include "ll_struct.h"


void xll_init(xll_node *node) {
    node->value = 0;
    node->ht_node = NULL;
}

void xll_set_value(xll_node *node, uint64_t value) {
    // If negative number you add, messed up your linked list will be. Are allowed positive numbers only !!!
    node->value = value & 0x7FFFFFFFFFFFFFFF;
}

xll_node *xll_xor_nodes(xll_node* node_a, xll_node* node_b) {
    return (xll_node*)((uintptr_t)node_a ^ (uintptr_t)node_b);
}

int xll_insert_value_head(xll_node *node, uint64_t value) {
    if (node == NULL)
        return -1;

    xll_node *new_node = (xll_node*)malloc(sizeof(xll_node));
    xll_set_value(new_node, value);
    return xll_insert_node_head(node, new_node);
}

int xll_insert_value_tail(xll_node *node, uint64_t value) {
    if (node == NULL)
        return -1;

    xll_node *new_node = (xll_node*)malloc(sizeof(xll_node));
    xll_set_value(new_node, value);
    return xll_insert_node_tail(node, new_node);
}

int xll_insert_node_head(xll_node *node, xll_node *to_insert) {
    if (node == NULL || to_insert == NULL)
        return -1;

    to_insert->ht_node = xll_xor_nodes(NULL, node);
    if (node != NULL) {
        xll_node *next = xll_xor_nodes(NULL, node->ht_node);
        node->ht_node = xll_xor_nodes(to_insert, next);
    }

    return 1;
}

int xll_insert_node_tail(xll_node *node, xll_node *to_insert) {
    if (node == NULL || to_insert == NULL)
        return -1;

    to_insert->ht_node = xll_xor_nodes(node, NULL);
    if (node != NULL) {
        xll_node *prev = xll_xor_nodes(node->ht_node, NULL);
        node->ht_node = xll_xor_nodes(prev, to_insert);
    }

    return 1;
}

int xll_remove_node(xll_node *node) {
    if (node == NULL)
        return -1;

    xll_node *prev = xll_xor_nodes(node->ht_node, NULL);
    xll_node *next = xll_xor_nodes(NULL, node->ht_node);

    if (prev != NULL)
        prev->ht_node = xll_xor_nodes(xll_xor_nodes(prev->ht_node, node), next);
    
    if (next != NULL)
        next->ht_node = xll_xor_nodes(prev, xll_xor_nodes(next->ht_node, node));

    free(node);
    return 1;
}

int xll_clear_tail(xll_node *node) {
    while (node != NULL) {
        xll_node *next = xll_xor_nodes(NULL, node->ht_node);
        node->value = 0;
        node = next;
    }
    return 1;
}

int xll_free_tail(xll_node *node) {
    return 1;
}

void xll_display(xll_node *node) {
    xll_node *prev = NULL;
    xll_node *next;

    while (node != NULL) {
        printf("%ld", node->value);
        next = xll_xor_nodes(prev, node->ht_node);
        prev = node;
        node = next;
    }
    printf("\n");
}