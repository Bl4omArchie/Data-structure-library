#ifndef LL_STRUCT_H
#define LL_STRUCT_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <unistd.h>



// For each data structure (DLL, BDLL or XLL), you have to initialize the first node. it nullify the head and tail and set the value equal to 0.
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

int dll_remove_node(dll_node *node);

int dll_clear(dll_node *node);
int dll_clear_head(dll_node *node);
int dll_clear_tail(dll_node *node);

int dll_free(dll_node *node);
int dll_free_head(dll_node *node);
int dll_free_tail(dll_node *node);

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




// ********* Xored Linked List *********

typedef struct XoredLinkedList {
    uint64_t value;
    struct XoredLinkedList *ht_node;
} xll_node;


void xll_init(xll_node *node);
void xll_set_value(xll_node *node, uint64_t value);
xll_node *xll_xor_nodes(xll_node* node_a, xll_node* node_b);

int xll_insert_value_head(xll_node *node, uint64_t value);
int xll_insert_value_tail(xll_node *node, uint64_t value);

int xll_insert_node_head(xll_node *node, xll_node *to_insert);
int xll_insert_node_tail(xll_node *node, xll_node *to_insert);

int xll_remove_node(xll_node *node);
int xll_clear_tail(xll_node *node);
int xll_free_tail(xll_node *node);

void xll_display(xll_node *node);

#endif