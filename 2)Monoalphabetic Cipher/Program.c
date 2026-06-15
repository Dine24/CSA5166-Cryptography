#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to encrypt using monoalphabetic substitution
void encrypt(char text[], char key[]) {
	int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            if (isupper(ch)) {
                text[i] = toupper(key[ch - 'A']);
            } else {
                text[i] = tolower(key[ch - 'a']);
            }
        }
    }
}

// Function to decrypt using monoalphabetic substitution
void decrypt(char text[], char key[]) {
    char reverseKey[26];
    int i;
    for (i = 0; i < 26; i++) {
        reverseKey[key[i] - 'A'] = 'A' + i;
    }

    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            if (isupper(ch)) {
                text[i] = reverseKey[ch - 'A'];
            } else {
                text[i] = tolower(reverseKey[toupper(ch) - 'A']);
            }
        }
    }
}

int main() {
    char text[100];
    // Example substitution key (must be a permutation of A–Z)
    char key[26] = {'Q','W','E','R','T','Y','U','I','O','P',
                    'A','S','D','F','G','H','J','K','L','Z',
                    'X','C','V','B','N','M'};

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // remove newline

    encrypt(text, key);
    printf("Encrypted message: %s\n", text);

    decrypt(text, key);
    printf("Decrypted message: %s\n", text);

    return 0;
}
