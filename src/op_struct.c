#include "../includes/file_struct.h"


int add_head(DLL *res) {
    if (res == NULL)
        return -1;

    DLL *current = res->head;

    while (current != NULL) {
        res->data += current->data;
        current = current->head;
    }
    return 1;
}

int add_tail(DLL *res) {
    if (res == NULL)
        return -1;

    DLL *current = res->tail;

    while (current != NULL) {
        res->data += current->data;
        current = current->tail;
    }
    return 1;
}

int add_head_range(DLL *res, DLL start_elem, DLL end_elem) {
    if (res == NULL || &start_elem == NULL || &end_elem == NULL)
        return -1;

    DLL *current = &start_elem;

    while (current != &end_elem && current != NULL) {
        res->data += current->data;
        current = current->head;
    }
    return 1;
}

int add_tail_range(DLL *res, DLL start_elem, DLL end_elem) {
    if (res == NULL || &start_elem == NULL || &end_elem == NULL)
        return -1;

    DLL *current = &start_elem;

    while (current != &end_elem && current != NULL) {
        res->data += current->data;
        current = current->tail;
    }
    return 1;
}

int add_head_fork(DLL *res) {
    
}

int add_tail_fork(DLL *res) {

}