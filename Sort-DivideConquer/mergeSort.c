#include<stdio.h>
#include<stdlib.h>
#include<math.h>



void merge1(int a[], int p, int q, int r) {
    int i,j,k;
    
    int n1 = q - p + 1 ;
    int n2 = r - q ;
    int b[n1], c[n1];
    for(i=0;i<n1;i++) {
        b[i] = a[p + i - 1];
    }    
    printf("\n");
    for(j=0;j<n2;j++) {
        c[j] = a[q - j ];
    }
    printf("\n");

    i=0;j=0;k=p;
    while (i<n1 && j<n2)
    {
        if(b[i]<= c[j]){
            a[k]= b[i];
            i++;
        }
        else {
            a[k] = c[j];
            j++;
        }
        k++;
    }
    
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d \t", A[i]);
    printf("\n");
}

void mergeSort1(int a[], int p, int r) {
    int q;
    if(p<r) {
        q = p+(p+r)/2;
        mergeSort1(a,p,q);
        mergeSort1(a,q+1,r);
        merge1(a,p,q,r);
        
    }
}

int main() {
    int a[100];
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the array details: ");
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    mergeSort1(a,0,n);
    printf("\nThe sorted array is: ");
    printArray(a,n);
    return 0;
}