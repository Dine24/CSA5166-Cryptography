#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

/* Generate Playfair matrix */
void generateMatrix(char key[]) {
    int used[26] = {0};
    int r = 0, c = 0;

    used['J' - 'A'] = 1; // I/J combined
    
    int i;

    for (i = 0; key[i]; i++) {
        char ch = toupper(key[i]);

        if (ch < 'A' || ch > 'Z')
            continue;

        if (ch == 'J')
            ch = 'I';

        if (!used[ch - 'A']) {
            matrix[r][c++] = ch;
            used[ch - 'A'] = 1;

            if (c == 5) {
                r++;
                c = 0;
            }
        }
    }
	char ch;
    for (ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[r][c++] = ch;

            if (c == 5) {
                r++;
                c = 0;
            }
        }
    }
}

/* Find position of character */
void findPos(char ch, int *row, int *col) {
    if (ch == 'J')
        ch = 'I';
	int i,j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

/* Decrypt Playfair cipher */
void decrypt(char cipher[]) {
    int len = strlen(cipher);

    printf("Plaintext:\n");
    int i;

    for (i = 0; i < len; i += 2) {
        int r1, c1, r2, c2;

        findPos(cipher[i], &r1, &c1);
        findPos(cipher[i + 1], &r2, &c2);

        if (r1 == r2) {
            printf("%c%c",
                   matrix[r1][(c1 + 4) % 5],
                   matrix[r2][(c2 + 4) % 5]);
        }
        else if (c1 == c2) {
            printf("%c%c",
                   matrix[(r1 + 4) % 5][c1],
                   matrix[(r2 + 4) % 5][c2]);
        }
        else {
            printf("%c%c",
                   matrix[r1][c2],
                   matrix[r2][c1]);
        }
    }
    printf("\n");
}

int main() {
    char key[] = "ROYAL NEW ZEALAND NAVY";

    char cipher[] =
    "KXJEYUREBEZWEHEWRYTUHEYFS"
    "KREHEGOYFIWTTTUOLKSYCAJPO"
    "BOTEIZONTXBYBNTGONEYCUZWR"
    "GDSONSXBOUYWRHEBAAHYUSEDQ";

    generateMatrix(key);

    printf("Playfair Key Matrix:\n");
    
    int i,j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    printf("\n");
    decrypt(cipher);

    return 0;
}
