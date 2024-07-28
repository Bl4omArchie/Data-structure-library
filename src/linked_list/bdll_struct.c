#include "ll_struct.h"



void init_bdll(Node_BDLL *node) {
    node->head = NULL;
    node->tail = NULL;
    node->branch = NULL;
    node->value = 0;
}

void set_value_bdll(Node_BDLL *node, uint64_t value) {
    // If negative number you add, messed up your linked list will be. Are allowed positive numbers only !!!
    node->value = value & 0x7FFFFFFFFFFFFFFF;
}


int insert_branch_bdll(Node_BDLL *node, uint64_t value) {
    if (node == NULL)
        return -1;

    Node_BDLL *newNode = (Node_BDLL*)malloc(sizeof(Node_BDLL));
    init_bdll(newNode);
    set_value_bdll(newNode, value);
    
    if (node->branch != NULL) {
        node->branch->head = newNode;
        newNode->tail = node->branch;
    }
    else
        newNode->tail = node->tail;
    
    node->branch = newNode;

    return 1;
}

int insert_head_bdll(Node_BDLL *node, uint64_t value) {
    return 1;
}

int insert_tail_bdll(Node_BDLL *node, uint64_t value) {
    return 1;
}


int insert_node_branch_bdll(Node_BDLL *node, Node_BDLL *to_replace);
int insert_node_head_bdll(Node_BDLL *node, Node_BDLL *to_replace);
int insert_node_tail_bdll(Node_BDLL *node, Node_BDLL *to_replace);

int remove_node_BDLL(Node_BDLL *node);
int remove_branch_BDLL(Node_BDLL *node);

int clear_bdll(Node_BDLL *node);
int clear_branch_bdll(Node_BDLL *node);
int clear_head_bdll(Node_BDLL *node);
int clear_tail_bdll(Node_BDLL *node);

int free_bdll(Node_BDLL *node);
int free_branch_bdll(Node_BDLL *node);
int free_head_bdll(Node_BDLL *node);
int free_tail_bdll(Node_BDLL *node);

void display_tail_bdll(Node_BDLL *node) {
    printf ("%ld", node->value);
}