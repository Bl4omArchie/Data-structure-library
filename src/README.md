# Data structure and algorithm


In this readme I give more technical explanation about my algorithms. I'm also listing all of them for a better overview.

- 1)Linked List:
    - 1.1) init_linked_list
    - 1.2) set_data
    - 1.3) insert
        - 1.3.1) insert_element_head
        - 1.3.2) insert_element_tail
        - 1.3.3) insert_data_head
        - 1.3.4) insert_data_tail
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


# TODO

Algorithms I'm coding actually:
- Algorithm 2.1.5
- Algorithm 2.2.3
- Algorithm 3.1

Revision todo:
- Algorithm 2.3

Potential revision on every Algorithm 1 depeding on how the struct is evolving.

## Op struct


### Predict carry

For an efficient parallelization of operation between linked list, I have to predict before the operation if the result will give a carry so I can avoid useless computation.

**The idea**: The algo is comparing each bit of a and b from MSB to LSB. 
1) I'm first taking the MSB from a and b, if they are both equal to 1, then c (the carry) equal 1 and we exit.
2) If they are both equals to 0, we exit. 
3) If they equal 0 and 1, c = 0 and we continue.

In short, this algorithm can end very quickly which is good.

Optimized algorithm:
```c
int predict_carry(uint64_t a, uint64_t b) {
    // v2
    int i = 63;
    int c = 0;

    while ( ((a>>i)&1 || (b>>i)&1) && i > 0 && c == 0) {
        c = ((a>>i)&1) && ((b>>i)&1);
        i--;
    }
    return c;
}
```

Maybe I can make further optimization by removing some steps with the many shift and AND operations.