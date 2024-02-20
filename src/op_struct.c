#include "../includes/file_struct.h"


int add_head(DLL *res, DLL start) {
    if (res == NULL)
        return -1;

    DLL *current = start.head;

    while (current != NULL) {
        res->data += current->data;
        current = current->head;
    }
    return 1;
}

int add_tail(DLL *res, DLL start) {
    if (res == NULL)
        return -1;

    DLL *current = start.tail;

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
    int max_processes = 10;
    int iter = 0;
    
    while (iter < max_processes) {
        pid_t pid = fork();
        iter++;

        if (pid == -1) {
            perror("fork");
            break;
        } 
        
        else if (pid == 0) {
            // add_head();
            exit(0);
        } 
        
        else
            max_processes++;
    }
}

int add_tail_fork(DLL *res) {

}