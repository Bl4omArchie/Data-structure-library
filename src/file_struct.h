#ifndef FILE_STRUCT_H
#define FILE_STRUCT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


// Structure of an integer element of the DoublyLinkedList
typedef struct Element {
    uint64_t data;
    struct Element* next;
    struct Element* prev;
} Element;

// Structure DoublyLinkedList
typedef struct DoublyLinkedList {
    Element* head;
    Element* tail;
} DoublyLinkedList;


void init_list(DoublyLinkedList *f);
void insert_head(DoublyLinkedList *f, uint64_t v);
void insert_tail(DoublyLinkedList *f, uint64_t v);
bool is_empty(const DoublyLinkedList *f);
void delete_element(DoublyLinkedList *f, Element to_delete);
void free_file(DoublyLinkedList *f);
void print_doubly_linked(DoublyLinkedList *f);

Element find(DoublyLinkedList *f, uint64_t v);
Element find_next(DoublyLinkedList *f, uint64_t v);
Element find_previous(DoublyLinkedList *f, uint64_t v);

#endif