#include<stdio.h>
#include<stdlib.h>

int call = 0;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++) 
        printf("%d  ",arr[i]);
    printf("\n"); 
}  

int partition(int a[], int l, int h) {
    int j,temp;
    int x = a[h]; //Pivot element.
    int i = l-1; //Index of small element.
    for(j=l;j<=h-1;j++){
        if(a[j]<=x){
            i++;
            swap(&a[i],&a[j]);
            printf("Swapped: ");
            printArray(a,6);
            printf("\n");
        }
    }
    swap(&a[i+1],&a[h]);
    printf("Swapped: ");
    printArray(a,6);
    printf("\n");
    return (i+1);
}

void quickSort(int a[],int l, int h) {
    call++;
    printf("\nCall: %d\n",call);
    int pi;
    if(l<h) {
        pi = partition(a,l,h);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,h);
    }
    printf("Partition = %d\n",pi);
}


int main() {
    int a[6],i,n;
    printf("Enter the array elements: ");
    for(i=0;i<6;i++) {
        scanf("%d",&a[i]);
    }
    n = sizeof(a)/sizeof(a[0]);
    quickSort(a,0,n-1);
    printf("The sorted array is: ");
    printArray(a,n);
    return 0;
}