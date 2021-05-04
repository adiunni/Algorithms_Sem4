#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define d 256

void search(char pat[], char txt[], int q){
    int m = strlen(pat);
    int n = strlen(txt);
    int i,j;
    int h=1;
    int p=0;
    int t=0;
    
    for(i=0;i<m-1;i++){
        h = (h*d)%q;
    }

    for(i=0;i<m;i++){
        p = (d*p + pat[i])%q;
        //printf("p = %d\n",p);
        t = (d*t + txt[i])%q;
        //printf("t = %d\n",t);
    }

    for(i=0;i<=n-m;i++){
        if(p == t){
            //printf("\nInside if condition\n");
            for(j=0;j<m;j++){
                if(txt[i+j] != pat[j]){
                    break;
                }
            }
            if(j==m)
                printf("\nPattern is found at sweep %d \n",i+1);
        }

        if(i<n-m){
            t = (d*(t - txt[i]*h) + txt[i+m])%q;
            if(t<0)
                t += q;
        }
    }
}

int main(){
    printf("\nRABIN KARP Algorithm\n");
    char txt[] = "cdfjacdbebfcghddbebfjjcdbebfb";
    char pat[] = "dbebf";
    int q = 13;
    search(pat,txt,q);
    return 0;
}