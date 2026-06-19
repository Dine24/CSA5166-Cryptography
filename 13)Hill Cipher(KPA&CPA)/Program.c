#include <stdio.h>

int modInverse(int a) {
    a %= 26;
    int x;
    for(x = 1; x < 26; x++) {
        if((a * x) % 26 == 1)
            return x;
    }
    return -1;
}

int main() {
	int i,j,k;
    /* Known plaintext matrix */
    int P[2][2] = {
        {7,11},
        {4,15}
    };

    /* Corresponding ciphertext matrix */
    int C[2][2] = {
        {25,17},
        {1,18}
    };

    int det = (P[0][0]*P[1][1] - P[0][1]*P[1][0]) % 26;
    if(det < 0) det += 26;

    int detInv = modInverse(det);

    if(detInv == -1){
        printf("Inverse does not exist.\n");
        return 0;
    }

    int Pinv[2][2];

    Pinv[0][0] = ( P[1][1] * detInv) % 26;
    Pinv[0][1] = ((-P[0][1] + 26) * detInv) % 26;
    Pinv[1][0] = ((-P[1][0] + 26) * detInv) % 26;
    Pinv[1][1] = ( P[0][0] * detInv) % 26;

    int K[2][2];

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            K[i][j]=0;
            for(k=0;k<2;k++)
                K[i][j]+=C[i][k]*Pinv[k][j];

            K[i][j]%=26;
        }
    }

    printf("Recovered Key Matrix:\n");

    for(i=0;i<2;i++){
        for(j=0;j<2;j++)
            printf("%3d ",K[i][j]);
        printf("\n");
    }

    return 0;
}
