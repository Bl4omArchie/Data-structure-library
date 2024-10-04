#ifndef BIGNUM_H
#define BIGNUM_H


#include "ll_struct.h"


typedef struct _bignum_struture {
    struct DLL *root_bn;
    size_t size_bn;
    int number_element;
} Bignum;


void init_bn(Bignum *bn);
void reset_bn(Bignum *bn);

void set_bn_i(Bignum *bn, int number);
void set_bn(Bignum *bn, Bignum *bn_to_set);

void add_bn_i(Bignum *bn, int number);
void add_bn(Bignum *bn, Bignum *bn_to_add);

void free_bn(Bignum *bn);


#endif