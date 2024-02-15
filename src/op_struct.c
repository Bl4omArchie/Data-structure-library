#include "../includes/file_struct.h"


int add_head(DoublyLinkedList *res) {
    if (res == NULL)
        return -1;

    DoublyLinkedList *current = res->head;

    while (current != NULL) {
        res->data += current->data;
        current = current->head;
    }
    return 1;
}

int add_tail(DoublyLinkedList *res) {
    if (res == NULL)
        return -1;

    DoublyLinkedList *current = res->tail;

    while (current != NULL) {
        res->data += current->data;
        current = current->tail;
    }
    return 1;
}

int add_head_range(DoublyLinkedList *res, DoublyLinkedList start_elem, DoublyLinkedList end_elem) {
    if (res == NULL || &start_elem == NULL || &end_elem == NULL)
        return -1;

    DoublyLinkedList *current = &start_elem;

    while (current != &end_elem && current != NULL) {
        res->data += current->data;
        current = current->head;
    }
    return 1;
}

int add_tail_range(DoublyLinkedList *res, DoublyLinkedList start_elem, DoublyLinkedList end_elem) {
    if (res == NULL || &start_elem == NULL || &end_elem == NULL)
        return -1;

    DoublyLinkedList *current = &start_elem;

    while (current != &end_elem && current != NULL) {
        res->data += current->data;
        current = current->tail;
    }
    return 1;
}

int add_head_fork(DoublyLinkedList *res) {

}

int add_tail_fork(DoublyLinkedList *res) {

}