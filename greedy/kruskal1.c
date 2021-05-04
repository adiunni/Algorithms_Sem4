#include<stdio.h>
#include<stdlib.h>
#define MAX 9

int i,j,k,a,b,u,v,no_of_edge=1; //Config variables
int min,graph[MAX][MAX],parent[MAX], graph2[MAX][MAX]; //Global configuration.

int find(int i){
	while(parent[i]) //Loop used instead of recursion
	i=parent[i];
	return i;
}

int union101(int i,int j){
	if(i!=j){
		parent[j]=i;
		return 1; //Return true
	}
	return 0; //Else Returns false
}

void display_edgetable(){
    int flag[MAX][MAX];
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            flag[i][j]=0;
        }
    }
    printf("\nThe Edge table before sorting will be: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            if(graph2[i][j] != 99999){
                if(graph2[i][j]==graph2[j][i] && flag[i][j]==0){
                    printf("Edge %d (%c,%c) =%d\n",no_of_edge++,i+65,j+65,graph2[i][j]);
                    flag[i][j]=flag[j][i]=1;
                }
            }
        }
    }   
}

void kruskal(){
    display_edgetable();
    no_of_edge = 1;
    printf("\nThe path of the tree along with it's weights are: \n");
	while(no_of_edge < MAX){ //For each edge we need to do the following
        //1. Sort the edges in non decreasing order of weights
		for(i=0,min=99999;i<MAX;i++){
			for(j=0;j < MAX;j++){
				if(graph[i][j] < min){
					min=graph[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
        //2. Check if any complete path is formed. If not then display the edge. 
		u=find(u);
		v=find(v);
		if(union101(u,v)){
			printf("Edge %d (%c,%c) =%d\n",no_of_edge++,a+65,b+65,min);
		}
		graph[a][b]=graph[b][a]=99999; //To remove the edge value of from further calculations.
	}
    printf("\n");
}

int main(){
	printf("\nEnter the adjacency matrix with weights:\n");
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			scanf("%d",&graph[i][j]);
            graph2[i][j] = graph[i][j];
			if(graph[i][j]==0 && graph2[i][j]==0){
				graph[i][j]=99999; //We need to do this because 0 will be detected in min.
                graph2[i][j] = 99999;
            }
		}
	}
	kruskal();
	return 0;
}
