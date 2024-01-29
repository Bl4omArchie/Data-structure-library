#ifndef FILE_STRUCT_H
#define FILE_STRUCT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/*
A doubly linked list that handle positive numbers of 64 bits. 
*/
typedef struct DoublyLinkedList {
    uint64_t data;
    struct DoublyLinkedList* next;
    struct DoublyLinkedList* prev;
} DoublyLinkedList;


int init_linked_list(struct DoublyLinkedList *linked_list);

int insert_element_head(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int insert_data_head(struct DoublyLinkedList *linked_list, uint64_t data);

int insert_element_tail(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int insert_data_tail(struct DoublyLinkedList *linked_list, uint64_t data);

int remove_element_head(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int remove_data_head(struct DoublyLinkedList *linked_list, uint64_t data);

int remove_element_tail(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int remove_data_tail(struct DoublyLinkedList *linked_list, uint64_t data);

int free_linked_list(struct DoublyLinkedList *linked_list);

#endif