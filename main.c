#include "includes/file_struct.h"
#include "includes/benchmark.h"

#include <stdio.h>




int main() {
    XorLinkedList myList;
    xll_init(&myList);

    xll_set_data(&myList, 75345649876);

    return 1;
}