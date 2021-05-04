#include <stdio.h>
#include <stdlib.h>

int n = 4;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void swapChar(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}


int partition(int a[],int b[], int c[], char d[], int l, int h) {
    int j,temp;
    int x = a[h]; //Pivot element.
    int i = l-1; //Index of small element.
    for(j=l;j<=h-1;j++){
        if(a[j]>=x){
            i++;
            swap(&a[i],&a[j]);
            swap(&b[i],&b[j]);
            swap(&c[i],&c[j]);
            swapChar(&d[i],&d[j]);
        }
    }
    swap(&a[i+1],&a[h]);
    swap(&b[i+1],&b[h]);
    swap(&c[i+1],&c[h]);
    swapChar(&d[i+1],&d[h]);
    return (i+1);
}

void sort(int arr[], int brr[], int crr[], char drr[],int l, int r){
    int pi;
    if(l<r) {
        pi = partition(arr,brr,crr,drr,l,r);
        sort(arr,brr,crr,drr,l,pi-1);
        sort(arr,brr,crr,drr,pi+1,r);
    }
}

void knapsack(char x[], int profit[], int weights[], int max_weight){
    char s[n]; // Set to store profits
    int sw = 0, sp = 0, i = 1; //Sum of weights and profits declared
    float frac;
    int cost[n];
    for(int i=0;i<n;i++){
        cost[i] = profit[i]/weights[i];
    }
    sort(cost,profit,weights,x,0,n); //Quick sort algorithm to sort the cost array 
    // and the other arrays corresponding to it.
    printf("\nThe array according to cost is: ");
    for(i=0;i<n;i++){
        printf("%d ",cost[i]);
    }
    printf("\nThe array according to profits will be: ");
    for(i=0;i<n;i++){
        printf("%d ",profit[i]);
    }
    printf("\nThe array according to weights will be: ");
    for(i=0;i<n;i++){
        printf("%d ",weights[i]);
    }
    printf("\nThe supposed sequence of jobs is: ");
    for(i=0;i<n;i++){
        printf("%c ",x[i]);
    }
    printf("\n");
    i=0;
    while(i<=n){
        printf("\nLoop %d",i+1);
        if((sw+weights[i])<=max_weight){
            s[i] = x[i];
            sw += weights[i];
            sp += profit[i];
            printf("\nCurrent weight sum = %d",sw);
            printf("\nCurrent profit sum = %d",sp);
        }
        else {
            frac = ((float)max_weight - (float)sw)/(float)weights[i];
            printf("\nFraction value is %f ", frac);
            s[i] = x[i];
            sw += weights[i]*frac;
            sp += profit[i]*frac;
            break;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    printf("\nThe schedule is: ");
    for(i=0;i<n;i++){
        printf("%c ",s[i]);
    }
    printf("\nThe max profit achieved is: %d",sp);
    printf("\nThe weight achieved is: %d\n\n",sw);
}

int main(){
    int i,j,k; //Looping vars and size config.
    int profit[n], weights[n], max_weight; //Profits, weights and maximum weight.
    char x[] = {'A','B','C','D','E'};

    printf("Enter the profits: ");
    for(i=0;i<n;i++){
        scanf("%d",&profit[i]);
    }
    printf("Enter the weights: ");
    for(i=0;i<n;i++){
        scanf("%d",&weights[i]);
    }
    printf("Enter the maximum weight: ");
    scanf("%d",&max_weight);
    
    knapsack(x,profit, weights, max_weight);
}