#include <stdio.h>
#include <conio.h>

int main()
{
    int i;

    printf("DES Decryption Key Schedule\n\n");

    printf("Encryption Order:\n");
    for(i=1;i<=16;i++)
    {
        printf("K%d ",i);
    }

    printf("\n\nDecryption Order:\n");
    for(i=16;i>=1;i--)
    {
        printf("K%d ",i);
    }

    getch();
    return 0;
}
