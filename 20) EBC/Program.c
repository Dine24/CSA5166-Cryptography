#include <stdio.h>
#include <conio.h>

int main()
{
    int P1 = 10, P2 = 20, P3 = 30;
    int Key = 5;

    int C1, C2, C3;
    int D1, D2, D3;

    /* ECB Encryption */
    C1 = P1 ^ Key;
    C2 = P2 ^ Key;
    C3 = P3 ^ Key;

    /* Introduce error in C1 */
    C1 = C1 ^ 1;

    /* ECB Decryption */
    D1 = C1 ^ Key;
    D2 = C2 ^ Key;
    D3 = C3 ^ Key;

    printf("=== ECB MODE ===\n");
    printf("Recovered P1 = %d\n", D1);
    printf("Recovered P2 = %d\n", D2);
    printf("Recovered P3 = %d\n", D3);

    printf("\nOnly P1 is affected by the error.\n");

    /* CBC Encryption */
    {
        int IV = 0;

        C1 = (P1 ^ IV) ^ Key;
        C2 = (P2 ^ C1) ^ Key;
        C3 = (P3 ^ C2) ^ Key;

        /* Error in transmitted C1 */
        C1 = C1 ^ 1;

        /* CBC Decryption */
        D1 = (C1 ^ Key) ^ IV;
        D2 = (C2 ^ Key) ^ C1;
        D3 = (C3 ^ Key) ^ C2;

        printf("\n=== CBC MODE ===\n");
        printf("Recovered P1 = %d\n", D1);
        printf("Recovered P2 = %d\n", D2);
        printf("Recovered P3 = %d\n", D3);

        printf("\nP1 and P2 are affected by the error.\n");
        printf("P3 is recovered correctly.\n");
    }

    getch();
    return 0;
}
