#ifndef FILE_STRUCT_H
#define FILE_STRUCT_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <unistd.h>

#include <sys/types.h>

// Note: pointer on certain elements for scalable parallelization



// ################### 1 - Linked List #####################


// A doubly linked list that handle POSITIVE nubmbers of 64 bits.
// Data can be less than 64 bits but it need to be specified
typedef struct DoublyLinkedList {
    uint64_t data;
    int byte_size_data;
    struct DoublyLinkedList *head;
    struct DoublyLinkedList *tail;
} DLL;

/* Manual: init_dll
Used for the first element of the linked list.
It nullify the head and the tail
*/
void init_dll(DLL *linked_list);


/* Manual insertion
set_data: set the given value into your element (positive number only)
insert_element: insert a given element (DLL) into the head or the tail of the given linked list
insert_data: same utility but you only provide a value and it create a new element
insert_linked_list: instead of inserting a new data/element at the head/tail of the element, it insert the value at the head/tail of the whole DLL
*/
void set_data(DLL *linked_list, uint64_t data);
int insert_element_head(DLL *linked_list, DLL *element);
int insert_element_tail(DLL *linked_list, DLL *element);

int insert_data_head(DLL *linked_list, uint64_t data);
int insert_data_tail(DLL *linked_list, uint64_t data);

int insert_data_linked_list_head(DLL *linked_list, uint64_t data);
int insert_data_linked_list_tail(DLL *linked_list, uint64_t data);

int insert_element_linked_list_head(DLL *linked_list, DLL *element);
int insert_element_linked_list_tail(DLL *linked_list, DLL *element);


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



// ################### 2 - Linked list Operation #####################

/* Addition with Linked List
add_head: add into the given element, every head's value
add_tail: same with tail
add_elements_range: add into res every elements from A to B (included)
*/
int add_head(DLL *res, DLL start_elem);
int add_tail(DLL *res, DLL start_elem);
int add_head_range(DLL *res, DLL start_elem, DLL end_elem);
int add_tail_range(DLL *res, DLL start_elem, DLL end_elem);
int add_linked_list(DLL *res, DLL first_list, DLL second_list);

// Forked version of linked list addition
int add_head_fork(DLL *res, DLL start_elem);
int add_tail_fork(DLL *res, DLL start_elem);
int add_linked_list_fork(DLL *res, DLL start_elem);

// For two 64 bits number a and b, predict if the addition of those two numbers will give a carry or not
int predict_carry(uint64_t a, uint64_t b, int bit_size);



// ################### 3 - Assembly  #####################

extern uint64_t add_binary_optimized(uint64_t a, uint64_t b, int c);
extern uint64_t sub_binary_optimized(uint64_t a, uint64_t b, int c);



// ################### 4 - Associative Array  #####################

typedef struct AssociativeArray {
    void *Values;
    void *Keys;
    int actual_capacity;
    int max_capacity;
} AA;

int init_aa(AA *associative_array, int max_capacity);
int resize_aa(AA *ssociativeArray, int new_capacity);

int clear_aa(AA *associative_array);
int free_aa(AA *associative_array);

// TODO:
int put_data_aa(AA *associative_array, void *value, void *key);
int get_data_aa(AA *associative_array, void *key);
int remove_data_aa(AA *associative_array, void *key);
int get_hash(void *Keys);


#endif