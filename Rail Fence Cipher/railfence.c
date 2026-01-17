#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], clean[100];
    int rows, cols, k = 0;

    printf("Enter message: ");
    gets(text);

    printf("Enter rows: ");
    scanf("%d", &rows);

    printf("Enter columns: ");
    scanf("%d", &cols);

    for (int i = 0; text[i]; i++)
        if (isalpha(text[i]))
            clean[k++] = tolower(text[i]);

    while (k < rows * cols)
        clean[k++] = 'x';

    clean[k] = '\0';

    char matrix[rows][cols];
    k = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = clean[k++];

    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    printf("\nCiphertext: ");
    for (int j = 0; j < cols; j++)
        for (int i = 0; i < rows; i++)
            printf("%c", matrix[i][j]);

    return 0;
}
