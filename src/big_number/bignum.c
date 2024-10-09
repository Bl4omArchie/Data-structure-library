#include "bignum.h"

void init_bn(Bignum *bn) {
    bn->number_element = 0;
    dll_init(bn->root_bn);
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

void add_bn_i(Bignum *bn, int number) {

}

void add_bn(Bignum *bn, Bignum *bn_to_add) {

}

void free_bn(Bignum *bn) {
    dll_free(bn->root_bn);
    free(bn);
}