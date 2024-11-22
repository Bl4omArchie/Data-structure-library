#include "bignum.h"



Bignum *new_bn() {
    Bignum *bn = (Bignum*)malloc(sizeof(Bignum));
    bn->root_bn = new_dll(0);
    bn->size_bn = 0;
    bn->number_element = 0;

    return bn;
}

void init_bn(Bignum *bn) {
    init_dll(bn->root_bn, 0);
    bn->size_bn = 0;
    bn->number_element = 0;
}

void reset_bn(Bignum *bn) {
    free_bn(bn);
    init_bn(bn);
}

void set_bn_i(Bignum *a, int n);
void set_bn(Bignum *a, Bignum *b);

void add_bn_i(Bignum *r, Bignum *a, int n);
void add_bn(Bignum *r, Bignum *a, Bignum *b);

void free_bn(Bignum *bn) {
    dll_free(bn->root_bn);
    free(bn);
}