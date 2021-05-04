#include<stdio.h>
#define MAX 5
#define INF 99999

int graph[MAX][MAX],visited[MAX],cost=0,i,j;

int tsp(int c){
    int nc=INF, min=INF, temp;
    for(i=0;i<MAX;i++){
        if((graph[c][i]!=0) && (visited[i]==0)){
            if(graph[c][i]<min){
                min = graph[c][0] + graph[c][i];
                temp=graph[c][i];
                nc = i;
            }
        }
    }

    if(min != INF){
        cost += temp;
        //printf("Cost: %d\n",cost);
    }
    return nc;
}

void minCost(int city){
    int nc;
    visited[city] = 1;
    printf("%d ",city+1);
    nc = tsp(city);
    if(nc==INF){
        nc = 0;
        printf("%d ",nc+1);
        cost += graph[city][nc];
        return;
    }
    minCost(nc);   
}

int main(){
    int source;
    printf("\nEnter the cost of graph: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            scanf("%d",&graph[i][j]);
        }
        visited[i]=0;
    }
    printf("Enter source location: ");
    scanf("%d",&source);
    printf("\nThe path followed: ");
    minCost(source);
    printf("\nThe cost taken to complete the path is: %d\n",cost);
    return 0;
}