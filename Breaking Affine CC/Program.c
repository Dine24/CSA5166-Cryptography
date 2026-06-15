#include <stdio.h>

// Function to find modular inverse
int modInverse(int a, int m) {
    a = a % m;
    int x;
    for (x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

int main() {
    int C1 = 1;   // B
    int C2 = 20;  // U

    int P1 = 4;   // E
    int P2 = 19;  // T

    int diffP = (P2 - P1 + 26) % 26;
    int diffC = (C2 - C1 + 26) % 26;

    int inv = modInverse(diffP, 26);

    if (inv == -1) {
        printf("No modular inverse exists.\n");
        return 0;
    }

    int a = (diffC * inv) % 26;
    int b = (C1 - a * P1 + 26 * 10) % 26;

    printf("Recovered Key:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}
