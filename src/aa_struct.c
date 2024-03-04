#include "../includes/file_struct.h"


// 4.1
int init_aa(AA *associative_array, int max_capacity) {
    if (associative_array == NULL || max_capacity <= 0)
        return -1;

    associative_array->actual_capacity = 0;
    associative_array->max_capacity = max_capacity;

    associative_array->Key = (uint64_t*)malloc(associative_array->max_capacity);
    associative_array->Values = (uint64_t*)malloc(associative_array->max_capacity);

    return 1;
}

// 4.2
int resize_aa(AA * associative_array, int new_capacity) {
    if (associative_array == NULL || new_capacity <= 0)
        return -1;

    associative_array->max_capacity = new_capacity;
    associative_array->Key = (uint64_t*)realloc(associative_array->Key, associative_array->max_capacity);
    associative_array->Values = (uint64_t*)realloc(associative_array->Values, associative_array->max_capacity);

    return 1;
}