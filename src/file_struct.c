#include "../includes/file_struct.h"


void init_linked_list(struct DoublyLinkedList *linked_list) {
    linked_list->data = 0;
    linked_list->head = NULL;
    linked_list->tail = NULL;
}


void set_data(struct DoublyLinkedList *linked_list, uint64_t data) {
    // If negative number you add, messed up your linked list will be. Are allowed positive numbers only !!!
    linked_list->data = data & 0x7FFFFFFFFFFFFFFF;
}


int insert_element_head(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element) {
    if (linked_list == NULL || element == NULL) 
        return -1;
    
    if (linked_list->head != NULL) {
        linked_list->head->tail = element;
        element->head = linked_list->head;
    }
    element->tail = linked_list;
    linked_list->head = element;

    return 1;
}


int insert_data_head(struct DoublyLinkedList *linked_list, uint64_t data) {
    if (linked_list == NULL) 
        return -1;

    DoublyLinkedList *newElement = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    init_linked_list(newElement);
    newElement->data = data;
    return insert_element_head(linked_list, newElement);
}


int insert_element_tail(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element) {
    if (linked_list == NULL || element == NULL) 
        return -1;
    
    if (linked_list->tail != NULL) {
        linked_list->tail->head = element;
        element->tail = linked_list->tail;
    }

    element->head = linked_list;
    linked_list->tail = element;
    return 1;
}


int insert_data_tail(struct DoublyLinkedList *linked_list, uint64_t data) {
    if (linked_list == NULL) 
        return -1;
    
    DoublyLinkedList *newElement = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    init_linked_list(newElement);
    newElement->data = data;
    return insert_element_tail(linked_list, newElement);
}


void remove_element(struct DoublyLinkedList *element) {
    element->head->tail = element->tail;
    element->tail = element->head;
    free(element);
}


void clear_linked_list(struct DoublyLinkedList *linked_list) {

}


void clear_head_linked_list(struct DoublyLinkedList *linked_list) {
    DoublyLinkedList *current = linked_list;
    DoublyLinkedList *prev;

    if (linked_list->tail != NULL)
        linked_list->tail->head = NULL;

    while (current != NULL) {
        prev = current->head;
        free(current);
        current = prev;
    }
}

void clear_tail_linked_list(struct DoublyLinkedList *linked_list) {
    DoublyLinkedList *current = linked_list;
    DoublyLinkedList *next;

    if (linked_list->head != NULL)
        linked_list->head->tail = NULL;

    while (current != NULL) {
        next = current->tail;
        free(current);
        current = next;
    }
}

void free_linked_list(struct DoublyLinkedList *linked_list) {
    clear_linked_list(linked_list);
    free(linked_list);
}

void free_head_linked_list(struct DoublyLinkedList *linked_list) {
    clear_head_linked_list(linked_list);
    free(linked_list);
}

void free_tail_linked_list(struct DoublyLinkedList *linked_list) {
    clear_tail_linked_list(linked_list);
    free(linked_list);
}


DoublyLinkedList *find_head(struct DoublyLinkedList *linked_list) {
    DoublyLinkedList *current = linked_list;
    DoublyLinkedList *next;

    while (current->head != NULL) {
        current = next;
        next = current->tail;
    }
    return current;
}

DoublyLinkedList *find_tail(struct DoublyLinkedList *linked_list) {
    DoublyLinkedList *current = linked_list;
    DoublyLinkedList *prev;

    while (current->tail != NULL) {
        current = prev;
        prev = current->head;
    }
    return current;
}