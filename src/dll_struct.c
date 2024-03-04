#include "../includes/file_struct.h"



// ################### Algorithm 1 #####################

// 1.1
void init_linked_list(DLL *linked_list) {
    linked_list->data = 0;
    linked_list->head = NULL;
    linked_list->tail = NULL;
}

// 1.2
void set_data(DLL *linked_list, uint64_t data) {
    // If negative number you add, messed up your linked list will be. Are allowed positive numbers only !!!
    linked_list->data = data & 0x7FFFFFFFFFFFFFFF;
    linked_list->byte_size_data = sizeof(linked_list->data);
}

// 1.3.1
int insert_element_head(DLL *linked_list, DLL *element) {
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

// 1.3.2
int insert_element_tail(DLL *linked_list, DLL *element) {
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

// 1.3.3
int insert_data_head(DLL *linked_list, uint64_t data) {
    if (linked_list == NULL) 
        return -1;

    DLL *newElement = (DLL*)malloc(sizeof(DLL));
    init_linked_list(newElement);
    set_data(newElement, data);
    
    return insert_element_head(linked_list, newElement);
}

// 1.3.4
int insert_data_tail(DLL *linked_list, uint64_t data) {
    if (linked_list == NULL) 
        return -1;
    
    DLL *newElement = (DLL*)malloc(sizeof(DLL));
    init_linked_list(newElement);
    set_data(newElement, data);

    return insert_element_tail(linked_list, newElement);
}

// 1.3.5
int insert_data_linked_list_head(DLL *linked_list, uint64_t data) {
    if (linked_list == NULL) 
        return -1;
    
    DLL *head = find_head(linked_list);
    insert_data_head(head, data);
    return 1;
}

// 1.3.6
int insert_data_linked_list_tail(DLL *linked_list, uint64_t data) {
    if (linked_list == NULL) 
        return -1;
    
    DLL *tail = find_tail(linked_list);
    insert_data_head(tail, data);
    return 1;
}

// 1.3.7
int insert_element_linked_list_head(DLL *linked_list, DLL *element) {
    if (linked_list == NULL) 
        return -1;
    DLL *head = find_head(linked_list);
    insert_element_head(head, element);
    return 1; 
}

// 1.3.8
int insert_element_linked_list_tail(DLL *linked_list, DLL *element) {
    if (linked_list == NULL) 
        return -1;
    DLL *tail = find_tail(linked_list);
    insert_element_tail(tail, element);
    return 1; 
}

// 1.4
void remove_element(DLL *element) {
    element->head->tail = element->tail;
    element->tail = element->head;
    free(element);
}

// 1.5.1
int clear_linked_list(DLL *linked_list) {
    if (linked_list == NULL)
        return -1;

    DLL *head = find_head(linked_list);
    return clear_tail_linked_list(head);
}

// 1.5.2
int clear_head_linked_list(DLL *linked_list) {
    if (linked_list == NULL || linked_list->head == NULL) 
        return -1;

    DLL *current = linked_list->head;
    DLL *prev;

    while (current != NULL) {
        prev = current->head;
        free(current);
        current = prev;
    }
    linked_list->head = NULL;
    return 1;
}

// 1.5.3
int clear_tail_linked_list(DLL *linked_list) {
    if (linked_list == NULL || linked_list->tail == NULL) 
        return -1;

    DLL *current = linked_list->tail;
    DLL *next;

    while (current != NULL) {
        next = current->tail;
        free(current);
        current = next;
    }
    linked_list->tail = NULL;
    return 1;
}

// 1.6.1
void free_linked_list(DLL *linked_list) {
    clear_linked_list(linked_list);
    free(linked_list);
}

// 1.6.2
void free_head_linked_list(DLL *linked_list) {
    clear_head_linked_list(linked_list);
    free(linked_list);
}

// 1.6.3
void free_tail_linked_list(DLL *linked_list) {
    clear_tail_linked_list(linked_list);
    free(linked_list);
}

// 1.7.1
DLL *find_head(DLL *linked_list) {
    if (linked_list == NULL)
        return NULL;

    DLL *current = linked_list;
    DLL *prev;

    while (current->head != NULL) {
        current = prev;
        prev = current->head;
    }
    return current;
}

// 1.7.2
DLL *find_tail(DLL *linked_list) {
    if (linked_list == NULL)
        return NULL;

    DLL *current = linked_list;
    DLL *next;

    while (current->tail != NULL) {
        current = next;
        next = current->tail;
    }
    return current;
}

// 1.8
void display_linked_list(DLL linked_list) {
    DLL *current = &linked_list;
    DLL *next;

    while (current != NULL) {
        next = current->tail;
        printf ("%ld", current->data);
        current = next;
        
        if (current != NULL)
            printf (" -> ");
    }
    printf (" \n");
}