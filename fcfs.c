#include<stdio.h>

void findwaitingTime(int processes[],int n,int bt[],int wt[],int at[]){
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=at[i-1]+bt[i-1]+wt[i-1]-at[i];
    }
}
void findturnaroundTime(int processes[],int n,int bt[],int wt[],int tat[]){
    for(int i=0;i<n;i++)
    tat[i]=wt[i]+bt[i];
}
void findavgTime(int processes[],int n,int at[],int bt[]){
    int wt[n],tat[n],total_wt=0,total_tat=0;
    findwaitingTime(processes,n,bt,wt,at);
    findturnaroundTime(processes,n,bt,wt,tat);
    printf("Processes\tArrivalTime\tBurstTime\tWaitingTime\tTurnAroundTime\n");
    for(int i=0;i<n;i++){
        total_tat+=tat[i];
        total_wt+=wt[i];
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);
    }
    printf("Average Turn Around Time:%f.2\n",(float)total_tat/n);
    printf("Average Waiting Time:%f.2\n",(float)total_wt/n);
}

int main(){
    int processes[]={1,2,3,4,5};
    int n=sizeof(processes)/sizeof(processes[0]);
    int at[]={0,1,2,3,4};
    int bt[]={8,1,3,2,6};
    findavgTime(processes,n,at,bt);
}