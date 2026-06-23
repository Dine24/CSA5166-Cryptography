#include <stdio.h>
#include <conio.h>

int main()
{
    printf("DES Key Size : 56 bits\n\n");

    printf("Observation:\n");
    printf("First 24 bits of each subkey come from one 28-bit half.\n");
    printf("Second 24 bits come from the other 28-bit half.\n");
    printf("The two halves are disjoint.\n");

    getch();
    return 0;
}
