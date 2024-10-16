#include "ll_struct.h"



bdll_node *bdll_init(uint64_t value) {
    bdll_node *newNode = (bdll_node*)malloc(sizeof(bdll_node));
    if (newNode == NULL)
        return NULL;
    
    newNode->head = NULL;
    newNode->tail = NULL;
    newNode->branch = NULL;
    newNode->value = value;
    return newNode;
}

int bdll_set_value(bdll_node *node, uint64_t value) {
    if (node == NULL)
        return -1;
    // If negative number you add, messed up your linked list will be. Are allowed positive numbers only !!!
    node->value = value;
    return 1;
}

int bdll_insert_value_head(bdll_node *node, uint64_t value) {
    if (node == NULL) 
        return -1;

    bdll_node *newNode = bdll_init(value);
    
    if (node->head != NULL) {
        node->head->tail = newNode;
        newNode->head = node->head;
    }

    node->head = newNode;
    newNode->tail = node;
    return 1;
}

int bdll_insert_value_tail(bdll_node *node, uint64_t value) {
    if (node == NULL) 
        return -1;

    bdll_node *newNode = bdll_init(value);

    if (node->tail != NULL) {
        node->tail->head = newNode;
        newNode->tail = node->tail;
    }

    node->tail = newNode;
    newNode->head = node;
    return 1;
}

int bdll_insert_value_branch(bdll_node *node, uint64_t value) {
    if (node == NULL)
        return -1;

    bdll_node *newNode = bdll_init(value);
    
    if (node->branch != NULL) {
        node->branch->head = newNode;
        newNode->tail = node->branch;
    }
    
    newNode->head = node;
    node->branch = newNode;
    return 1;
}

int bdll_insert_node_head(bdll_node *node, bdll_node *to_replace) {
    if (node == NULL || to_replace == NULL)
        return -1;

    if (to_replace->head != NULL)
        to_replace->head->tail = to_replace->tail;
    if (to_replace->tail != NULL)
        to_replace->tail->head = to_replace->head;

    if (node->head != NULL) {
        node->head->tail = to_replace;
        to_replace->head = node->head;
    } 
    
    node->head = to_replace;
    to_replace->tail = node;
    return 1;
}

int bdll_insert_node_tail(bdll_node *node, bdll_node *to_replace) {
    if (node == NULL || to_replace == NULL)
        return -1;

    if (to_replace->head != NULL)
        to_replace->head->tail = to_replace->tail;
    if (to_replace->tail != NULL)
        to_replace->tail->head = to_replace->head;

    if (node->tail != NULL) {
        node->tail->head = to_replace;
        to_replace->tail = node->tail;
    }
    
    node->tail = to_replace;
    to_replace->head = node;
    return 1; 
}

int bdll_insert_node_branch(bdll_node *node, bdll_node *to_replace) {
    if (node == NULL || to_replace == NULL)
        return -1;

    if (node->branch != NULL) {
        node->branch->head = to_replace;
        to_replace->tail = node->branch;
    }
    
    to_replace->head = node;
    node->branch = to_replace;
    return 1;
}

int bdll_remove_node(bdll_node *node) {
    if (node == NULL)
        return -1;

    if (node->branch != NULL)
        bdll_free(node->branch);
    
    if (node->head != NULL)
        node->head->tail = node->tail;
    
    if (node->tail != NULL)
        node->tail->head = node->head;

    free(node);
    return 1;
}


int bdll_clear(bdll_node *node) {
    while (node != NULL) {
        if (node->branch != NULL)
            bdll_clear(node->branch);
        node->value = 0;
        node = node->tail;
    }

    return 1;
}

int bdll_free(bdll_node *node) {
    if (node == NULL)
        return -1;

    if (node->head != NULL)
        node->head->tail = NULL;

    bdll_node *next;    
    while (node != NULL) {
        next = node->tail;
        if (node->branch != NULL)
            bdll_free(node->branch);
        
        free(node);
        node = next;
    }
    return 1;
}

int bdll_free_branch(bdll_node *node) {
    if (node == NULL)
        return -1;

    if (node->branch == NULL)
        return -1;

    bdll_free(node->branch);
    node->branch = NULL;
    
    return 1;
}

void bdll_display_tail(bdll_node *node) {
    printf ("%ld", node->value);
}