#ifndef FILE_STRUCT_H
#define FILE_STRUCT_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <unistd.h>

#include <sys/types.h>

// Note: pointer on certain elements for scalable parallelization



// A doubly linked list that handle POSITIVE nubmbers of 64 bits.
typedef struct DoublyLinkedList {
    uint64_t data;
    struct DoublyLinkedList *head;
    struct DoublyLinkedList *tail;
} DLL;  



// ################### Doubly Linked List #####################

/* Manual: init_linked_list
Used for the first element of the linked list.
It nullify the head and the tail
*/
void init_linked_list(DLL *linked_list);


/* Manual insertion
set_data: set the given value into your element (positive number only)
insert_element: insert a given element (DLL) into the head or the tail of the given linked list
insert_data: same utility but you only provide a value and it create a new element
*/
void set_data(DLL *linked_list, uint64_t data);
int insert_element_head(DLL *linked_list, DLL *element);
int insert_element_tail(DLL *linked_list, DLL *element);

int insert_data_head(DLL *linked_list, uint64_t data);
int insert_data_tail(DLL *linked_list, uint64_t data);


// Manual deletion: remove the given element and link the head to the tail
void remove_element(DLL *element);


/* Manual: clear
clear: look for the head of the entire list, clear every element below and nullify the head
clear_head: nullify the given element and free the memory of every element from head to this element
clear_tail: same but for the tail

free: free memory of the whole linked list
free_head: free the given element and everything above it
free_tail: same but for the tail
*/ 
int clear_linked_list(DLL *linked_list);
int clear_head_linked_list(DLL *linked_list);
int clear_tail_linked_list(DLL *linked_list);

void free_linked_list(DLL *linked_list);
void free_head_linked_list(DLL *linked_list);
void free_tail_linked_list(DLL *linked_list);


/* Manual find:
find_head: look for the head element of the whole list
find_tail: same for tail
*/
DLL *find_head(DLL *linked_list);
DLL *find_tail(DLL *linked_list);


// Manual display: print from the given element until the end
void display_linked_list(DLL linked_list);


/*Arithmetic with Linked List
add_head: add into the given element, every head's value
add_tail: same with tail
add_elements_range: add into res every elements from A to B (included)
*/
int add_head(DLL *res, DLL start);
int add_tail(DLL *res, DLL start);
int add_head_range(DLL *res, DLL start_elem, DLL end_elem);
int add_tail_range(DLL *res, DLL start_elem, DLL end_elem);

// For two 64 bits number a and b, predict if the addition of those two numbers will give a carry or not
int predict_carry(uint64_t a, uint64_t b);

// Forked version of linked list addition
int add_head_fork(DLL *res, DLL start);
int add_tail_fork(DLL *res, DLL start);


#endif