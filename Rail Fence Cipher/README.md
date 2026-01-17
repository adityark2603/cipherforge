# 🔐 Rail Fence Cipher
The Rail Fence cipher is a transposition cipher that rearranges the letters of a message by writing them in a zigzag pattern across multiple “rails” and then reading them row by row.

#### <ins>Example:</ins>
```
Rail 1:  m   e   m   a   o   r   p   t
           \ / \ / \ / \ / \ / \ / \ /
Rail 2:    e   t   e   t   u   s   o
```

**4x4 Matrix:**
|   | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| R0 | m | e | e | t |
| R1 | m | e | a | t |
| R2 | o | u | r | s |
| R3 | p | o | t | X |


Column 0 → m m o p <br>
Column 1 → e e u o <br>
Column 2 → e a r t <br>
Column 3 → t t s X

**Ciphertext:**
`mmopeeuoearttts`
