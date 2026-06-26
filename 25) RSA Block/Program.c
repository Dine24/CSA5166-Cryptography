#include <stdio.h>

// Function to find GCD
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    long long p, q, n;
    long long plaintext;

    printf("Enter value of p: ");
    scanf("%lld", &p);

    printf("Enter value of q: ");
    scanf("%lld", &q);

    n = p * q;

    printf("Modulus n = %lld\n", n);

    printf("Enter a plaintext block: ");
    scanf("%lld", &plaintext);

    long long factor = gcd(plaintext, n);

    if (factor == 1)
    {
        printf("\nNo common factor found.\n");
        printf("The plaintext does not help in factoring n.\n");
    }
    else if (factor == n)
    {
        printf("\nPlaintext equals a multiple of n.\n");
    }
    else
    {
        printf("\nCommon factor found!\n");
        printf("Factor = %lld\n", factor);
        printf("Other factor = %lld\n", n / factor);
        printf("\nHence, n has been factored successfully.\n");
        printf("RSA security is broken.\n");
    }

    return 0;
}
