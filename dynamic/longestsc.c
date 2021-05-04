#include<stdio.h>
#include<string.h>

int table[8][7], table2[8][7], i, j, m, n;
char sub1[7],sub2[6];

void printLCS(int i,int j){
    if(i==0 || j==0){
        return;
    }

    if(table2[i][j]==1){ //For diagonal
        printLCS(i-1,j-1);
        printf("%c ",sub1[i-1]);
    }
    else if(table2[i][j]==2) //For upward
        printLCS(i-1,j);
    else
        printLCS(i,j-1);
}


void longSub(){
    
    m = strlen(sub1);
    n = strlen(sub2);

    for(i=0;i<=m;i++){
        table[i][0] = 0;
    }
    for(j=0;j<=n;j++){
        table[0][j]=0;
    }
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            table2[i][j]=0;
        }
    }

    //1 denotes diagonal, 2 denotes upwards, 3 denotes left
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(sub1[i-1]==sub2[j-1]){
                table[i][j] = table[i-1][j-1]+1;
                table2[i][j] = 1;
            }
            else if(table[i-1][j] >= table[i][j-1]){
                table[i][j] = table[i-1][j];
                table2[i][j] = 2;
            }
            else {
                table[i][j] = table[i][j-1];
                table2[i][j] = 3;
            }
        }
    }
    printf("\nThe table to calculate subsequence is: \n");
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    printf("\nNOTE\n1.The direction for diagonal is 1\n2.The direction for upwards is 2\n3.The direction for left is 3\n");
    printf("\nThe direction of subsequence is: \n");
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            printf("%d ",table2[i][j]);
        }
        printf("\n");
    }
    printf("\nThe Longest common subsequence is: ");
    printLCS(m,n);
    printf("\n");
}


int main(){
    
    printf("\nEnter the subsequence 1: ");
    scanf("%s",sub1);
    printf("\nEnter the subsequence 2: ");
    scanf("%s",sub2);
    longSub();
    return 0;
}