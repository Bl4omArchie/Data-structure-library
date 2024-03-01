# Data structure implementation

This project goals are to understand linked list, examine techniques to implement it and finally, find an optimal way to implement this data structure. Later I would like to use it for a bignum structure and also make improvements with parallelization. <br/>
For the coding language, I'll use C and also C++ for tests with GoogleTest Framework.

## 🚚  Roadmap

#### Main branch:
Priority:
- Finish add_linked_list
- Fixing makefile for assembly compilation
- Make assembly optimization for arithmetic operations
- Continue benchmark

Minor priority:
- Allow different types: 64 bits, 32 bits, 16 bits
- Translate my Java associative array in C for this project

#### GoogleTest:
Priority:
- Import and compile GoogleTest
- Write more tests

#### Xor Linked List
Minor priority:
- Understand how to implement xll
- Test if replacing dll with wll worth it

## 🚧 TODO

Algorithms I'm coding actually:
- Algorithm 2.1.5
- Algorithm 2.2.3
- Algorithm 3.1

Revision todo:
- Algorithm 2.3

Potential revision on every Algorithm 1 depeding on how the struct is evolving.

## 📋 Algorithm listing
- 1)Linked List:
    - 1.1) init_linked_list
    - 1.2) set_data
    
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

- 2)Operation:
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
    - 3.1) add


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