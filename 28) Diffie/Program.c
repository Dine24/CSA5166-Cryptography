#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, a;
    double aliceSend, bobSend;
    double eveX, eveY;

    printf("Enter Alice's secret x: ");
    scanf("%lf", &x);

    printf("Enter Bob's secret y: ");
    scanf("%lf", &y);

    printf("Enter public value a: ");
    scanf("%lf", &a);

    // Values sent publicly
    aliceSend = pow(x, a);
    bobSend = pow(y, a);

    printf("\nAlice sends : %.0lf\n", aliceSend);
    printf("Bob sends   : %.0lf\n", bobSend);

    // Eve recovers secrets
    eveX = pow(aliceSend, 1.0 / a);
    eveY = pow(bobSend, 1.0 / a);

    printf("\nEve computes:\n");
    printf("Recovered Alice secret = %.0lf\n", eveX);
    printf("Recovered Bob secret   = %.0lf\n", eveY);

    printf("\nConclusion:\n");
    printf("Using x^a instead of a^x mod q is NOT secure.\n");
    printf("Eve can recover the secret numbers by taking the a-th root.\n");

    return 0;
}
