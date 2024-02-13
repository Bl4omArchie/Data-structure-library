#include "../includes/file_struct.h"


void xll_init(XorLinkedList *xll) {
    xll->data = 0;
    xll->xored_ptr = NULL;
}

int xll_set_data(XorLinkedList *xll, uint64_t data) {
    if (xll == NULL)
        return -1;

    xll->data = data;
    return 1;
}


int xll_insert_data_head(XorLinkedList *xll, uint64_t data) {
    if (xll == NULL)
        return -1;

    
}

int xll_insert_data_tail(XorLinkedList *xll, uint64_t data) {
    if (xll == NULL)
        return -1;

    
}