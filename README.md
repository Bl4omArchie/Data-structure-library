# Linked List implementation - Definition, techniques and examples

This project goals is to understand linked list, examine techniques to implement it and finally, find an optimal way to implement this data structure.


## Introduction

### Context

Data structure are a way to store informations. Actually there are differents techniques to do so: array, hash tables, graphs, stacks/queues, trees and linked list. Each of them has their own specificities but here we have a fixed subject: linked list, so we won't talk about differences between data structure. 
For further reading I suggest you geeksforgeeks's website which resume and lead to various documentation about each type of data structure.
The post is called: [Data Structures Tutorial](https://www.geeksforgeeks.org/data-structures/).

### Definition 

So what is a linked list ?
-> Linked list is a data structure where each element contains a data element of some type and a pointer to the next item in the list. It is easy to insert and delete elements in a linked list, which are not natural operations on arrays, since arrays have a fixed size. 

You also may heard of **Doubly Linked List**. This means that each item contains not only a pointer to the next item but also on the previous one. In this project, we'll use a doubly linked list.


## Techniques and methods

### Structures

First we need to create a structure to represent the Linked list. We have two ways to do this.

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
With the second method, we are merging the representation of the global struct and an element into one single structure. This representation is lighter and personnaly, I prefer this **one**.  
```c
struct DoublyLinkedList {
    int value;
    DoublyLinkedList *next;
    DoublyLinkedList *prev;
};
```

### Features and rototypes

Now, we'll talk about the prototype to implement in order to make our linked list work. No matters what methods you chosed previously (the idea stay the same but you have to thing slightly differently), this what you will need to implement:

```
- Initialization
- Insertion
- Deletion
- Clear and Free memory
```




Some prototypes can be added but aren't mandatory:
```c
void print_doubly_linked(DoublyLinkedList *f);
bool is_empty(const DoublyLinkedList *f);
Element find(DoublyLinkedList *f, uint64_t v);
Element find_next(DoublyLinkedList *f, uint64_t v);
Element find_previous(DoublyLinkedList *f, uint64_t v);
```



# Sources
- [Les listes doublement chaînées en C](https://nicolasj.developpez.com/articles/listedouble/#LIII-C)
- [Programmation algorithmique/Listes doublement chaînées](https://fr.wikibooks.org/wiki/Programmation_algorithmique/Listes_doublement_cha%C3%AEn%C3%A9es)
- [Linked List Basics - by Nick Parlante](http://cslibrary.stanford.edu/103/LinkedListBasics.pdf)
- [Lecture Notes on Linked Lists - by Frank Pfenning, Rob Simmons, Andr´e Platzer, September 30, 2014](https://www.cs.cmu.edu/~rjsimmon/15122-f14/lec/11-linkedlist.pdf)
- [Linked Lists - Computer Science E-22 - Harvard University, David G. Sullivan, Ph.D](https://cscie22.sites.fas.harvard.edu/files/lectures/04_linked_lists.pdf)
- [Data Structures Tutorial](https://www.geeksforgeeks.org/data-structures/)