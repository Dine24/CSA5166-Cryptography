#include <stdio.h>
#include <string.h>
#include <conio.h>

#define BLOCK_SIZE 8

int main()
{
    char msg[100];
    int len;
    int padBits;
    int totalLen;
    int i;

    printf("Enter message: ");
    gets(msg);

    len = strlen(msg);

    printf("\nOriginal Length = %d bytes\n", len);

    if(len % BLOCK_SIZE == 0)
    {
        /* Add an entire padding block */
        totalLen = len + BLOCK_SIZE;
        padBits = BLOCK_SIZE;
    }
    else
    {
        padBits = BLOCK_SIZE - (len % BLOCK_SIZE);
        totalLen = len + padBits;
    }

    printf("Block Size      = %d bytes\n", BLOCK_SIZE);
    printf("Padding Added   = %d bytes\n", padBits);
    printf("Final Length    = %d bytes\n", totalLen);

    printf("\nPadded Message Representation:\n");

    for(i = 0; i < len; i++)
        printf("%c", msg[i]);

    /* First padding byte = 1 */
    printf("1");

    for(i = 1; i < padBits; i++)
        printf("0");

    printf("\n");

    printf("\nApplicable to ECB, CBC and CFB modes.\n");

    getch();
    return 0;
}
