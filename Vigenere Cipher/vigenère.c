#include <stdio.h>
#include <ctype.h>
#include <string.h>

void vigenere(char text[], char key[]) {
    int j = 0, klen = strlen(key);
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int shift = toupper(key[j % klen]) - 'A';
            text[i] = (text[i] - base + shift) % 26 + base;
            j++;
        }
    }
}

int main() {
    char msg[] = "HELLO";
    char key[] = "KEY";
    vigenere(msg, key);
    printf("Encrypted: %s\n", msg);
    return 0;
}
