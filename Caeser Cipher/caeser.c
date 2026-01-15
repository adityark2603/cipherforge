#include <stdio.h>
#include <ctype.h>

void caesar(char text[], int key) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + key) % 26 + base;
        }
    }
}

int main() {
    char msg[] = "HELLO";
    caesar(msg, 3);
    printf("Encrypted: %s\n", msg);
    return 0;
}
