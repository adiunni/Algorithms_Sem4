#include <stdio.h>
#include <stdlib.h>

int a[100];

int main(){
    //Variable declaration
    int i,n,temp,j,pass,comparison,swaps;

    //Data entry
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the array data: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    //Algorithm in code  
    pass = 0;  
    for(i=0;i<n;i++){
        swaps = 0;
        comparison = 1;
        temp = a[i];
        j = i-1;
        while(temp<= a[j]){
            a[j+1] = a[j];
            j--;
            swaps++;
            comparison++;
        }
        a[j+1] = temp;
        pass++;
        printf("Pass %d : ",i+1);
        for(j=0;j<n;j++){
            printf("%d \t",a[j]);
        }
        printf("\nThe number of comparisons made is %d",comparison);
        printf("\nThe number of swaps made is %d\n",swaps);
        printf("\n");
    }

    //Final result
    printf("The sorted array is: ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\nThe number of passes is %d\n",pass);
    
    return 0;
}