#ifndef LL_STRUCT_H
#define LL_STRUCT_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <unistd.h>


// *** Doubly Linked List ***

typedef struct DoublyLinkedList {
    uint64_t value;
    struct DoublyLinkedList *head;
    struct DoublyLinkedList *tail;
} Node_DLL;



void init_dll(Node_DLL *node);
void set_value_dll(Node_DLL *node, uint64_t value);

int insert_head_dll(Node_DLL *node, uint64_t value);
int insert_tail_dll(Node_DLL *node, uint64_t value);

int replace_node_head_dll(Node_DLL *node, Node_DLL *to_replace);
int replace_node_tail_dll(Node_DLL *node, Node_DLL *to_replace);

int remove_node_dll(Node_DLL *node);

int clear_dll(Node_DLL *node);
int clear_head_dll(Node_DLL *node);
int clear_tail_dll(Node_DLL *node);

int free_dll(Node_DLL *node);
int free_head_dll(Node_DLL *node);
int free_tail_dll(Node_DLL *node);

void display_dll(Node_DLL node);



// *** Xored Linked List ***

typedef struct XoredLinkedList {
    uint64_t value;
    struct XoredLinkedList *ht_node;
} Node_XLL;



void init_xll(Node_XLL *node);
void set_value_xll(Node_XLL *node, uint64_t value);
Node_XLL *xor_nodes(Node_XLL* node_a, Node_XLL* node_b);

int insert_node_head_xll(Node_XLL *node, Node_XLL *to_insert);
int insert_node_tail_xll(Node_XLL *node, Node_XLL *to_insert);

int insert_value_head_xll(Node_XLL *node, uint64_t value);
int insert_value_tail_xll(Node_XLL *node, uint64_t value);

int remove_Node_XLL(Node_XLL *node);

int clear_xll(Node_XLL *node);
int clear_head_xll(Node_XLL *node);
int clear_tail_xll(Node_XLL *node);

int free_xll(Node_XLL *node);
int free_head_xll(Node_XLL *node);
int free_tail_xll(Node_XLL *node);

void display_xll(Node_XLL node);


#endif