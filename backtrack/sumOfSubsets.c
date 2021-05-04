#include<stdio.h>
#include<stdlib.h>

int total_nodes=0;

void printSet(int set[], int n){
    for(int i=0;i<n;i++){
        printf("%d\t",set[i]);
    }
    printf("\n");
}

//t_sum = Total sum to achieve
//sum = Sum of each iteration.

void isSubet(int set[], int tset[], int n, int t_size, int sum, int t_sum, int ite){
    total_nodes++;
    if(t_sum==sum){
        printSet(tset,t_size);
        return;
    }
    else{
        for (int i = ite; i < n; i++) {
            tset[t_size] = set[i];
            isSubet(set, tset, n, t_size+1,sum+set[i],t_sum,i+1);
        }
    }  
}

void generateSubset(int set[], int n, int sum){
    int* t_set = (int*)malloc(n * sizeof(int));
    isSubet(set,t_set,n,0,0,sum,0);
    free(t_set);
}

int main(){
    int set[100],n,i,sum;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("\nEnter the set details: ");
    for(i=0;i<n;i++){
        scanf("%d",&set[i]);
    }
    printf("Enter the sum: ");
    scanf("%d",&sum);
    printf("\nThe possible subsets of the set following the sum value is: \n");
    generateSubset(set,n,sum);
    printf("\nTotal no of nodes: %d",total_nodes);
}