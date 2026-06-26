#include <stdio.h>

// Function to find GCD
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Modular inverse
long long modInverse(long long e, long long phi)
{
    long long d = 1;

    while ((d * e) % phi != 1)
        d++;

    return d;
}

int main()
{
    long long p, q, n, phi;
    long long e1, d1;
    long long e2, d2;

    printf("Enter prime p: ");
    scanf("%lld", &p);

    printf("Enter prime q: ");
    scanf("%lld", &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("Enter Bob's original public key (e1): ");
    scanf("%lld", &e1);

    if (gcd(e1, phi) != 1)
    {
        printf("Invalid public key.\n");
        return 0;
    }

    d1 = modInverse(e1, phi);

    printf("\nOriginal Keys\n");
    printf("Public Key (e1, n) = (%lld, %lld)\n", e1, n);
    printf("Private Key d1 = %lld\n", d1);

    printf("\n*** Assume d1 is leaked ***\n");

    printf("\nEnter a new public key (e2): ");
    scanf("%lld", &e2);

    if (gcd(e2, phi) != 1)
    {
        printf("Invalid new public key.\n");
        return 0;
    }

    d2 = modInverse(e2, phi);

    printf("\nNew Keys (Same Modulus)\n");
    printf("Public Key (e2, n) = (%lld, %lld)\n", e2, n);
    printf("Private Key d2 = %lld\n", d2);

    printf("\nConclusion:\n");
    printf("Reusing the same modulus n is NOT SAFE.\n");
    printf("An attacker who knows the old private key can compute phi(n),\n");
    printf("factor n, and derive every future private key using the same modulus.\n");
    printf("Bob must generate new primes p and q and a new modulus n.\n");

    return 0;
}
