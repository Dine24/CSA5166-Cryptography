#include <stdio.h>
#include <conio.h>

int gcdExtended(int a, int b, int *x, int *y)
{
    int x1, y1;
    int gcd;

    if(a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main()
{
    int p = 59;
    int q = 61;

    int n;
    int phi;
    int e = 31;

    int x, y;
    int d;

    n = p * q;
    phi = (p - 1) * (q - 1);

    gcdExtended(e, phi, &x, &y);

    d = (x % phi + phi) % phi;

    printf("p = %d\n", p);
    printf("q = %d\n", q);
    printf("n = %d\n", n);
    printf("phi(n) = %d\n", phi);

    printf("\nPublic Key : (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);

    getch();
    return 0;
}
