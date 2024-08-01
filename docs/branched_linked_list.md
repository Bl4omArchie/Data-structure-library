# Branched Linked List

What I called Branched Linked List is a type of Linked List where you add one more pointer in the struct. This additionnal pointer lead to another linked list wich finally lead back to the tail of the parent node.

See the struct as follow:

```c
typedef struct BranchedDoublyLinkedList {
    uint64_t value;
    struct BranchedDoublyLinkedList *head;
    struct BranchedDoublyLinkedList *tail;
    struct BranchedDoublyLinkedList *branch;
} bdll_node;
```

This new data structure can be represented like this:

 Node 1
   |
   | ---> Branch 1 ---> Branch 2
   |                      |
   |                      |
 Node 2 <------------------


The point of such a data structure is to perform computation on several cluster of data. For instance, if you want to make computation on a bunch of contract, you can linked each contract within a branched linked list and make your operation in a single row.