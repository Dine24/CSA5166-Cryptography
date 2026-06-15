#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt using Vigenère cipher
void encrypt(char text[], char key[], char encrypted[]) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int j = 0;
	int i;
    for (i = 0; i < textLen; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char kch = toupper(key[j % keyLen]) - 'A'; // shift from key
            encrypted[i] = (ch - base + kch) % 26 + base;
            j++;
        } else {
            encrypted[i] = ch; // keep non-letters unchanged
        }
    }
    encrypted[textLen] = '\0';
}

// Function to decrypt using Vigenère cipher
void decrypt(char text[], char key[], char decrypted[]) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int j = 0;
	int i;
    for (i = 0; i < textLen; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char kch = toupper(key[j % keyLen]) - 'A'; // shift from key
            decrypted[i] = (ch - base - kch + 26) % 26 + base;
            j++;
        } else {
            decrypted[i] = ch;
        }
    }
    decrypted[textLen] = '\0';
}

int main() {
    char text[200], key[50], encrypted[200], decrypted[200];

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // remove newline

    printf("Enter key (alphabetic only): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    encrypt(text, key, encrypted);
    printf("Encrypted text: %s\n", encrypted);

    decrypt(encrypted, key, decrypted);
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}
