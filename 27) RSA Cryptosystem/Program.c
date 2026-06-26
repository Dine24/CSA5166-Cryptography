#include <stdio.h>

// Fast modular exponentiation
long long modExp(long long base, long long exp, long long mod)
{
    long long result = 1;
    base %= mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

int main()
{
    long long e, n;
    int i;

    printf("Enter public key e: ");
    scanf("%lld", &e);

    printf("Enter modulus n: ");
    scanf("%lld", &n);

    printf("\nLookup Table (Dictionary Attack)\n");
    printf("----------------------------------\n");
    printf("Letter\tPlain\tCipher\n");

    for(i = 0; i < 26; i++)
    {
        printf("%c\t%d\t%lld\n",
               'A' + i,
               i,
               modExp(i, e, n));
    }

    printf("\nConclusion:\n");
    printf("Since only 26 plaintext values exist,\n");
    printf("an attacker can encrypt all of them using the public key\n");
    printf("and create a lookup table to decrypt any message.\n");
    printf("Hence, encrypting each letter separately with RSA is NOT secure.\n");

    return 0;
}
