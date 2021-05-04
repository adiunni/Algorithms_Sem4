#include <stdio.h>
#include <stdlib.h>

int a[100];

int main(){
    int i,j,min,n,temp,passes,comparison,swaps;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the array data: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    comparison = 0;
    passes = 0;
    }
    for(i=0;i<n;i++){
        min = i;
        comparison = 0;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min])
                min = j;
            comparison ++;
        }
        temp = a[min];
        a[min]=a[i];
        a[i]=temp;
        printf("Pass %d : ",i+1);
        for(j=i+1;j<n;j++)
            printf("%d \t",a[j]);
        printf("\n");
        printf("\nThe number of comparisons made is %d\n",comparison);
        passes++;
        swaps++;
    }
    printf("\nThe sorted array is: ");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\nThe number of passes is %d\n",passes);
    printf("\nTotal number of swaps made is %d\n",swaps);
    return 0;
}