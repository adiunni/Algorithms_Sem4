#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int chromatic_number=0;

void printSoln(int color[]){
    printf("\nThis is the solution: ");
    for(int i=0;i<MAX;i++){
        printf("%d  ",color[i]);
    }
}

int isSafe(int graph[MAX][MAX], int v, int color[], int c){
    for(int i=0;i<MAX;i++){
        if(graph[v][i] && c == color[i])
            return 0;
    }
    return 1;
}

int graphColor(int graph[MAX][MAX], int v, int color[], int m){
    
    if(v==MAX){
        return 1;
    }
    for(int c=0;c<m;c++){
        if(isSafe(graph,v,color,c)){
            color[v] = c;
            //printSoln(color);
            if(graphColor(graph,v+1,color,m)==1){
                //printSoln(color);
                return 1;
            }
            color[v]=0;
        }
        else{
            graphColor(graph,v+1,color,m);
        }
    }
    return 0;
}

int graphColor2(int graph[MAX][MAX], int m){
    int color[MAX],i,j;
    for(i=0;i<MAX;i++){
        color[i]=0;
    }
    if(graphColor(graph,0,color,m)==0){
        printf("\nSolution does not exist");
        return 0;
    }
    for(i=0;i<MAX;i++){
        for(j=0;j<i;j++){
            if(color[i]==color[j])
                break;
        }
        if(i==j)
            chromatic_number++;
    }
    printSoln(color);
    return 1;
}

int main(){
    int graph[MAX][MAX],m;
    int i,j;
    printf("Enter the adjacency list: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\nEnter the number of colors required: ");
    scanf("%d",&m);
    graphColor2(graph,m);
    printf("\nThe chromatic number of this graph is: %d\n",chromatic_number);
}