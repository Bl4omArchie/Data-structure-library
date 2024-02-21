# Linked List implementation - Definition, techniques and examples

This project goals are to understand linked list, examine techniques to implement it and finally, find an optimal way to implement this data structure. Later I would like to use it for a bignum structure and also make improvements with parallelization. <br/>
For the coding language, I'll use C and also C++ for tests with GoogleTest Framework.

## Roadmap

### Main branch:
Priority:
- Make operation between linked list parallerlized 
- Continue benchmark

Futur work:
- Allow different types: 64 bits, 32 bits, 16 bits
- Translate my Java associative array in C for this project

### GoogleTest:
Priority:
- Import and compile GoogleTest
- Write more tests

### Xor Linked List
Minor priority:
- Understand how to implement xll
- Test if replacing dll with wll worth it


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


### Parallelization

Adding two linked list to each other is cool but adding them in parallel is cooler. So let's do this.


# Sources
- [Les listes doublement chaînées en C - by Nicolas Joseph - 20 july 2005](https://nicolasj.developpez.com/articles/listedouble/#LIII-C)
- [Programmation algorithmique/Listes doublement chaînées](https://fr.wikibooks.org/wiki/Programmation_algorithmique/Listes_doublement_cha%C3%AEn%C3%A9es)
- [Linked List Basics - by Nick Parlante](http://cslibrary.stanford.edu/103/LinkedListBasics.pdf)
- [Lecture Notes on Linked Lists - by Frank Pfenning, Rob Simmons, Andre Platzer - 30 september 2014](https://www.cs.cmu.edu/~rjsimmon/15122-f14/lec/11-linkedlist.pdf)
- [Linked Lists - Computer Science E-22 - Harvard University, David G. Sullivan, Ph.D](https://cscie22.sites.fas.harvard.edu/files/lectures/04_linked_lists.pdf)
- [Data Structures Tutorial](https://www.geeksforgeeks.org/data-structures/)
- [Parallel linked lists - Lecture 10 of TDA384/DIT391 Principles of Concurrent Programming, Gerardo Schneider](https://www.cse.chalmers.se/edu/course/TDA384_LP1/files/lectures/Lecture10-parallel_lists.pdf)