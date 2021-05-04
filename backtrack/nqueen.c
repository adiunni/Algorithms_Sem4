#include<stdio.h>
#include<stdlib.h>

int board[20],count;

void printsoln(int n){
    printf("\n\nSolution: %d\n",++count);
    int i,j;
    printf("\t");
    for(i=1;i<=n;i++){
        printf("\t%d",i);
    }
    printf("\n");
    for(i=1;i<=n;i++){
        printf("\t%d",i);
        for(j=1;j<=n;j++){
            if(board[i]==j)
                printf("\tQ");
            else{
                printf("\t-");
            }
        }
        printf("\n");
    }
}

int place(int row, int column){
    int i;
    for(i=1;i<=row-1;i++){
        if(board[i]==column){
            //printf("False");
            return 0;
        }
        else {
            if(abs(board[i]-column)==abs(i-row)){
                //printf("False");
                return 0;
            }    
        }
    }
    return 1;
}

void queen(int row, int n){
    //printf("\nInside the queen function");
    int i; //Column.
    for(i=1;i<=n;i++){
        if(place(row,i)){
            board[row] = i;
            if(row==n)
                printsoln(n);
            else 
                queen(row+1,n);
        }
    }
}


int main(){
    int i, j, n;
    printf("\nEnter the number of queens: ");
    scanf("%d",&n);
    queen(1,n);
    return 0;
}