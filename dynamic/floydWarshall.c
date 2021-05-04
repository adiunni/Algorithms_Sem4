#include<stdio.h>

#define MAX 4
#define INF 99999

int graph[MAX][MAX],dist[MAX][MAX];
int i,j,k;

void printSoln(){
    int p,q;
    printf("The shortest distance between every pair of vertices.\n");
    for(p=0;p<MAX;p++){
        for(q=0;q<MAX;q++){
            printf("%d  ",dist[p][q]);
        }
        printf("\n");
    }
}

void printSoln1(){
    int p,q;
    printf("\nIteration\n");
    for(p=0;p<MAX;p++){
        for(q=0;q<MAX;q++){
            printf("%d  ",dist[p][q]);
        }
        printf("\n");
    }
}

void floydWarshall(){
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            dist[i][j]=graph[i][j];
        }
    }

    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            for(k=0;k<MAX;k++){
                if(dist[j][k]>dist[j][i]+dist[i][k]){
                    dist[j][k]=dist[j][i]+dist[i][k];
                }
            }
        }
        printSoln1();
    }
    printf("\nThe final array: ");
    printSoln();
}

int main(){
    printf("\nEnter the adjacency matrix: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            scanf("%d",&graph[i][j]);
            if(i!=j && graph[i][j]==0)
                graph[i][j]=INF;
        }
    }
    floydWarshall();
    return 0;
}