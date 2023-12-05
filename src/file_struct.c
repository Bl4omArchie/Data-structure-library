#include "../src/file_struct.h"


void init_list(DoublyLinkedList *f) {
    f->head = NULL;
    f->tail = NULL;
}

void insert_head(DoublyLinkedList *f, int v) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    newElement->data = v;
    newElement->next = f->head;
    newElement->prev = NULL;

    if (f->head != NULL) 
        f->head->prev = newElement;
    else 
        f->tail = newElement;

    f->head = newElement;
}

void insert_tail(DoublyLinkedList *f, int v) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    newElement->data = v;
    newElement->next = f->tail;
    newElement->prev = NULL;

    if (f->tail != NULL) 
        f->tail->prev = newElement;
    else 
        f->head = newElement;
        
    f->tail = newElement;
}

bool is_empty(const DoublyLinkedList *f) {
    return f->head == NULL;
}


//Delete a given Element of a given list
void delete_element(DoublyLinkedList *f, Element to_delete) {
    if (to_delete.prev != NULL)
        to_delete.prev->next = to_delete.next;
    else
        f->head = to_delete.next;
    
    if (to_delete.next != NULL)
        to_delete.next->prev = to_delete.prev;
    else   
        f->tail = to_delete.prev;
}


/*
Suppression of each Element of the list
The head and tail are set to null
*/
void free_file(DoublyLinkedList *f) {
    Element *current = f->head;
    Element *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    f->head = NULL;
    f->tail = NULL;
}

Element find(DoublyLinkedList *f, int v) {
    Element *current = f->head;
    Element *next = current->next;

    while (current != NULL) {
        if (current->data == v)
            return *current;
        current = next;
        next = current->next;
    }
}

Element find_next(DoublyLinkedList *f, int v) {
    return *find(f, v).next;
}

Element find_previous(DoublyLinkedList *f, int v) {
    return *find(f, v).prev;
}