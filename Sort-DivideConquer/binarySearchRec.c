#include<stdio.h>
#include<stdlib.h>

int call=0;

void binSearch(int arr[], int s , int n, int val) {
    /*printf("\n");
    for(int i=s;i<=n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");*/
    call++;
    printf("Call %d\n",call);

    int mid;
    if(s<=n){
        mid =s + (n-s)/2;
        if(arr[mid]==val)
            printf("\nThe location of the array is: %d\n",mid);
        else if(arr[mid]>val){
            printf("\nMid value decreases to: %d\n",mid-1);
            binSearch(arr, s, mid-1, val);
        }
        else {
            printf("\nMid value increases to: %d\n",mid+1);
            binSearch(arr, mid+1, n, val);
        }
    }
    else{
        printf("\nThe element is not found\n");
    }
}

int main(){

    int n,val;
    int a[100];
    printf("Enter the length of array: ");
    scanf("%d",&n);
    printf("Enter the elements inside the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the value to be searched in the array: ");
    scanf("%d",&val);
    binSearch(a,0,n-1,val);
    return 0;
}