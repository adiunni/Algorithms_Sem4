#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void strMatch(char* text, char* pattern){
    int m = strlen(pattern);
    int n = strlen(text);

    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(text[i+j] != pattern[j])
                break;
        }
        if(j==m){
            printf("Pattern is found at sweep %d \n",i+1);
        }
    }
}

int main(){
    printf("\nNAIVE String matching\n");
    char text[100], pattern[100];
    printf("Enter the string text: ");
    scanf("%s",text);
    printf("Enter the pattern text: ");
    scanf("%s",pattern);
    strMatch(text, pattern);
    return 0;
}