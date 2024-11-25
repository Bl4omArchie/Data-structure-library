#ifndef BIGNUM_H
#define BIGNUM_H


#include "ll_struct.h"


// Endianess standard : big endian


typedef struct _bignum_struture {
    dll_node *root_bn;
    size_t size_bn;
    int number_element;
} Bignum;


Bignum *new_bn();
int init_bn(Bignum *bn);
void reset_bn(Bignum *bn);

void set_bn_i(Bignum *a, int n);
void set_bn(Bignum *a, Bignum *b);

void add_bn_i(Bignum *r, Bignum *a, int n);
void add_bn(Bignum *r, Bignum *a, Bignum *b);

void free_bn(Bignum *bn);


#endif