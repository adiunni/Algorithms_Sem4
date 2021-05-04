#include<stdio.h>

#define MAX 4


struct jobs{
    int job_id;
    int weight;
    int profit;
}job_list[4];

int i,j,k,max_weight,result[MAX];

int max(int a, int b){return a>b ? a : b ;}

void knap01(){
    printf("\n");
    int table1[MAX+1][max_weight+1];
    for(i=0;i<=MAX;i++){
        for(j=0;j<=max_weight;j++){
            table1[i][j]=0;
            printf("%d ",table1[i][j]);
        }
        result[i]=0;
        printf("\n");
    }
    printf("\nThe subset of the knapsack table formed is: \n");

    for(i=1;i<=MAX;i++){
        for(j=1;j<=max_weight;j++){
            if(j - job_list[i-1].weight < 0){
                table1[i][j] = table1[i-1][j];
            }
            else{
                table1[i][j] = max(table1[i-1][j], job_list[i-1].profit + table1[i-1][j-job_list[i-1].weight]);
            }
            printf("%d  ",table1[i][j]);
        }
        printf("\n");
    }

    for(i=MAX;i>0;i--){
        if(table1[i][max_weight]!=table1[i-1][max_weight]){
            printf("Profit %d is due to item %d\n",table1[i][max_weight], i);
            result[i-1]=1;
        }
    }
    printf("\nThe final result of the knapsack problem is: ");
    for(i=0;i<MAX;i++){
        printf("%d  ",result[i]);
    }
    printf("\n");

}

int main(){
    printf("\nEnter the job weights: ");
    for(i=0;i<MAX;i++){
        job_list[i].job_id=i+1;
        scanf("%d",&job_list[i].weight);
    }
    printf("\nEnter the job profits: ");
    for(i=0;i<MAX;i++){
        scanf("%d",&job_list[i].profit);
    }
    printf("\nEnter the maximum weight: ");
    scanf("%d",&max_weight);
    knap01();
    return 0;
}