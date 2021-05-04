#include<stdio.h>
#include<stdbool.h>

#define MAX 7
#define INF 99999

int graph1[MAX][MAX],edge[MAX][2];
int source,no_edge=0;

int i,j,k;

void printSolution(int dist[],char par[]) 
{ 
    printf("Vertex  \t Distance from Source \t Parent node \n"); 
    for (int k = 0; k < MAX; k++) 
        printf("%c \t\t %d \t\t\t %c \n", k+65, dist[k], par[k]); 
}

bool bellFord(){
    int dist[MAX];
    char par[MAX];
    bool pi[MAX];
    int u,v;

    for(i=0;i<MAX;i++){
        dist[i] = INF;
        par[i] = (char)36;
    }

    dist[source] = 0;
    for(i=0;i<MAX-1;i++){
        for(j=0;j<no_edge;j++){
            //printf("\n%d",j);
            u = edge[j][0];
            v = edge[j][1];
            //printf("\nEdge1:%c",u+65);
            //printf("\nEdge2:%c",v+65);
            //printf("\nWeight of %c,%c: %d",u+65,v+65,graph1[u][v]);
            if(dist[v]>dist[u]+graph1[u][v]){
                dist[v]=dist[u]+graph1[u][v];
                par[v]= (char)u+65;
            }
            
        }
        printf("\n");
        printSolution(dist,par);    
    }
    for(j=0;j<no_edge;j++){
        u = edge[j][0];
        v = edge[j][1];
        if(dist[v]>dist[u]+graph1[u][v]){
            return false;
        }
    }
    printf("\nThe final table will be: \n");
    printSolution(dist,par);
    return true;
}

int main(){
    printf("Enter the adjacency matrix with weights: \n"); //This matrix will take the weights
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            scanf("%d",&graph1[i][j]);
            if(graph1[i][j]!=0){
                edge[no_edge][0]=i;
                edge[no_edge][1]=j;
                no_edge++;
            }
        }
    }
    //printf("\nGraph[0][3]: %d",graph1[0][3]);
    printf("\nEnter source number: ");
    scanf("%d",&source);
    if(bellFord()){
        printf("\nThere is no negative cycle\n");
    }
    else{
        printf("\nThere is a negative cycle!\n");
    }
    return 0;
}