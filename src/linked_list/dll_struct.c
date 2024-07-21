#include "ll_struct.h"



void init_dll(Node_DLL *node) {
    node->head = NULL;
    node->tail = NULL;
    node->value = 0;
}

void set_value_dll(Node_DLL *node, uint64_t value) {
    // If negative number you add, messed up your linked list will be. Are allowed positive numbers only !!!
    node->value = value & 0x7FFFFFFFFFFFFFFF;
}
    

int insert_head_dll(Node_DLL *node, uint64_t value) {
    if (node == NULL) 
        return -1;

    Node_DLL *newNode = (Node_DLL*)malloc(sizeof(Node_DLL));
    init_dll(newNode);
    set_value_dll(newNode, value);
    
    if (node->head != NULL) {
        node->head->tail = newNode;
        newNode->head = node->head;
    }

    node->head = newNode;
    newNode->tail = node;
    return 1;
}


int insert_tail_dll(Node_DLL *node, uint64_t value) {
    if (node == NULL) 
        return -1;

    Node_DLL *newNode = (Node_DLL*)malloc(sizeof(Node_DLL));
    init_dll(newNode);
    set_value_dll(newNode, value);

    if (node->tail != NULL) {
        node->tail->head = newNode;
        newNode->tail = node->tail;
    }
    node->tail = newNode;
    newNode->head = node;

    return 1;
}

int replace_node_head_dll(Node_DLL *node, Node_DLL *to_replace) {
    if (node == NULL || to_replace == NULL) 
        return -1;

    if (node->head != NULL) {
        node->head->tail = to_replace;
        to_replace->head = node->head;
    }

    node->head = to_replace;
    to_replace->tail = node;
    return 1;
}


int replace_node_tail_dll(Node_DLL *node, Node_DLL *to_replace) {
    if (node->head == NULL || to_replace == NULL) 
        return -1;

    if (node->tail != NULL) {
        node->tail->head = to_replace;
        to_replace->tail = node->tail;
    }
    
    node->tail = to_replace;
    to_replace->head = node;
    return 1;
}

int remove_node_dll(Node_DLL *node) {
    if (node == NULL)
        return -1;
    
    if (node->head != NULL)
        node->head->tail = node->tail;
    
    if (node->tail != NULL)
        node->tail->head = node->head;

    free(node);
    return 1;
}

int clear_head_dll(Node_DLL *node) {
    if (node == NULL) 
        return -1;

    Node_DLL *current = node;
    while (current != NULL) {
        current->value = 0;
        current = current->head;
    }

    return 1;
}

int clear_tail_dll(Node_DLL *node) {
    if (node == NULL) 
        return -1;

    Node_DLL *current = node;
    while (current != NULL) {
        current->value = 0;
        current = current->tail;
    }

    return 1;
}

int clear_dll(Node_DLL *node) {
    if (node == NULL)
        return -1;
    
    if (node->tail != NULL) {
        Node_DLL *next = node->tail;
        clear_tail_dll(next);
    }

    clear_head_dll(node);
    return 1;
}

int free_head_dll(Node_DLL *node) {
    if (node == NULL || node->head == NULL)
        return -1;

    Node_DLL *current = node;
    Node_DLL *prev;

    while (current != NULL) {
        prev = current->head;
        free(current);
        current = prev;
    }

    node->head = NULL;
    return 1;
}

int free_tail_dll(Node_DLL *node) {
    if (node == NULL || node->tail == NULL)
        return -1;

    Node_DLL *current = node;
    Node_DLL *next;

    while (current != NULL) {
        next = current->tail;
        free(current);
        current = next;
    }

    node->tail = NULL;
    return 1;
}


int free_dll(Node_DLL *node) {
    if (node == NULL)
        return -1;
    
    if (node->tail != NULL) {
        Node_DLL *next = node->tail;
        free_tail_dll(next);
    }

    free_head_dll(node);
    return 1;
}


void display_dll(Node_DLL node) {
    Node_DLL *current = &node;
    Node_DLL *next;

    while (current != NULL) {
        next = current->tail;
        printf ("%ld", current->value);
        current = next;
        
        if (current != NULL)
            printf (" -> ");
    }
    printf (" \n");
}