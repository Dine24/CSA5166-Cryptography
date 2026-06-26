#include <stdio.h>

#define TOTAL_LANES 25
#define RATE_LANES 16
#define CAPACITY_LANES 9

int main()
{
    int i;
    int state[TOTAL_LANES];

    // First 16 lanes (rate) contain message data
    for(i = 0; i < RATE_LANES; i++)
        state[i] = 1;

    // Last 9 lanes (capacity) are initially zero
    for(i = RATE_LANES; i < TOTAL_LANES; i++)
        state[i] = 0;

    printf("SHA-3 State Analysis\n");
    printf("---------------------\n");
    printf("Total Lanes    : %d\n", TOTAL_LANES);
    printf("Rate Lanes     : %d\n", RATE_LANES);
    printf("Capacity Lanes : %d\n\n", CAPACITY_LANES);

    printf("Capacity Lane Status:\n");

    for(i = RATE_LANES; i < TOTAL_LANES; i++)
    {
        if(state[i] == 0)
            printf("Lane %d : Zero\n", i);
    }

    printf("\nIgnoring the permutation, the message only affects the rate lanes.\n");
    printf("The capacity lanes remain zero forever.\n");
    printf("Time required for all capacity lanes to become nonzero: NEVER (Infinite).\n");

    return 0;
}
