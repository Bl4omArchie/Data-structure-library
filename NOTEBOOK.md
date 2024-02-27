# Linked List implementation - Definition, techniques and examples

This notebook is a chronology of the improvement of my library. I'm starting from scratch where I started and I'm explaining how I managed to made this project. 

## Introduction

### Context

Data structure are a way to store informations. Actually there are differents techniques to do so: array, hash tables, graphs, stacks/queues, trees and linked list. Each of them has their own specificities but here we have a fixed subject: linked list, so we won't talk about differences between data structure. 
For further reading I suggest you geeksforgeeks's website which resume and lead to various documentation about each type of data structure.
The post is called: [Data Structures Tutorial](https://www.geeksforgeeks.org/data-structures/).

**NOTE** The code in this readme is evolving, first I give a simple definition and implementation but when I add new features, the code can change. So for instance the structures I'm presenting below are no more in the last version of my code. 

### Definition 

So what is a linked list ?
-> Linked list is a data structure where each element contains a data element of some type and a pointer to the next item in the list. It is easy to insert and delete elements in a linked list, which are not natural operations on arrays, since arrays have a fixed size. 


### Types of Linked List

There exists several types of Linked List:
- Linked List: the most basic one where you have only one pointer that lead to the tail element
- Doubly LL: point both at the tail and head element 
- Circular LL: the last element of your linked list point to the head
- XOR LL:  a doubly LL but the head and tail pointers of an element are xored together so you only have one pointer for both. This type if useful for memory optimization and small hardware

Here I'm going to implement Doubly Linked List because it is more efficient for what I'm aiming to do later.

## Techniques and methods

### Structures

First we need to create a structure that represent the Doubly Linked list. We have two ways to do this.

- with two representations:
The first struct represent the Linked List itself and the second one represent an Element. The advantage of this method is that we keep an eye on the first and last element which can be an advantage depending on how you are implementing yours prototypes. But in the other hand, this method can be unconfortable for prototypes implemetations (ie: more steps for the adding feature).
```c
typedef struct Element {
    uint64_t data;
    struct Element* next;
    struct Element* prev;
} Element;

// Structure DoublyLinkedList
typedef struct DoublyLinkedList {
    Element* head;
    Element* tail;
} DoublyLinkedList;
```

- self contained structure:
With the second method, we are merging the representation of the global struct and an element into one single structure. This representation is lighter and personnaly I prefer this one.  
```c
struct DoublyLinkedList {
    int value;
    DoublyLinkedList *next;
    DoublyLinkedList *prev;
};
```

### Features and prototypes

To make a linked list work, you need some basic operations. There is a list of the most important ones:
```
- Initialization
- Insertion
- Deletion
- Clear and Free memory
```

For each operation, you have several prototypes to make depending on where and how your perform the operation. For instance, you can Insert a data (int) or an element (struct) to your list at the head or at the tail. Which give us this:
```c
int insert_element_head(DoublyLinkedList *linked_list, DoublyLinkedList *element);
int insert_element_tail(DoublyLinkedList *linked_list, DoublyLinkedList *element);
int insert_data_head(DoublyLinkedList *linked_list, uint64_t data);
int insert_data_tail(DoublyLinkedList *linked_list, uint64_t data);
```
In the header file of my project, you can find further details about each prototypes.