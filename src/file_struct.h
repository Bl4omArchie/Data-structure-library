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
A doubly linked list that handle positive numbers of 64 bits. 
*/
typedef struct DoublyLinkedList {
    uint64_t data;
    struct DoublyLinkedList *head;
    struct DoublyLinkedList *tail;
} DoublyLinkedList;


void init_linked_list(struct DoublyLinkedList *linked_list);

int insert_element_head(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int insert_data_head(struct DoublyLinkedList *linked_list, uint64_t data);

int insert_element_tail(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int insert_data_tail(struct DoublyLinkedList *linked_list, uint64_t data);

int remove_element_head(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int remove_data_head(struct DoublyLinkedList *linked_list, uint64_t data);

int remove_element_tail(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int remove_data_tail(struct DoublyLinkedList *linked_list, uint64_t data);

void free_element(struct DoublyLinkedList *element);
void free_linked_list(struct DoublyLinkedList *linked_list);
void free_linked_list_fork(struct DoublyLinkedList *linked_list);



#endif