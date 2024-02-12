#include "../includes/file_struct.h"


void init_linked_list(DoublyLinkedList *linked_list) {
    linked_list->data = 0;
    linked_list->head = NULL;
    linked_list->tail = NULL;
}


void set_data(DoublyLinkedList *linked_list, uint64_t data) {
    // If negative number you add, messed up your linked list will be. Are allowed positive numbers only !!!
    linked_list->data = data & 0x7FFFFFFFFFFFFFFF;
}


int insert_element_head(DoublyLinkedList *linked_list, DoublyLinkedList *element) {
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


int insert_data_head(DoublyLinkedList *linked_list, uint64_t data) {
    if (linked_list == NULL) 
        return -1;

    DoublyLinkedList *newElement = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    init_linked_list(newElement);
    set_data(newElement, data);
    
    return insert_element_head(linked_list, newElement);
}


int insert_element_tail(DoublyLinkedList *linked_list, DoublyLinkedList *element) {
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


int insert_data_tail(DoublyLinkedList *linked_list, uint64_t data) {
    if (linked_list == NULL) 
        return -1;
    
    DoublyLinkedList *newElement = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    init_linked_list(newElement);
    set_data(newElement, data);

    return insert_element_tail(linked_list, newElement);
}


void remove_element(DoublyLinkedList *element) {
    element->head->tail = element->tail;
    element->tail = element->head;
    free(element);
}



int clear_linked_list(DoublyLinkedList *linked_list) {
    if (linked_list == NULL)
        return -1;

    DoublyLinkedList *head = find_head(linked_list);
    return clear_tail_linked_list(head);
}


int clear_head_linked_list(DoublyLinkedList *linked_list) {
    if (linked_list == NULL || linked_list->head == NULL) 
        return -1;

    DoublyLinkedList *current = linked_list->head;
    DoublyLinkedList *prev;

    while (current != NULL) {
        prev = current->head;
        free(current);
        current = prev;
    }
    linked_list->head = NULL;
    return 1;
}

int clear_tail_linked_list(DoublyLinkedList *linked_list) {
    if (linked_list == NULL || linked_list->tail == NULL) 
        return -1;

    DoublyLinkedList *current = linked_list->tail;
    DoublyLinkedList *next;

    while (current != NULL) {
        next = current->tail;
        free(current);
        current = next;
    }
    linked_list->tail = NULL;
    return 1;
}

void free_linked_list(DoublyLinkedList *linked_list) {
    clear_linked_list(linked_list);
    free(linked_list);
}

void free_head_linked_list(DoublyLinkedList *linked_list) {
    clear_head_linked_list(linked_list);
    free(linked_list);
}

void free_tail_linked_list(DoublyLinkedList *linked_list) {
    clear_tail_linked_list(linked_list);
    free(linked_list);
}


DoublyLinkedList *find_head(DoublyLinkedList *linked_list) {
    DoublyLinkedList *current = linked_list;
    DoublyLinkedList *next;

    while (current->head != NULL) {
        current = next;
        next = current->tail;
    }
    return current;
}

DoublyLinkedList *find_tail(DoublyLinkedList *linked_list) {
    DoublyLinkedList *current = linked_list;
    DoublyLinkedList *prev;

    while (current->tail != NULL) {
        current = prev;
        prev = current->head;
    }
    return current;
}

void display_linked_list(DoublyLinkedList linked_list) {
    DoublyLinkedList *current = &linked_list;
    DoublyLinkedList *next;

    while (current != NULL) {
        next = current->tail;
        printf ("%ld", current->data);
        current = next;
        if (current != NULL)
            printf (" -> ");
    }
}