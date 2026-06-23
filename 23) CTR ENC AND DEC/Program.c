#include <stdio.h>
#include <conio.h>

int main()
{
    unsigned char plaintext[3];
    unsigned char ciphertext[3];
    unsigned char decrypted[3];

    unsigned char key;
    unsigned char counter;

    int i;

    plaintext[0] = 0x01;   /* 00000001 */
    plaintext[1] = 0x02;   /* 00000010 */
    plaintext[2] = 0x04;   /* 00000100 */

    key = 0xFD;            /* 11111101 */
    counter = 0x00;

    printf("Encryption:\n");

    for(i=0; i<3; i++)
    {
        ciphertext[i] = plaintext[i] ^ (counter ^ key);

        printf("Cipher[%d] = %02X\n", i+1, ciphertext[i]);

        counter++;
    }

    counter = 0x00;

    printf("\nDecryption:\n");

    for(i=0; i<3; i++)
    {
        decrypted[i] = ciphertext[i] ^ (counter ^ key);

        printf("Plain[%d] = %02X\n", i+1, decrypted[i]);

        counter++;
    }

    getch();
    return 0;
}
