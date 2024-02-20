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


// ################### Fork #####################

int predict_carry(uint64_t a, uint64_t b) {
    int c = 0;

    for (int i=0; i<64; i++) {
        c = (a & 1) + (b & 1) + c;
        c >>= 1;
        a >>= 1;
        b >>= 1;
    }
    return c;
}

int predict_carry_v2(uint64_t a, uint64_t b) {
    int c = 0;
    uint64_t mask = 1ULL << 63;

    while ((a & mask) || (b & mask)) {
        c = (a & mask) + (b & mask) + c;
        c >>= 1;
        a <<= 1;
        b <<= 1;
    }
    return c;
}


int add_head_fork(DLL *res, DLL start) {
    int max_processes = 15;
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

int add_tail_fork(DLL *res, DLL start) {

}