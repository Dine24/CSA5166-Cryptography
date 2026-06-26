#include <stdio.h>

int main()
{
    unsigned int X, T;
    unsigned int secondBlock, forgedTag;

    printf("Enter one-block message (X): ");
    scanf("%u", &X);

    printf("Enter CBC-MAC of X (T): ");
    scanf("%u", &T);

    // Construct second block
    secondBlock = X ^ T;

    // Forged MAC
    forgedTag = T;

    printf("\nOriginal Message : %u\n", X);
    printf("Known MAC (T)    : %u\n", T);

    printf("\nForged Two-Block Message:\n");
    printf("Block 1 : %u\n", X);
    printf("Block 2 : %u (X XOR T)\n", secondBlock);

    printf("\nForged CBC-MAC = %u\n", forgedTag);

    printf("\nConclusion:\n");
    printf("MAC(K, X || (X XOR T)) = T\n");
    printf("The attacker can forge a valid MAC without knowing the secret key.\n");
    printf("Hence, basic CBC-MAC is insecure for variable-length messages.\n");

    return 0;
}
