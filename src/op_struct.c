#include "../includes/file_struct.h"


int add_head(DLL *res, DLL start_elem) {
    if (res == NULL || &start_elem == NULL)
        return -1;

    DLL *current = start_elem.head;

    while (current != NULL) {
        set_data(res, res->data+current->data);
        current = current->head;
    }
    return 1;
}

int add_tail(DLL *res, DLL start_elem) {
    if (res == NULL || &start_elem == NULL)
        return -1;

    DLL *current = start_elem.tail;

    while (current != NULL) {
        set_data(res, res->data+current->data);
        current = current->tail;
    }
    return 1;
}


int add_head_range(DLL *res, DLL start_elem, DLL end_elem) {
    if (res == NULL || &start_elem == NULL || &end_elem == NULL)
        return -1;

    DLL *current = &start_elem;

    while (current != &end_elem && current != NULL) {
        set_data(res, res->data+current->data);
        current = current->head;
    }
    return 1;
}

int add_tail_range(DLL *res, DLL start_elem, DLL end_elem) {
    if (res == NULL || &start_elem == NULL || &end_elem == NULL)
        return -1;

    DLL *current = &start_elem;

    while (current != &end_elem && current != NULL) {
        set_data(res, res->data+current->data);
        current = current->tail;
    }
    return 1;
}


int add_linked_list(DLL *res, DLL first_list, DLL second_list) {
    if (res == NULL || &first_list == NULL || &second_list == NULL)
        return -1;

    DLL *a_c = &first_list;
    DLL *b_c = &second_list;

    printf ("ok2");

    while ( a_c != NULL || b_c != NULL) {
        set_data(res, a_c->data + b_c->data);
        res = res->tail;

        printf ("ok3");
        
        a_c = a_c->tail;
        b_c = b_c->tail;
    }

    printf ("ok final");
}


// ################### Fork #####################


int predict_carry(uint64_t a, uint64_t b, int bit_size) {
    // v2
    int i = bit_size-1;
    int c = 0;

    while ( ((a>>i)&1 || (b>>i)&1) && i > 0 && c == 0) {
        c = ((a>>i)&1) && ((b>>i)&1);
        i--;
    }
    return c;
}



int add_head_fork(DLL *res, DLL start_elem) {
    if (res == NULL || &start_elem == NULL)
        return -1;


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

int add_tail_fork(DLL *res, DLL start_elem) {

}