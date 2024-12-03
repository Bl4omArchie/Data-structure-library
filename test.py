def mult_bin(a, b):
    res = 0
    while b:
        if b & 1:
            tmp_a = a
            while tmp_a:
                res ^= tmp_a
                tmp_a = ((res^tmp_a) & tmp_a)<<1
        a <<= 1
        b >>= 1

    return res

print (mult_bin(50, 3))