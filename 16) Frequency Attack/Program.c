#include <stdio.h>
#include <string.h>

int main() {
    char cipher[500];
    int freq[26]={0};

    printf("Enter Ciphertext:\n");
    fgets(cipher,sizeof(cipher),stdin);
	int i;
    for(i=0;cipher[i];i++)
        if(cipher[i]>='A' && cipher[i]<='Z')
            freq[cipher[i]-'A']++;

    printf("\nFrequency Analysis:\n");
	
    	for(i=0;i<26;i++)
        	printf("%c : %d\n",'A'+i,freq[i]);

    return 0;
}
