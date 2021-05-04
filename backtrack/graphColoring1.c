#include<stdio.h>
#define MAX 50
int m, n, c=0, count=0, g[MAX][MAX],color[MAX];

void nextValue(int k)
{
    int j;
    while(1){
        color[k]=(color[k]+1)%(m+1);
        if(color[k]==0){
            return;
        }
        for(j=1;j<=n;j++){
        if(g[k][j]==1&&color[k]==color[j])
            break;
        }
        if(j==(n+1)){
            return;
        }
    }
}

void GraphColoring(int k){
    int i;
    while(1){
        nextValue(k);
        if(color[k]==0){
            return;
        }
        if(k==n){
            c=1;
            for(i=1;i<=n;i++){
            printf("%d ", color[i]);
            }   
            count++;
            printf("\n");
        }
        else
            GraphColoring(k+1);
    }
}

int main()
{
    int i, j;
    int temp;
    printf("\nEnter the number of nodes: " );
    scanf("%d", &n);
    printf("\nEnter Adjacency Matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d", &g[i][j]);
        }
    }
    printf("\nPossible Solutions are\n");
    for(m=1;m<=n;m++){
        if(c==1){
            break;
        }
        GraphColoring(1);
    }
    printf("\nThe chromatic number is %d", m-1);
    printf("\nThe total number of solutions is %d", count);
}
