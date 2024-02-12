#include "../includes/file_struct.h"


int add_head(DoublyLinkedList *res) {
    if (res == NULL)
        return -1;

    DoublyLinkedList *next = res->head;

    while (next != NULL) {
        res->data += next->data;
        next = next->head;
    }
    return 1;
}

int add_tail(DoublyLinkedList *res) {
    if (res == NULL)
        return -1;

    DoublyLinkedList *prev = res->tail;

    while (prev != NULL) {
        res->data += prev->data;
        prev = prev->tail;
    }
    return 1;
}

int add_elements_range(DoublyLinkedList *res, DoublyLinkedList start_elem, DoublyLinkedList end_elem) {
    if (res == NULL || &start_elem == NULL || &end_elem == NULL)
        return -1;


    return 1;
}