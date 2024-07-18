#include<stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
};

int findshortestjob(struct Process processes[],int n,int current_time,int rt[]){
    int shortest_job=-1;
    int min_burst_time=INT_MAX;
    for(int i=0;i<n;i++){
        if(processes[i].arrival_time<=current_time && processes[i].burst_time<=min_burst_time && rt[i]!=0){
            min_burst_time=processes[i].burst_time;
            shortest_job=i;
        }
    }
    return shortest_job;
}

void calculatetime(struct Process processes[],int n,int tat[],int at[],int wt[]){
    int remainingtime[n];
    for(int i=0;i<n;i++)
    remainingtime[i]=processes[i].burst_time;
    int completed=0;
    int current_time=0;
    int shortestjobs[50];
    int i=0;
    while(completed<n){
        int shortest_job=findshortestjob(processes,n,current_time,remainingtime);
        shortestjobs[i++]=shortest_job;
        if(shortest_job==-1){
            current_time++;
            continue;
        }
        remainingtime[shortest_job]--;
        current_time++;
        if(remainingtime[shortest_job]==0){
            tat[shortest_job]=current_time-processes[shortest_job].arrival_time;
            wt[shortest_job]=tat[shortest_job]-processes[shortest_job].burst_time;
            completed++;
        }
        }
    }
 void avgfind(struct Process processes[],int n){
     int total_wt=0,total_tat=0;
     int wt[n],tat[n],at[n];
     printf("Process\tWT\tTAT\n");
     calculatetime(processes,n,tat,at,wt);
     for(int i=0;i<n;i++){
         total_wt+=wt[i];
         total_tat+=tat[i];
         printf("%d\t%d\t%d\n",processes[i].pid,wt[i],tat[i]);
     }
     printf("The average waiting time is:%.2f\n",(float)total_wt/n);
     printf("The average turnaround time is:%.2f\n",(float)total_tat/n);
 }
 
 int main() {
    int n = 5; // Number of processes
    struct Process processes[] = {
        {1, 0, 8},
        {2, 1, 1},
        {3, 2, 3},
        {4, 3, 2},
        {5, 4, 6}
    };

    // Calculate average waiting time and turnaround time
    avgfind(processes, n);

    return 0;
}