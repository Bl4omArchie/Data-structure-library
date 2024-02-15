#ifndef FILE_STRUCT_H
#define FILE_STRUCT_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>



// Note: pointer on certain elements for scalable parallelization


// A doubly linked list that handle POSITIVE nubmbers of 64 bits.
typedef struct DoublyLinkedList {
    uint64_t data;
    struct DoublyLinkedList *head;
    struct DoublyLinkedList *tail;
} DoublyLinkedList;



// ##################### Doubly Linked List #####################

/* Manual: init_linked_list
Use for the first element of the linked list.
It nullify the head and the tail
*/
void init_linked_list(DoublyLinkedList *linked_list);


/* Manual insertion
set_data: set the given value into your element (positive number only)
insert_element: insert a given element (DoublyLinkedList) into the head or the tail of the given linked list
insert_data: same utility but you only provide a value and it create a new element
*/
void set_data(DoublyLinkedList *linked_list, uint64_t data);
int insert_element_head(DoublyLinkedList *linked_list, DoublyLinkedList *element);
int insert_element_tail(DoublyLinkedList *linked_list, DoublyLinkedList *element);

int insert_data_head(DoublyLinkedList *linked_list, uint64_t data);
int insert_data_tail(DoublyLinkedList *linked_list, uint64_t data);


// Manual deletion: remove the given element and link the head to the tail
void remove_element(DoublyLinkedList *element);


/* Manual: clear
clear: look for the head of the entire list, clear every element below and nullify the head
clear_head: nullify the given element and free the memory of every element from head to this element
clear_tail: same but for the tail

free: free memory of the whole linked list
free_head: free the given element and everything above it
free_tail: same but for the tail
*/ 
int clear_linked_list(DoublyLinkedList *linked_list);
int clear_head_linked_list(DoublyLinkedList *linked_list);
int clear_tail_linked_list(DoublyLinkedList *linked_list);

void free_linked_list(DoublyLinkedList *linked_list);
void free_head_linked_list(DoublyLinkedList *linked_list);
void free_tail_linked_list(DoublyLinkedList *linked_list);


/* Manual find:
find_head: look for the head element of the whole list
find_tail: same for tail
*/
DoublyLinkedList *find_head(DoublyLinkedList *linked_list);
DoublyLinkedList *find_tail(DoublyLinkedList *linked_list);


// Manual display: print from the given element until the end
void display_linked_list(DoublyLinkedList linked_list);


/*Arithmetic with Linked List
add_head: add into the given element, every head's value
add_tail: same with tail
add_elements_range: add into res every elements from A to B (included)
*/
int add_head(DoublyLinkedList *res);
int add_tail(DoublyLinkedList *res);
int add_head_range(DoublyLinkedList *res, DoublyLinkedList start_elem, DoublyLinkedList end_elem);
int add_tail_range(DoublyLinkedList *res, DoublyLinkedList start_elem, DoublyLinkedList end_elem);


// Forked version of linked list addition
int add_head_fork(DoublyLinkedList *res);
int add_tail_fork(DoublyLinkedList *res);


#endif