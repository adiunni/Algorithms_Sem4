#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

int pi[MAX];

void compPreFunc(char pat[]){
    //printf("\nInside this function\n");
    int m = strlen(pat), i;
    pi[1] = 0;
    int k = 0;
    for(int q = 2;q<m;q++){
        while (k>0 && pat[k+1]!=pat[q]){
            k = pi[k];
        }
        if(pat[k+1] == pat[q])
            k += 1;
        pi[q] = k;
    }
    printf("\nThe prefix values of each character in pattern: ");
    for(i=1;i<m;i++){
        printf("%d  ",pi[i]);
    }
    printf("\n");
}

void kmp(char pat[], char text[]){
    //printf("\nInside KMP algorithm\n");
    int n = strlen(text);
    int m = strlen(pat);
    compPreFunc(pat);
    //printf("\nBack to this function");
    int q = 0; //No. of characters matched
    for(int i=1;i<n;i++){ 
        while (q>0 && pat[q+1]!=text[i]){
            q = pi[q];
        }
        if(pat[q+1]==text[i])
            q += 1;
        if(q==m-1){
            printf("\nThe pattern occured on shift %d\n",i-m+1);
            q = pi[q];
        }
    }
}

int main(){
    printf("\nKnuth-Morris-Pratt Algorithm\n");
    char txt[] = " bacbababacabcbabababacaabcabaababaca"; //Space given to make the first char appear null
    char pat[] = " ababaca";
    kmp(pat,txt);
    return 0;
}