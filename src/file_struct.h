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
void File_enfiler(DoublyLinkedList* f, int v);
int File_defiler(DoublyLinkedList* f);
int file_size(const DoublyLinkedList* f);
bool is_empty(const DoublyLinkedList* f);
void free_file(DoublyLinkedList* f);

// int File_premier(const File_t* f);
// int File_dernier(const File_t* f);


#endif