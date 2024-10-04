#include "ll_struct.h"



void dll_init(dll_node *node) {
    node->head = NULL;
    node->tail = NULL;
    node->value = 0;
}

void dll_set_value(dll_node *node, uint64_t value) {
    // If negative number you add, messed up your linked list will be. Are allowed positive numbers only !!!
    node->value = value & 0x7FFFFFFFFFFFFFFF;
}
    

int dll_insert_value_head(dll_node *node, uint64_t value) {
    if (node == NULL) 
        return -1;

    dll_node *newNode = (dll_node*)malloc(sizeof(dll_node));
    dll_init(newNode);
    dll_set_value(newNode, value);
    
    if (node->head != NULL) {
        node->head->tail = newNode;
        newNode->head = node->head;
    }

    node->head = newNode;
    newNode->tail = node;
    return 1;
}


int dll_insert_value_tail(dll_node *node, uint64_t value) {
    if (node == NULL) 
        return -1;

    dll_node *newNode = (dll_node*)malloc(sizeof(dll_node));
    dll_init(newNode);
    dll_set_value(newNode, value);

    if (node->tail != NULL) {
        node->tail->head = newNode;
        newNode->tail = node->tail;
    }

    node->tail = newNode;
    newNode->head = node;
    return 1;
}

int dll_insert_node_head(dll_node *node, dll_node *to_replace) {
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


int dll_insert_node_tail(dll_node *node, dll_node *to_replace) {
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


int dll_remove_node(dll_node *node) {
    if (node == NULL)
        return -1;
    
    if (node->head != NULL)
        node->head->tail = node->tail;
    
    if (node->tail != NULL)
        node->tail->head = node->head;

    free(node);
    return 1;
}


int dll_clear(dll_node *node) {
    while (node != NULL) {
        node->value = 0;
        node = node->head;
    }
    return 1;
}


int dll_free(dll_node *node) {
    node->head->tail = NULL;
    dll_node *next;

    while (node != NULL) {
        next = node->tail;
        free(node);
        node = next;
    }
    return 1;
}


void dll_display_tail(dll_node *node) {
    dll_node *next;

    while (node != NULL) {
        printf ("%ld", node->value);
        node = node->tail;
        
        if (node != NULL)
            printf (" -> ");
    }
    printf (" \n");
}