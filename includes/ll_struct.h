#ifndef LL_STRUCT_H
#define LL_STRUCT_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <unistd.h>


// ********* Doubly Linked List ************

typedef struct DoublyLinkedList {
    uint64_t value;
    struct DoublyLinkedList *head;
    struct DoublyLinkedList *tail;
} Node_DLL;


void init_dll(Node_DLL *node);
void set_value_dll(Node_DLL *node, uint64_t value);

int insert_head_dll(Node_DLL *node, uint64_t value);
int insert_tail_dll(Node_DLL *node, uint64_t value);

int insert_node_head_dll(Node_DLL *node, Node_DLL *to_replace);
int insert_node_tail_dll(Node_DLL *node, Node_DLL *to_replace);

int remove_node_dll(Node_DLL *node);

int clear_dll(Node_DLL *node);
int clear_head_dll(Node_DLL *node);
int clear_tail_dll(Node_DLL *node);

int free_dll(Node_DLL *node);
int free_head_dll(Node_DLL *node);
int free_tail_dll(Node_DLL *node);

void display_tail_dll(Node_DLL *node);



// ********* Branched Doubly Linked List *********

typedef struct BranchedDoublyLinkedList {
    uint64_t value;
    struct BranchedDoublyLinkedList *head;
    struct BranchedDoublyLinkedList *tail;
    struct BranchedDoublyLinkedList *branch;
} Node_BDLL;



void init_bdll(Node_BDLL *node);
void set_value_bdll(Node_BDLL *node, uint64_t value);


int insert_branch_bdll(Node_BDLL *node, uint64_t value);
int insert_head_bdll(Node_BDLL *node, uint64_t value);
int insert_tail_bdll(Node_BDLL *node, uint64_t value);

int insert_node_branch_bdll(Node_BDLL *node, Node_BDLL *to_replace);
int insert_node_head_bdll(Node_BDLL *node, Node_BDLL *to_replace);
int insert_node_tail_bdll(Node_BDLL *node, Node_BDLL *to_replace);

int remove_node_BDLL(Node_BDLL *node);
int remove_branch_BDLL(Node_BDLL *node);

int clear_bdll(Node_BDLL *node);
int clear_branch_bdll(Node_BDLL *node);
int clear_head_bdll(Node_BDLL *node);
int clear_tail_bdll(Node_BDLL *node);

int free_bdll(Node_BDLL *node);
int free_branch_bdll(Node_BDLL *node);
int free_head_bdll(Node_BDLL *node);
int free_tail_bdll(Node_BDLL *node);

void display_bdll(Node_BDLL *node);




// ********* Xored Linked List *********

typedef struct XoredLinkedList {
    uint64_t value;
    struct XoredLinkedList *ht_node;
} Node_XLL;


void init_xll(Node_XLL *node);
void set_value_xll(Node_XLL *node, uint64_t value);
Node_XLL *xor_nodes(Node_XLL* node_a, Node_XLL* node_b);

int insert_head_xll(Node_XLL *node, uint64_t value);
int insert_tail_xll(Node_XLL *node, uint64_t value);

int insert_node_head_xll(Node_XLL *node, Node_XLL *to_insert);
int insert_node_tail_xll(Node_XLL *node, Node_XLL *to_insert);

int remove_node_XLL(Node_XLL *node);
int clear_tail_xll(Node_XLL *node);
int free_tail_xll(Node_XLL *node);

void display_xll(Node_XLL *node);


#endif