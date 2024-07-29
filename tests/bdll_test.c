#include "ll_tests.h"


int bdll_routine() {
    return 1;
}

int main_bdll_test() {
    bdll_node branched_linked_list;
    bdll_init(&branched_linked_list);
    bdll_set_value(&branched_linked_list, 5);


    bdll_insert_value_tail(&branched_linked_list, 10);
    bdll_insert_value_tail(branched_linked_list.tail, 10);
    bdll_insert_value_tail(branched_linked_list.tail->tail, 20);

    printf ("%ld\n", branched_linked_list.value);

    bdll_display_tail(&branched_linked_list);

    return 1;
}