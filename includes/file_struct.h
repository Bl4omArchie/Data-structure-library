#ifndef FILE_STRUCT_H
#define FILE_STRUCT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>


/*
Third type of struct ?

struct Element {
    Element *head;
    Element *tail;
} Element;

typedef struct DoublyLinkedList {
    struct Element *head;
    struct Element *tail;
    struct Element *middle;
} DoublyLinkedList;

for parallelization

Note: the third pointer middle may not be necessary, I think the structure we already using is enough bout I need to thing more on how could I perform scalable parallelization.
*/


// A doubly linked list that handle positive nu vmbers of 64 bits. 
typedef struct DoublyLinkedList {
    uint64_t data;
    struct DoublyLinkedList *head;
    struct DoublyLinkedList *tail;
} DoublyLinkedList;


/* Manual: init_linked_list
Use for the first element of the linked list.
It nullify the head and the tail
*/
void init_linked_list(struct DoublyLinkedList *linked_list);


/* Manual insertion
set_data: set the given value into your element (positive number only)
insert_element: insert a given element (DoublyLinkedList) into the head or the tail of the given linked list
insert_data: same utility but you only provide a value and it create a new element
*/
void set_data(struct DoublyLinkedList *linked_list, uint64_t data);
int insert_element_head(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int insert_data_head(struct DoublyLinkedList *linked_list, uint64_t data);
int insert_element_tail(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int insert_data_tail(struct DoublyLinkedList *linked_list, uint64_t data);


// Manual deletion: remove the given element and link the head to the tail
void remove_element(struct DoublyLinkedList *element);


/* Manual: clear
clear: nullify the head and free the memory of the rest
clear_head: nullify the given element and free the memory of every element from head to this element
clear_tail: same but for the tail

free: free memory of the whole linked list
free_head: free the given element and everything above it
free_tail: same but for the tail
*/ 
void clear_linked_list(struct DoublyLinkedList *linked_list);
void free_linked_list(struct DoublyLinkedList *linked_list);
void clear_head_linked_list(struct DoublyLinkedList *linked_list);
void clear_tail_linked_list(struct DoublyLinkedList *linked_list);
void free_head_linked_list(struct DoublyLinkedList *linked_list);
void free_tail_linked_list(struct DoublyLinkedList *linked_list);


/* Manual find:
find_head:
find_tail:
*/
DoublyLinkedList *find_head(struct DoublyLinkedList *linked_list);


#endif