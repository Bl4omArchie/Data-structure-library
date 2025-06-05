#ifndef LL_STRUCT_H
#define LL_STRUCT_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <unistd.h>



typedef struct _circular_doubly_linked_list {
    struct _circular_doubly_linked_list *next;
    struct _circular_doubly_linked_list *prev;
    void *object_data;
} cdll_t;


typedef struct _cdll_l {
    cdll_t *head_guard;
    size_t total_size;
    cursor_t cdll_cursor;
} cdll_list;


typedef struct cursor_t {
    void *c_next;
    void *c_prev;
} cursor_t;


cdll_list new_cdll_list(void *data);
void init_cdll_list(cdll_list *cdll_l);

static inline cdll_t get_prev(cdll_t *node);
static inline cdll_t get_next(cdll_t *node);
static inline void set_object_data(cdll_t *node, void *obj_data);



#endif