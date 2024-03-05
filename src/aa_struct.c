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
    associative_array->Key = (void*)realloc(associative_array->Key, associative_array->max_capacity);
    associative_array->Values = (void*)realloc(associative_array->Values, associative_array->max_capacity);

    return 1;   
}

// 4.3
int put_data_aa(AA *associative_array, void *Key, void *Values) {
    if (associative_array == NULL)
        return -1;

    if (associative_array->actual_capacity >= associative_array->max_capacity/2)
        resize_aa(associative_array, associative_array->max_capacity*2);
        

    int i = get_hash(Key);
    /*
    while (associative_array->Key[i] != NULL) {
        if (this.tab[i].equals(k)) {
            this.tab[i].setValue(v);
            return (Value) this.tab[i].getValue();
        }
        i = (i + 1) % associative_array->max_capacity;
    }
        
    associative_array->Values[i] = new Objet(k, v);
    associative_array->actual_capacity++;
    */
    return 1;
}

// 4.4
int get_data_aa(AA *associative_array, void *Key) {

}

//4.5
int remove_data_aa(AA *associative_array, void *Key) {

}

//4.6
int get_hash(void *Key) {

}