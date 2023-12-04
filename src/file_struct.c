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
    if (f->tail == NULL) {

    }

}

int File_defiler(DoublyLinkedList *f) {

}

int file_size(const DoublyLinkedList *f) {

}

bool is_empty(const DoublyLinkedList *f) {

}

void free_file(DoublyLinkedList *f) {
    
}


// int File_premier(const DoublyLinkedList* f);
// int File_dernier(const DoublyLinkedList* f);