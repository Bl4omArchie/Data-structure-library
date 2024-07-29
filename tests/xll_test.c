#include "ll_tests.h"




int main_xll_test() {
    xll_node *head = (xll_node*)malloc(sizeof(xll_node));
    xll_init(head);
    xll_set_value(head, 10);
    
    xll_insert_value_head(head, 20);
    xll_insert_value_tail(head, 30);
    xll_insert_value_head(head, 40);
    xll_insert_value_tail(head, 50);
    
    printf("List after insertions: ");
    xll_display(head);
    
    xll_node *node_to_remove = xll_xor_nodes(NULL, head->ht_node); // remove the first node after head
    xll_remove_node(node_to_remove);

    printf("List after removal: ");
    xll_display(head);

    xll_clear_tail(head);
    printf("List after clearing values: ");
    xll_display(head);

    xll_free_tail(head);

    return 1;
}