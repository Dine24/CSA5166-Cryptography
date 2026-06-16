#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to prepare the key matrix
void generateKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    int used[26] = {0};
    int k = 0;

    // Treat 'J' as 'I'
    used['J' - 'A'] = 1;

    // Fill matrix with keyword
    int i;
    for (i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (isalpha(ch) && !used[ch - 'A']) {
            keyMatrix[k / SIZE][k % SIZE] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    // Fill remaining letters
    char ch;
    for (ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            keyMatrix[k / SIZE][k % SIZE] = ch;
            k++;
        }
    }
}

// Function to find position of a letter in the matrix
void findPosition(char keyMatrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; // Treat J as I
    int i;
    int j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to prepare plaintext (remove spaces, handle duplicates)
void prepareText(char text[], char prepared[]) {
    int len = 0;
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            prepared[len++] = toupper(text[i]);
        }
    }
    prepared[len] = '\0';

    // Insert 'X' between duplicate letters in a digraph
    char temp[200];
    int k = 0;
    for (i = 0; i < len; i++) {
        temp[k++] = prepared[i];
        if (i < len - 1 && prepared[i] == prepared[i + 1]) {
            temp[k++] = 'X';
        }
    }
    if (k % 2 != 0) temp[k++] = 'X'; // Pad if odd length
    temp[k] = '\0';
    strcpy(prepared, temp);
}

// Function to encrypt using Playfair cipher
void encrypt(char prepared[], char keyMatrix[SIZE][SIZE], char encrypted[]) {
    int len = strlen(prepared);
    int k = 0;
	int i=0;
    for (i = 0; i < len; i += 2) {
        int r1, c1, r2, c2;
        findPosition(keyMatrix, prepared[i], &r1, &c1);
        findPosition(keyMatrix, prepared[i + 1], &r2, &c2);

        if (r1 == r2) { // Same row
            encrypted[k++] = keyMatrix[r1][(c1 + 1) % SIZE];
            encrypted[k++] = keyMatrix[r2][(c2 + 1) % SIZE];
        } else if (c1 == c2) { // Same column
            encrypted[k++] = keyMatrix[(r1 + 1) % SIZE][c1];
            encrypted[k++] = keyMatrix[(r2 + 1) % SIZE][c2];
        } else { // Rectangle swap
            encrypted[k++] = keyMatrix[r1][c2];
            encrypted[k++] = keyMatrix[r2][c1];
        }
    }
    encrypted[k] = '\0';
}

int main() {
    char key[100], text[200], prepared[200], encrypted[200];
    char keyMatrix[SIZE][SIZE];
	int i;
	int j;
    printf("Enter keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    generateKeyMatrix(key, keyMatrix);

    printf("Key Matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", keyMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    prepareText(text, prepared);
    encrypt(prepared, keyMatrix, encrypted);

    printf("Prepared plaintext: %s\n", prepared);
    printf("Encrypted text: %s\n", encrypted);

    return 0;
}

