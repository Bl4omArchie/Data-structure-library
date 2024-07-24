#include "includes/ll_struct.h" 
// #include "includes/ll_tests.h" 




int main() {

    //main_dll_test();
    //main_bdll_test();

    Node_DLL linked_list, second_linked_list, third_linked_list, fourth_linked_list;
    init_dll(&linked_list);
    init_dll(&second_linked_list);
    init_dll(&third_linked_list);
    init_dll(&fourth_linked_list);


    set_value_dll(&linked_list, 5);
    set_value_dll(&second_linked_list, 10);
    set_value_dll(&third_linked_list, 15);
    set_value_dll(&fourth_linked_list, 20);

    
    insert_node_head_dll(&linked_list, &second_linked_list);
    insert_node_head_dll(&second_linked_list, &third_linked_list);
    insert_node_head_dll(&third_linked_list, &fourth_linked_list);

    display_tail_dll(&fourth_linked_list);
    free_dll(&third_linked_list);
    display_tail_dll(&fourth_linked_list);

    return 1;
}