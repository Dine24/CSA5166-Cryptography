#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[] = "MEETMEATTHEUSUALPLACEATTENRATHERTHANEIGHTOCLOCK";
    int key[2][2] = {{9,4},{5,7}};
    int inv[2][2] = {{5,12},{15,25}};

    int len = strlen(text);

    if(len % 2 != 0) {
        text[len] = 'X';
        text[len+1] = '\0';
        len++;
    }

    char cipher[100], plain[100];

    printf("Ciphertext: ");
	int i;
    for(i=0;i<len;i+=2){
        int p1=text[i]-'A';
        int p2=text[i+1]-'A';

        int c1=(key[0][0]*p1 + key[0][1]*p2)%26;
        int c2=(key[1][0]*p1 + key[1][1]*p2)%26;

        cipher[i]=c1+'A';
        cipher[i+1]=c2+'A';

        printf("%c%c",cipher[i],cipher[i+1]);
    }

    printf("\n");

    printf("Recovered Plaintext: ");
    for(i=0;i<len;i+=2){
        int c1=cipher[i]-'A';
        int c2=cipher[i+1]-'A';

        int p1=(inv[0][0]*c1 + inv[0][1]*c2)%26;
        int p2=(inv[1][0]*c1 + inv[1][1]*c2)%26;

        plain[i]=p1+'A';
        plain[i+1]=p2+'A';

        printf("%c%c",plain[i],plain[i+1]);
    }

    printf("\n");

    return 0;
}
