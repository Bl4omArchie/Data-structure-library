#include "ll_tests.h"




int main_xll_test() {
    Node_XLL *head = (Node_XLL*)malloc(sizeof(Node_XLL));
    init_xll(head);
    set_value_xll(head, 10);
    
    insert_head_xll(head, 20);
    insert_tail_xll(head, 30);
    insert_head_xll(head, 40);
    insert_tail_xll(head, 50);
    
    printf("List after insertions: ");
    display_xll(head);
    
    Node_XLL *node_to_remove = xor_nodes(NULL, head->ht_node); // remove the first node after head
    remove_node_XLL(node_to_remove);

    printf("List after removal: ");
    display_xll(head);

    clear_tail_xll(head);
    printf("List after clearing values: ");
    display_xll(head);

    free_tail_xll(head);

    return 1;
}