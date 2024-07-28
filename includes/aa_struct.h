#ifndef AA_STRUCT_H
#define AA_STRUCT_H


#include <stdlib.h>


typedef struct AssociativeArray {
    void *Values;
    void *Keys;
    int actual_capacity;
    int max_capacity;
} AA;


int init_aa(AA *associative_array, int max_capacity);
int resize_aa(AA *ssociativeArray, int new_capacity);

int clear_aa(AA *associative_array);
int free_aa(AA *associative_array);

// TODO:
int put_data_aa(AA *associative_array, void *value, void *key);
int get_data_aa(AA *associative_array, void *key);
int remove_data_aa(AA *associative_array, void *key);
int get_hash(void *Keys);


#endif