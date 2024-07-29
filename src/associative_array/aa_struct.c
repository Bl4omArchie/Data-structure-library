#include "aa_struct.h"


int aa_init(aa *associative_array, int max_capacity) {
    if (associative_array == NULL || max_capacity <= 0)
        return -1;

    associative_array->actual_capacity = 0;
    associative_array->max_capacity = max_capacity;

    associative_array->Keys = (void*)malloc(associative_array->max_capacity);
    associative_array->Values = (void*)malloc(associative_array->max_capacity);

    return 1;
}

int aa_resize(aa * associative_array, int new_capacity) {
    if (associative_array == NULL || new_capacity <= 0)
        return -1;

    associative_array->max_capacity = new_capacity;
    associative_array->Keys = (void*)realloc(associative_array->Keys, associative_array->max_capacity);
    associative_array->Values = (void*)realloc(associative_array->Values, associative_array->max_capacity);

    return 1;
}

int aa_put_data(aa *associative_array, void *value, void *key) {
    if (associative_array == NULL)
        return -1;

    if (associative_array->actual_capacity >= associative_array->max_capacity/2)
        aa_resize(associative_array, associative_array->max_capacity*2);
        
    int i = aa_get_hash(key);
    /*
    while (associative_array->Keys[i] != NULL) 
        i = (i + 1) % associative_array->max_capacity;
    
    associative_array->Keys[i] = key;
    associative_array->Values[i] = value;
    associative_array->actual_capacity++;
    */
    return 1;
}

int aa_get_data(aa *associative_array, void *key) {

}

int aa_remove_data(aa *associative_array, void *key) {

}

int aa_get_hash(void *key) {

}

int aa_clear(aa *associative_array) {
    free(associative_array->Keys);
    free(associative_array->Values);
    aa_init(associative_array, associative_array->max_capacity);
}

int aa_free(aa *associative_array) {
    free(associative_array->Keys);
    free(associative_array->Values);
    free(associative_array);
}