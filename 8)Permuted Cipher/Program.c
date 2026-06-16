#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char keyword[] = "CIPHER";
    char plain[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipher[27] = "";
    int used[26] = {0};
    int i, j = 0;

    // Add keyword letters to cipher alphabet
    for(i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);

        if(!used[ch - 'A']) {
            cipher[j++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    // Add remaining unused letters
    for(i = 0; i < 26; i++) {
        if(!used[i]) {
            cipher[j++] = 'A' + i;
        }
    }
    cipher[j] = '\0';

    printf("Plain : ");
    for(i = 0; i < 26; i++)
        printf("%c ", plain[i]);

    printf("\nCipher: ");
    for(i = 0; i < 26; i++)
        printf("%c ", cipher[i]);

    // Encryption
    char text[100];
    printf("\n\nEnter plaintext: ");
    scanf(" %[^\n]", text);

    printf("Ciphertext: ");

    for(i = 0; text[i] != '\0'; i++) {
        if(isalpha(text[i])) {
            char ch = toupper(text[i]);
            printf("%c", cipher[ch - 'A']);
        } else {
            printf("%c", text[i]);
        }
    }

    printf("\n");

    return 0;
}
