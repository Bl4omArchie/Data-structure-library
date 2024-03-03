# Algorithm


In this document I give more technical explanation about my algorithms. Like a talk on how I end up writting this specific code rather than another.


## Op struct

Op_struct file implements operation like addition between linked list. 

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
Note: Maybe I can make further optimization by removing some steps with the many shift and AND operations.


### Assembly optimization

Addition and such operations could be done easily as we store only 64 bits numbers but as always I want to implement myself every piece of the process. So I started implementing myself arithmetic operations and it finally end with assembly code cause it is the best way to optimize programs.

## Addition

The first classic operation is the addition and to make an efficient algorithm you need to use base 2 numbers obviously. 
Addition in binary is the same as in decimal:
```
   1010
+  1111
------
  11001
```
From that I could easily come up with a first algorithm:
```
1- Take two numbers a and b and two other variables result and carry.
2- Xor a and b into result
3- (a & b) << 1 into carry
4- Repeat each steps from step 2 until carry = 0
5- Return result
```
Quickly the first thing I wanted to remove is the two variables result and carry. So I make this new algo:
```
1- Take two numbers a and b 
2- Xor a and b into a
3- (a & b) << 1 into b
4- Repeat each steps from step 2 until b = 0
5- Return result
```
But here we get a mistake! Indeed in step 3 we use a which already has been xored by b which falsed the result.
How to correct this ? I finded the anwser with 