#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int key;
    double score;
    char text[MAX];
} Candidate;

/* English letter frequencies */
double freq[26] = {
    8.2,1.5,2.8,4.3,12.7,2.2,2.0,6.1,7.0,0.15,
    0.77,4.0,2.4,6.7,7.5,1.9,0.095,6.0,6.3,9.1,
    2.8,1.0,2.4,0.15,2.0,0.07
};

double scoreText(char text[]) {
    double score = 0;
	int i;
    for(i=0;text[i];i++) {
        if(isalpha(text[i])) {
            score += freq[toupper(text[i]) - 'A'];
        }
    }
    return score;
}

void decrypt(char cipher[], int key, char plain[]) {
    int i;

    for(i=0; cipher[i]; i++) {
        if(isalpha(cipher[i])) {
            char ch = toupper(cipher[i]);
            plain[i] = ((ch - 'A' - key + 26) % 26) + 'A';
        }
        else {
            plain[i] = cipher[i];
        }
    }
    plain[i] = '\0';
}

int compare(const void *a, const void *b) {
    Candidate *x = (Candidate *)a;
    Candidate *y = (Candidate *)b;

    if(y->score > x->score) return 1;
    if(y->score < x->score) return -1;
    return 0;
}

int main() {
    char cipher[MAX];
    int topN;

    Candidate result[26];

    printf("Enter Ciphertext: ");
    fgets(cipher, MAX, stdin);

    printf("Enter number of top plaintexts required: ");
    scanf("%d", &topN);

    if(topN > 26)
        topN = 26;
	int key;
    for(key=0; key<26; key++) {
        result[key].key = key;

        decrypt(cipher, key, result[key].text);

        result[key].score = scoreText(result[key].text);
    }

    qsort(result, 26, sizeof(Candidate), compare);

    printf("\nTop %d Possible Plaintexts:\n\n", topN);
	int i;
    for(i=0; i<topN; i++) {
        printf("Rank %d\n", i+1);
        printf("Key : %d\n", result[i].key);
        printf("Text: %s\n", result[i].text);
        printf("Score: %.2lf\n\n", result[i].score);
    }

    return 0;
}
