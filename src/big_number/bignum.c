#include "bignum.h"


Bignum *new_bn() {
    Bignum *bn = (Bignum*)malloc(sizeof(Bignum*));
    bn->number_element = 0;
    bn->root_bn = new_dll(0);
    bn->size_bn = 0;

    return bn;
}

int init_bn(Bignum *bn) {
    if (bn != NULL)
        return -1;

    bn->number_element = 0;
    bn->root_bn = new_dll(0);
    bn->size_bn = 0;
}

void reset_bn(Bignum *bn) {
    free_bn(bn);
    init_bn(bn);
}

void set_bn_ui(Bignum *bn, uint64_t number) {
    
}

void set_bn(Bignum *bn, Bignum *bn_to_set) {
    bn->root_bn = bn_to_set->root_bn;
    bn->size_bn = bn_to_set->size_bn;
    bn->number_element = bn_to_set->number_element;
}

void add_bn_i(Bignum *r, Bignum *a, int n) {

}

void add_bn(Bignum *r, Bignum *a, Bignum *b) {
    
}

void free_bn(Bignum *bn) {
    dll_free(bn->root_bn);
    free(bn);
}