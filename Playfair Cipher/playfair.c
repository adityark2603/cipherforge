#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

/* Generate 5x5 Playfair Matrix */
void generateMatrix(char key[]) {
    int used[26] = {0};
    used['J' - 'A'] = 1;

    int k = 0;
    for (int i = 0; key[i]; i++) {
        char c = toupper(key[i]);
        if (c < 'A' || c > 'Z') continue;
        if (!used[c - 'A']) {
            matrix[k / 5][k % 5] = c;
            used[c - 'A'] = 1;
            k++;
        }
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        if (!used[c - 'A']) {
            matrix[k / 5][k % 5] = c;
            k++;
        }
    }
}

/* Find position of character in matrix */
void findPosition(char c, int *r, int *c2) {
    if (c == 'J') c = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == c) {
                *r = i;
                *c2 = j;
            }
}

/* Prepare plaintext */
void prepareText(char text[]) {
    char temp[100];
    int k = 0;

    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char c = toupper(text[i]);
            if (c == 'J') c = 'I';
            temp[k++] = c;
        }
    }

    temp[k] = '\0';
    strcpy(text, temp);

    for (int i = 0; i < strlen(text); i += 2) {
        if (text[i] == text[i + 1]) {
            memmove(&text[i + 2], &text[i + 1], strlen(text) - i);
            text[i + 1] = 'X';
        }
    }

    if (strlen(text) % 2 != 0)
        strcat(text, "X");
}

/* Encrypt */
void playfairEncrypt(char text[]) {
    for (int i = 0; i < strlen(text); i += 2) {
        int r1, c1, r2, c2;
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            printf("%c%c ", matrix[r1][(c1 + 1) % 5], matrix[r2][(c2 + 1) % 5]);
        } else if (c1 == c2) {
            printf("%c%c ", matrix[(r1 + 1) % 5][c1], matrix[(r2 + 1) % 5][c2]);
        } else {
            printf("%c%c ", matrix[r1][c2], matrix[r2][c1]);
        }
    }
}

int main() {
    char key[50], text[100];

    printf("Enter key: ");
    gets(key);

    printf("Enter plaintext: ");
    gets(text);

    prepareText(text);
    generateMatrix(key);

    printf("\nCiphertext:\n");
    playfairEncrypt(text);

    return 0;
}
