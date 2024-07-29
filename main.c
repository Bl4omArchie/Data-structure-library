#include "ll_struct.h" 
#include "ll_tests.h" 
#include "util.h"




int main() {
    
    display_specifications();
    
    //if (main_bdll_test())
        //printf ("End of DLL the test");


    dll_node node;
    dll_node second_node;

    dll_init(&node);
    dll_init(&second_node);
    dll_set_value(&node, 5);
    dll_set_value(&second_node, 10);

    dll_insert_value_tail(&node, 6);
    dll_insert_value_tail(node.tail, 7);
    dll_insert_value_tail(node.tail->tail, 8);
    dll_insert_value_tail(node.tail->tail->tail, 9);

    dll_insert_value_tail(&second_node, 11);
    dll_insert_value_tail(second_node.tail, 12);
    dll_insert_value_tail(second_node.tail->tail, 13);
    dll_insert_value_tail(second_node.tail->tail->tail, 14);

    dll_display_tail(&node);
    dll_insert_node_tail(&node, &second_node);
    dll_display_tail(&node);

    return 1;
}