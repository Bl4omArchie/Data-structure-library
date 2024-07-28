#include "ll_tests.h"


int bdll_routine() {
    return 1;
}

int main_bdll_test() {
    Node_BDLL branched_linked_list;
    init_bdll(&branched_linked_list);
    set_value_bdll(&branched_linked_list, 5);


    insert_tail_bdll(&branched_linked_list, 10);
    insert_tail_bdll(branched_linked_list.tail, 10);
    insert_tail_bdll(branched_linked_list.tail->tail, 20);

    printf ("%ld\n", branched_linked_list.value);

    display_tail_bdll(&branched_linked_list);

    return 1;
}