#include "../includes/file_struct.h"


// ################### Algorithm 2 #####################

/*2.1.1*/
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

/*2.1.2*/
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

/*2.1.3*/
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

/*2.1.4*/
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

/*2.1.5*/
int add_linked_list(DLL *res, DLL first_list, DLL second_list) {
    if (res == NULL || &first_list == NULL || &second_list == NULL)
        return -1;

    DLL *a_next = &first_list;
    DLL *b_next = &second_list;
    int carry = 0;

    while ( a_next != NULL || b_next != NULL) {
        if (res->tail == NULL)
            insert_element_tail(res, (DLL*)malloc(sizeof(DLL)));

        set_data(res, add_binary_optimized(a_next->data, b_next->data, carry));
        carry = (a_next->data > UINT64_MAX - b_next->data) ? 1 : 0;
        
        res = res->tail;
        a_next = a_next->tail;
        b_next = b_next->tail;
    }
}


// ################### Fork #####################

// 2.2.1
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

// 2.2.2
int add_tail_fork(DLL *res, DLL start_elem) {

}

// 2.2.3
int add_linked_list_fork(DLL *res, DLL start_elem) {

}

// 2.3
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