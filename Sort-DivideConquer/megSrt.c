#include <stdio.h>
#include <stdlib.h>
 
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d \t", A[i]);
    printf("\n");
    printf("\n");
}

int call = 0, n;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int n = r-l;
    int a[n1], b[n2];

    for (i = 0; i < n1; i++)
        a[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        b[j] = arr[m + 1 + j];

    printf("\n");
    printf("Subarray 1: ");
    printArray(a,n1);
    printf("Subarray 2: ");
    printArray(b,n2);

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        }
        else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
   //copy elements to the array
    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }
    //copy elements into the array.
    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
  
int main()
{
    int arr[100],i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the array data: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int arr_size = n;
    printf("Given array is \n");
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}