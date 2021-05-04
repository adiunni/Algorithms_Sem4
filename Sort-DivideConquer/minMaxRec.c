#include<stdio.h>
#include<stdlib.h>

int a[100];

int minRec(int i, int j){
    int min;
    int min1;
    printf("\n");
    printf("\nValue of i: %d",i);
    printf("\nValue of j: %d",j);

    if(i==j)
        min = a[i];
    else if(i == j-1){
        if(a[i]<a[j])
            min = a[i];
        else
            min = a[j];
    }
    else {
        int mid = (i+j)/2;
        min = minRec(i,mid);
        min1 = minRec(mid+1,j);
        if(min>min1)
            min = min1;
    }
    printf("\nThe min value of call is: %d",min);
    printf("\n");
    return min;
}

int maxRec(int i, int j){
    int max;
    int max1;
    printf("\n");
    printf("\nValue of i: %d",i);
    printf("\nValue of j: %d",j);

    if(i==j)
        max = a[i];
    else if(i == j-1){
        if(a[i]>a[j])
            max = a[i];
        else
            max = a[j];
    }
    else{
        int mid = (i+j)/2;
        max = maxRec(i,mid);
        max1 = maxRec(mid+1,j);
        if(max<max1)
            max = max1;
    }
    printf("\nThe max value of call is: %d",max);
    printf("\n");
    return max;
}


int main(){
    int i,j,max=-999999,min=999999,n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the array data: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("The array data is: ");
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    printf("\n");
    printf("\n---------MAXIMUM--------");
    max = maxRec(0,n-1);
    printf("\n---------MINIMUM--------");
    min = minRec(0,n-1);
    printf("\nFinally, the minimum element is %d",min);
    printf("\nFinally, the maximum element is %d",max);
}