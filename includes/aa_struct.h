#ifndef AA_STRUCT_H
#define AA_STRUCT_H


#include <stdlib.h>


typedef struct AssociativeArray {
    void *Values;
    void *Keys;
    int actual_capacity;
    int max_capacity;
} aa;


int aa_init(aa *associative_array, int max_capacity);
int aa_resize(aa *ssociativeArray, int new_capacity);

int aa_clear(aa *associative_array);
int aa_free(aa *associative_array);

// TODO:
int aa_put_data(aa *associative_array, void *value, void *key);
int aa_get_data(aa *associative_array, void *key);
int aa_remove_data(aa *associative_array, void *key);
int aa_get_hash(void *Keys);


#endif