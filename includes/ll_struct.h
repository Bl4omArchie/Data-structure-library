#ifndef LL_STRUCT_H
#define LL_STRUCT_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <unistd.h>



// For each data structure (DLL or BDLL), you have to initialize the first node. it nullify the head and tail and set the value equal to 0.
// Than you can set a value and add more nodes at the head or tail.



// ********* Doubly Linked List ************

typedef struct DoublyLinkedList {
    uint64_t value;
    struct DoublyLinkedList *head;
    struct DoublyLinkedList *tail;
} dll_node;


void dll_init(dll_node *node);
void dll_set_value(dll_node *node, uint64_t value);

int dll_insert_value_head(dll_node *node, uint64_t value);
int dll_insert_value_tail(dll_node *node, uint64_t value);

int dll_insert_node_head(dll_node *node, dll_node *to_replace);
int dll_insert_node_tail(dll_node *node, dll_node *to_replace);

//Remove the given node and link the head of it to its tail
int dll_remove_node(dll_node *node);

// Clear and free from the given node until it reached the tail
int dll_clear(dll_node *node);
int dll_free(dll_node *node);

void dll_display_tail(dll_node *node);



// ********* Branched Doubly Linked List *********

typedef struct BranchedDoublyLinkedList {
    uint64_t value;
    struct BranchedDoublyLinkedList *head;
    struct BranchedDoublyLinkedList *tail;
    struct BranchedDoublyLinkedList *branch;
} bdll_node;



void bdll_init(bdll_node *node);
void bdll_set_value(bdll_node *node, uint64_t value);


int bdll_insert_value_branch(bdll_node *node, uint64_t value);
int bdll_insert_value_head(bdll_node *node, uint64_t value);
int bdll_insert_value_tail(bdll_node *node, uint64_t value);

int bdll_insert_node_branch(bdll_node *node, bdll_node *to_replace);
int bdll_insert_node_head(bdll_node *node, bdll_node *to_replace);
int bdll_insert_node_tail(bdll_node *node, bdll_node *to_replace);

int bdll_remove_node(bdll_node *node);
int bdll_remove_branch(bdll_node *node);

int bdll_clear(bdll_node *node);
int bdll_clear_branch(bdll_node *node);
int bdll_clear_head(bdll_node *node);
int bdll_clear_tail(bdll_node *node);

int bdll_free_branch(bdll_node *node);
int bdll_free_head(bdll_node *node);
int bdll_free_tail(bdll_node *node);

void bdll_display_tail(bdll_node *node);


#endif