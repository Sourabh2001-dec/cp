# Operators
- preincrementor (++i) => uses the incremented value
- postincrementor (i++) => uses the original value and then increments it

```c++
*Example*

    int i = 0;
    i = i++ - --i + ++i - i--;
        0->1  0      1    1->0
        0 - 0 + 1 - 1 = 0
    
    i becomes 0
```

# Bitwise operators
```c++
& - AND
| - OR
^ - XOR (SAME IS 0)
~ - 1'S COMPLEMENT
<< - LEFT SHIFT (a << n => a * 2^n)
>> - RIGHT SHIFT  (a >> n => a / 2^n)
```

# Tips

1. For row column based problems find if the positions can give any info
