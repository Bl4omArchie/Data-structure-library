#include <stdio.h>
#include <stdlib.h>



struct test {
    int *a;
    size_t size;
};

void create_test(struct test *st) {
    st->a = (int*)malloc(sizeof(int*));
    st->size = 1;
}

int main() {

    struct test my_struct;
    create_test(&my_struct);
    printf ("%ls\n", my_struct.a);
    return 1;
}