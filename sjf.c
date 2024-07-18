#include<stdio.h>
#include<stdbool.h>

struct Process{
    int PID;
    int arrival_time;
    int burst_time;
};

void sortProcesses(struct Process processes[],int n){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(processes[j].burst_time>processes[j+1].burst_time){
                    struct Process temp = processes[j];
                    processes[j]=processes[j+1];
                    processes[j+1]=temp;
                }
            }
        }
}

void calculateTime(struct Process processses[],int n,int wt[],int tat[]){
    wt[0]=0;
    tat[0]=wt[0]+processses[0].burst_time;
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+processses[i-1].burst_time;
        tat[i]=wt[i]+processses[i].burst_time;
    }
}

void avgtime(struct Process processes[],int n){
       int wt[n],tat[n];
       calculateTime(processes,n,wt,tat);
       printf("PID\tWT\tTAT\n");
       float avg_wt=0,avg_tat=0;
       for(int i=0;i<n;i++){
         avg_wt+=wt[i];
         avg_tat+=tat[i];
         printf("%d\t%d\t%d\n",processes[i].PID,wt[i],tat[i]);
       }
}
int main(){
    int n=5;
    struct Process processes[]={
        {1,0,8},
        {2,1,1},
        {3,2,3},
        {4,3,2},
        {5,4,6}
    };
    sortProcesses(processes,n);
    avgtime(processes,n);
}