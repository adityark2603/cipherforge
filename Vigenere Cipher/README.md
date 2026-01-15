# 🔐 Vigenère Cipher
The Vigenère Cipher is a **polyalphabetic substitution cipher** that uses a repeating **keyword** to apply different Caesar shifts to each letter of the plaintext, making it more secure than the Caesar cipher.

#### 📘 Encryption Equation

$$\[
E(x_i) = (x_i + k_i) \bmod 26
\]$$

#### 📕 Decryption Equation

$$\[
D(x_i) = (x_i - k_i) \bmod 26
\]$$

Where:
- `x_i` = position of the *i-th* plaintext letter (`A = 0, ..., Z = 25`)
- `k_i` = position of the *i-th* key letter
- Key repeats to match plaintext length


#### <ins>Example:</ins>
**1. Without Autokey:** <br>
Plaintext: `attackatdawn` <br>
Key: `LEMONLEMONLE`

| Plaintext | a | t | t | a | c | k | a | t | d | a | w | n |
|----------|---|---|---|---|---|---|---|---|---|---|---|---|
| Key      | l | e | m | o | n | l | e | m | o | n | l | e |
| Shift    |11 | 4 |12 |14 |13 |11 | 4 |12 |14 |13 |11 | 4 |
| Cipher   | l | x | f | o | p | v | e | f | r | n | h | r |

Result: `lxfopv ef rnhr`

**2. With Autokey:** <br>
Plaintext: `attackatdawn` <br>
Key: `LEMONLATTACKA`

| Plaintext | a | t | t | a | c | k | a | t | d | a | w | n |
|----------|---|---|---|---|---|---|---|---|---|---|---|---|
| Autokey  | l | e | m | o | n | a | t | t | a | c | k | o |
| Shift    |11 | 4 |12 |14 |13 | 0 |19 |19 | 0 | 2 |10 |14 |
| Cipher   | l | x | f | o | p | k | t | m | d | c | g | b |

Result: `lxfopk tm dcgn`
