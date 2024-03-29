# Data structure implementation

This project goals are to understand linked list, examine techniques to implement it and finally, find an optimal way to implement this data structure. Later I would like to use it for a bignum structure and also make improvements with parallelization. <br/>
For the coding language, I'll use C and also C++ for tests with GoogleTest Framework.

## 🚚  Roadmap

#### Main branch:
- Priority:
  - Finish add_linked_list
  - Continue benchmark

- Minor priority:
  - Make data a generic pointer
  - Translate my Java associative array in C for this project

#### GoogleTest:
- Priority:
  - Import and compile GoogleTest
  - Write more tests

#### Xor Linked List
- Minor priority:
  - Understand how to implement xll
  - Test if replacing dll with wll worth it

## 🚧 TODO

Algorithms I'm currently coding:
- Algorithm 4.3
- Algorithm 2.2.1, 2.2.2 and 2.2.3
- Algorithm 3.1 and 3.2

Revision todo:
- Algorithm 2.3: I made some improvements but maybe I still can make improvement. 

## 📋 Algorithm listing
- 1)Linked List:
    - 1.1) init_dll
    - 1.2) set_data
    - 1.3) insert
        - 1.3.1) insert_element_head
        - 1.3.2) insert_element_tail
        - 1.3.3) insert_data_head
        - 1.3.4) insert_data_tail
        - 1.3.5) insert_data_linked_list_head
        - 1.3.6) insert_data_linked_list_tail
        - 1.3.7) insert_element_linked_list_head
        - 1.3.8) insert_element_linked_list_tail
    - 1.4) remove
    - 1.5) clear
        - 1.5.1) clear_linked_list
        - 1.5.2) clear_head_linked_list
        - 1.5.3) clear_tail_linked_list
    - 1.6) free
        - 1.6.1) free_linked_list
        - 1.6.2) free_head_linked_list
        - 1.6.3) free_tail_linked_list
    - 1.7) find
        - 1.7.1) find_head
        - 1.7.2) find_tail
    - 1.8) display

<br/>

- 2)Linked List Operation:
    - 2.1) add
        - 2.1.1) add_head
        - 2.1.2) add_tail
        - 2.1.3) add_head_range
        - 2.1.4) add_tail_range
        - 2.1.5) add_linked_list
    - 2.2) add_fork
        - 2.2.1) add_head_fork
        - 2.2.2) add_tail_fork
        - 2.2.3) add_linked_list_fork
    - 2.3) predict_carry

- 3)Assembly:
    - 3.1) add_binary_optimized
    - 3.2) sub_binary_optimized

- 4)Associative array:
  - 4.1) init_aa
  - 4.2) resize_aa

## Installation

1) Pull or download the repository
2) Install yasm compiler with:
```
sudo apt install yasm
```
3) Use make command:
```
make
make bench 
make test
```
4) Execute the corresponding binary:
```
./file.o
./bench.o
./test.o
```

## 📣 Author
You can contact me and see my work here:

- Blog: https://bl4omarchie.github.io/archX/
- Discord server: https://discord.com/invite/D2wGP62


## ✊ Acknowledgment

Thank to my friend [Jossl123](https://github.com/Jossl123) who supported and helped me during our many discussions while we where in class.

# 🔗Sources
- [Les listes doublement chaînées en C - by Nicolas Joseph - 20 july 2005](https://nicolasj.developpez.com/articles/listedouble/#LIII-C)
- [Programmation algorithmique/Listes doublement chaînées](https://fr.wikibooks.org/wiki/Programmation_algorithmique/Listes_doublement_cha%C3%AEn%C3%A9es)
- [Linked List Basics - by Nick Parlante](http://cslibrary.stanford.edu/103/LinkedListBasics.pdf)
- [Lecture Notes on Linked Lists - by Frank Pfenning, Rob Simmons, Andre Platzer - 30 september 2014](https://www.cs.cmu.edu/~rjsimmon/15122-f14/lec/11-linkedlist.pdf)
- [Linked Lists - Computer Science E-22 - Harvard University, David G. Sullivan, Ph.D](https://cscie22.sites.fas.harvard.edu/files/lectures/04_linked_lists.pdf)
- [Data Structures Tutorial](https://www.geeksforgeeks.org/data-structures/)
- [Parallel linked lists - Lecture 10 of TDA384/DIT391 Principles of Concurrent Programming, Gerardo Schneider](https://www.cse.chalmers.se/edu/course/TDA384_LP1/files/lectures/Lecture10-parallel_lists.pdf)
