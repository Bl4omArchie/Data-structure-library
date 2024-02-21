# Data structure and algorithm


In this readme I give more technical explanation about my algorithms.

## Op struct


### Predict carry

For an efficient parallelization of operation between linked list, I have to predict before the operation if the result will give a carry so I can avoid useless computation.

**The idea**: The algo is comparing each bit of a and b from MSB to LSB. 
1) I'm first taking the MSB from a and b, if they are both equal to 1, then c (the carry) equal 1 and we exit.
2) If they are both equals to 0, we exit. 
3) If they equal 0 and 1, c = 0 and we continue.
 

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