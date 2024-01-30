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
Third struct ?

typedef struct DoublyLinkedList {
    uint64_t data;
    struct DoublyLinkedList *head;
    struct DoublyLinkedList *tail;
    struct DoublyLinkedList *middle;
} DoublyLinkedList;

Parallelization for clear and free

*/


// A doubly linked list that handle positive numbers of 64 bits. 
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


/* Manual: insertion
The first prototype insert a given element.
The second one create a new element with a given data
Both prototype exists for head and tail 
*/
int insert_data(struct DoublyLinkedList *linked_list, uint64_t data);
int insert_element_head(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int insert_data_head(struct DoublyLinkedList *linked_list, uint64_t data);
int insert_element_tail(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int insert_data_tail(struct DoublyLinkedList *linked_list, uint64_t data);


// Manual deletion
int remove_element(struct DoublyLinkedList *element);


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


#endif