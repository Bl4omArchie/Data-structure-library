#ifndef FILE_STRUCT_H
#define FILE_STRUCT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// Structure of an integer element of the DoublyLinkedList
typedef struct Element {
    int data;
    struct Element* next;
    struct Element* prev;
} Element;

// Structure DoublyLinkedList
typedef struct DoublyLinkedList {
    Element* head;
    Element* tail;
} DoublyLinkedList;


void init_list(DoublyLinkedList *f);
void insert_head(DoublyLinkedList *f, int v);
void insert_tail(DoublyLinkedList *f, int v);
bool is_empty(const DoublyLinkedList *f);
void delete_element(DoublyLinkedList *f, Element to_delete);
void free_file(DoublyLinkedList *f);

void find(DoublyLinkedList *f, Element *elem);
void find_next(DoublyLinkedList *f, Element *elem);
void find_previous(DoublyLinkedList *f, Element *elem);

#endif