# 🔐 Caeser Cipher
The Caesar Cipher is a **substitution cipher** in which each letter of the plaintext is shifted forward by a fixed number of positions in the alphabet.

#### 📘 Encryption Equation

$$\[
E(x) = (x + K) \bmod 26
\]$$

#### 📕 Decryption Equation

$$\[
D(x) = (x - K) \bmod 26
\]$$

Where:
- `x` = letter position (`A = 0, B = 1, ..., Z = 25`)
- `K` = key (here, **K = 3**)

#### <ins>Example:</ins>
Encrypting `aditya` (K = 3) 

| Plaintext | a | d | i | t | y | a |
|----------|---|---|---|---|---|---|
| **Shift +3** | d | g | l | w | b | d |


