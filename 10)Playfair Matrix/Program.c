#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

void findPos(char ch, int *row, int *col) {
    if(ch == 'J')
        ch = 'I';
	int i,j;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encryptPair(char a, char b) {
    int r1,c1,r2,c2;

    findPos(a,&r1,&c1);
    findPos(b,&r2,&c2);

    if(r1 == r2) {
        printf("%c%c",
               matrix[r1][(c1+1)%5],
               matrix[r2][(c2+1)%5]);
    }
    else if(c1 == c2) {
        printf("%c%c",
               matrix[(r1+1)%5][c1],
               matrix[(r2+1)%5][c2]);
    }
    else {
        printf("%c%c",
               matrix[r1][c2],
               matrix[r2][c1]);
    }
}

int main() {
    char plaintext[] = "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";
    int len = strlen(plaintext);
	int i;
    printf("Ciphertext:\n");

    for(i = 0; i < len; i += 2) {
        char a = plaintext[i];
        char b;

        if(i + 1 < len)
            b = plaintext[i + 1];
        else
            b = 'X';

        if(a == b) {
            b = 'X';
            i--;
        }

        encryptPair(a, b);
    }

    printf("\n");
    return 0;
}
