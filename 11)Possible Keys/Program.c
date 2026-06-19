#include <stdio.h>

int main() {
    long double keys = 1.0;
	int i;
    for (i = 1; i <= 25; i++) {
        keys *= i;
    }

    printf("Number of possible Playfair keys = %.0Lf\n", keys);
    printf("Approximate key space = 2^84\n");

    return 0;
}
