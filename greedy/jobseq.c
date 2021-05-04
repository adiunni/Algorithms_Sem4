#include<stdio.h>
#include<stdlib.h>

int n = 7;

struct job {
    int job_id;
    int deadline;
    int profit;
}job_list[7];

void sort(){
    struct job temp;
    int i,j;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(job_list[i].profit<job_list[j].profit){
                temp = job_list[i];
                job_list[i] = job_list[j];
                job_list[j] = temp;
            }
        }
    }
    printf("\nSorted according to profit\n");
    printf("JOB_ID\tJOB_PROFIT\tDEADLINE\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t\t%d\n",job_list[i].job_id,job_list[i].profit,job_list[i].deadline);
    }
}

int deadline_max(){
    int max=-1, i;
    for(i=0;i<n;i++){
        if(job_list[i].deadline>max)
            max = job_list[i].deadline;
    }
    return max;
}

int job_sequence(){
    sort();
    int after_job_sequence[n], T[n];
    int max_d = deadline_max(), t, j;
    printf("\nThe maximum deadline is %d",max_d);
    int max_profit = 0, k = 0;
    for(t = 0; t< max_d; t++){
        T[t] = -1;
    }
    for(j=0;j<n;j++){
        t = job_list[j].deadline - 1;
        //printf("\nDeadline %d : %d",j+1, t);
        while (t != -1){
            if(T[t]==-1){
                //printf("\nWent in if");
                T[t] = job_list[j].job_id;
                after_job_sequence[k] = job_list[j].job_id;
                k++;
                max_profit += job_list[j].profit;
                break;
            }
            else {
                //printf("\nWent in else");
                t--;
            }
        }
    }
    printf("\nThe values of deadlines in time array is: ");
    for(j=0;j<max_d;j++){
        printf("%d  ",T[j]);
    }

    printf("\n\nThe sequence is: ");
    for(j=0;j<k;j++){
        printf("%d  ",after_job_sequence[j]);
    }
    return max_profit;
}

int main(){
    int i,j;
    printf("Enter the profits: ");
    for(i=0;i<n;i++){
        scanf("%d",&job_list[i].profit);
    }
    printf("Enter the deadlines for the job: ");
    for(i=0;i<n;i++){
        scanf("%d",&job_list[i].deadline);
    }
    for(i=0;i<n;i++){
        job_list[i].job_id = i+1;
    }
    int max_profit = job_sequence();
    printf("\nThe max profit is %d\n\n",max_profit);
}