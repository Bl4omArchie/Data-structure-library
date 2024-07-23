#include "ll_tests.h"


int bdll_routine() {
    return 1;
}

int main_bdll_test() {
    Node_BDLL linked_list, second_linked_list, third_linked_list, fourth_linked_list;
    init_bdll(&linked_list);
    init_bdll(&second_linked_list);
    init_bdll(&third_linked_list);
    init_bdll(&fourth_linked_list);


    set_value_bdll(&linked_list, 5);
    set_value_bdll(&second_linked_list, 10);
    set_value_bdll(&third_linked_list, 15);
    set_value_bdll(&fourth_linked_list, 20);

    
    insert_node_head_bdll(&linked_list, &second_linked_list);
    insert_node_head_bdll(&second_linked_list, &third_linked_list);
    insert_node_head_bdll(&third_linked_list, &fourth_linked_list);

    return 1;
}