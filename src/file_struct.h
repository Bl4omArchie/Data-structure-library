#ifndef FILE_STRUCT_H
#define FILE_STRUCT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// Structure of an element of the DoublyLinkedList
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


void init_list(DoublyLinkedList *list);
void insert_head(DoublyLinkedList *f, int v);
void insert_tail(DoublyLinkedList *f, int v);

int File_defiler(DoublyLinkedList* f);
int file_size(const DoublyLinkedList* f);
bool is_empty(const DoublyLinkedList* f);
void free_file(DoublyLinkedList* f);



#endif