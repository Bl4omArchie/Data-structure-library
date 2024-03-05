#include "../includes/file_struct.h"


// 4.1
int init_aa(AA *associative_array, int max_capacity) {
    if (associative_array == NULL || max_capacity <= 0)
        return -1;

    associative_array->actual_capacity = 0;
    associative_array->max_capacity = max_capacity;

    associative_array->Keys = (void*)malloc(associative_array->max_capacity);
    associative_array->Values = (void*)malloc(associative_array->max_capacity);

    return 1;
}

// 4.2
int resize_aa(AA * associative_array, int new_capacity) {
    if (associative_array == NULL || new_capacity <= 0)
        return -1;

    associative_array->max_capacity = new_capacity;
    associative_array->Keys = (void*)realloc(associative_array->Keys, associative_array->max_capacity);
    associative_array->Values = (void*)realloc(associative_array->Values, associative_array->max_capacity);

    return 1;
}

// 4.3
int put_data_aa(AA *associative_array, void *value, void *key) {
    if (associative_array == NULL)
        return -1;

    if (associative_array->actual_capacity >= associative_array->max_capacity/2)
        resize_aa(associative_array, associative_array->max_capacity*2);
        
    int i = get_hash(key);
    while (associative_array->Keys[i] != NULL) 
        i = (i + 1) % associative_array->max_capacity;
    
    associative_array->Keys[i] = key;
    associative_array->Values[i] = value;
    associative_array->actual_capacity++;
    
    return 1;
}

// 4.4
int get_data_aa(AA *associative_array, void *key) {

}

//4.5
int remove_data_aa(AA *associative_array, void *key) {

}

//4.6
int get_hash(void *key) {

}

// 4.7
int clear_aa(AA *associative_array) {
    free(associative_array->Keys);
    free(associative_array->Values);
    init_aa(associative_array, associative_array->max_capacity);
}

// 4.8
int free_aa(AA *associative_array) {
    free(associative_array->Keys);
    free(associative_array->Values);
    free(associative_array);
}