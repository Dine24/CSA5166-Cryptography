#include <stdio.h>
#include <conio.h>

int main()
{
    unsigned char IV = 0xAA;      /* 10101010 */
    unsigned char KEY = 0xFD;     /* 11111101 */

    unsigned char P1 = 0x01;      /* 00000001 */
    unsigned char P2 = 0x23;      /* 00100011 */

    unsigned char C1, C2;
    unsigned char D1, D2;

    /* CBC Encryption */

    C1 = (P1 ^ IV) ^ KEY;
    C2 = (P2 ^ C1) ^ KEY;

    printf("CBC Encryption\n");
    printf("Cipher Block 1 = %02X\n", C1);
    printf("Cipher Block 2 = %02X\n", C2);

    /* CBC Decryption */

    D1 = (C1 ^ KEY) ^ IV;
    D2 = (C2 ^ KEY) ^ C1;

    printf("\nCBC Decryption\n");
    printf("Plain Block 1 = %02X\n", D1);
    printf("Plain Block 2 = %02X\n", D2);

    getch();
    return 0;
}
