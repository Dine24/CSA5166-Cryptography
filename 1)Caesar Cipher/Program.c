#include <stdio.h>
#include <ctype.h>
#include <string.h>

void caesarCipher(char text[], int k) {
  int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + k) % 26 + base;
        }

        text[i] = ch;
    }
}

int main() {
    char text[100];
    int k;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character if present
    text[strcspn(text, "\n")] = '\0';

    printf("Enter shift (1-25): ");
    scanf("%d", &k);

    if (k < 1 || k > 25) {
        printf("Invalid shift value. Please enter between 1 and 25.\n");
        return 1;
    }

    caesarCipher(text, k);

    printf("Encrypted message: %s\n", text);

    return 0;
}
