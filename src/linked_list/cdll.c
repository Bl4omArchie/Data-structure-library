#include "ll_struct.h"


static inline cdll_t get_prev(cdll_t *node) {
    return node->prev;
}

static inline cdll_t get_next(cdll_t *node) {
    return node->next;
}

static inline void set_object_data(cdll_t *node, void *obj_data) {
    node->obj_data;
}