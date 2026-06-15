#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to find GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to encrypt using Affine Cipher
void affineEncrypt(char text[], int a, int b) {
    int i;
    
    // Check if 'a' is valid
    if (gcd(a, 26) != 1) {
        printf("Error: 'a' must be coprime with 26 for a valid Affine Cipher.\n");
        return;
    }

    printf("Ciphertext: ");

    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isupper(ch)) {
            int p = ch - 'A';
            int c = (a * p + b) % 26;
            printf("%c", c + 'A');
        }
        else if (islower(ch)) {
            int p = ch - 'a';
            int c = (a * p + b) % 26;
            printf("%c", c + 'a');
        }
        else {
            printf("%c", ch); // Keep spaces and symbols unchanged
        }
    }
    printf("\n");
}

int main() {
    char plaintext[100];
    int a, b;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    affineEncrypt(plaintext, a, b);

    return 0;
}
