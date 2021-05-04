#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define MAX 5
#define INT_MAX 99999

int min_dist(int dist[], bool pi[], int Q[]) {
    int min=99999, i, min_index;
    for(i=0;i<MAX;i++){
        if(pi[i]==false && min>dist[i]){
            min = dist[i];
            min_index = i;
        }
    }
    return Q[min_index];
}

void printSolution(int dist[],int par[], int n) 
{ 
    printf("Vertex  \t Distance from Source \t Parent node \n"); 
    for (int i = 0; i < MAX; i++) 
        printf("%d \t\t %d \t\t %d \n", i, dist[i], par[i]); 
}

void dijkstra(int graph[MAX][MAX], int src) {

    int distance[MAX]; // Distance between two nodes
    bool pi[MAX]; // Check whether the node is removed from the queue.
    int par[MAX]; // Parent variable for each node.
    int S[MAX];
    int Q[MAX]={0,1,2,3,4}; // Pre-defined vertices.
    int i,j;
    for(i=0;i<MAX;i++){
        distance[i] = INT_MAX; //Make distance of each node close to INF
        pi[i] = false; //Make each node to false
        par[i] = - 1 ; //I will never make vertex less than 0.
    }

    distance[src]=0; //Distance of source node to zero.

    for(i=0;i<MAX;i++){
        int u = min_dist(distance,pi,Q); // Returns a value from the queue.
        S[i]= u;
        printf("\n%d\n",S[i]);
        pi[u] = true; //This will ensure the value is processed.
        for(j=0;j<MAX;j++){
            if((pi[j]==false) && graph[u][j] && distance[u] != INT_MAX && (distance[j] > distance[u] + graph[u][j])){
                distance[j] = graph[u][j] + distance[u];
                par[j] = u;
            }
        }
    }
    printSolution(distance,par,MAX);
    printf("The solution is: ");
    for(i=0;i<MAX;i++){
        printf("%d ",S[i]);
    }
}


int main(){
    int graph[MAX][MAX],i,j,src;
    printf("Enter the adjacency matrix with weights: \n"); //This matrix will take the weights
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\nEnter source number: ");
    scanf("%d",&src);
    dijkstra(graph, src);
    return 0;
}