#include "../src/file_struct.h"


void init_linked_list(struct DoublyLinkedList *linked_list) {
    linked_list->data = 0;
    linked_list->head = NULL;
    linked_list->tail = NULL;
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
    
    linked_list->tail->head = element;
    element->tail = linked_list->tail;
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

int remove_element_head(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int remove_data_head(struct DoublyLinkedList *linked_list, uint64_t data);

int remove_element_tail(struct DoublyLinkedList *linked_list, struct DoublyLinkedList *element);
int remove_data_tail(struct DoublyLinkedList *linked_list, uint64_t data);


void free_element(struct DoublyLinkedList *element) {
    element->head->tail = element->tail;
    element->tail = element->head;
    free(element);
}

void free_linked_list(struct DoublyLinkedList *linked_list) {
    DoublyLinkedList *current = linked_list->head;
    DoublyLinkedList *next;

    while (current != NULL) {
        next = current->tail;
        free(current);
        current = next;
    }
    free(linked_list);
}

void free_linked_list_fork(struct DoublyLinkedList *linked_list) {

}