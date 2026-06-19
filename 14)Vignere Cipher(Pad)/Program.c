#include <stdio.h>
#include <string.h>

int main() {
    char plaintext[] = "SENDMOREMONEY";
    int key[] = {9,0,1,7,23,15,21,14,11,11,2,8,9};

    int len = strlen(plaintext);
    char cipher[20];

    printf("Ciphertext: ");
	int i;
    for(i=0;i<len;i++) {
        int p = plaintext[i] - 'A';
        int c = (p + key[i]) % 26;

        cipher[i] = c + 'A';
        printf("%c", cipher[i]);
    }

    cipher[len] = '\0';

    printf("\n");

    return 0;
}
