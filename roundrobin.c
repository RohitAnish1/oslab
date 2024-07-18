#include<stdio.h>

struct Process{
    int id;
    int burst_time;
};

void roundrobin(struct Process processess,int time_quantum,int n){
    int remainingtime[n];
    int wt[n],tat[n];
    for(int i=0;i<n;i++)
        remainingtime[i]=processess[i].burst_time;
       int current_time=0;
       int completed=0;
       while(completed<n){
        int flag=0;
        for(int i=0;i<n;++i){
            if(remainingtime[i]>0){
                flag=1;
                if(remainingtime[i]<time_quantum){
                    current_time += remainingtime;
                    remainingtime[i]=0;
                    printf("Process P%d completed at time %d seconds",processess[i].id,current_time);
                    tat[i]=current_time;
                    wt[i]=tat[i]-processes.burst_time;
                    printf("Process P%d\t\tWT=%d\t\tTAT=%d\n",processes[i].id,wt[i],tat[i]);
                    completed++;
                }else{
                    current_time += time_quantum;
                    remainingtime -= time_quantum;
                }
            }
        }
        if (!flag)
       break;
       }
       float awt=0;
       float atat=0;
       for(int i=0;i<n;i++){
        awt=awt+wt[i];
        atat=atat+tat[i];
       }
       printf("Average Waiting Time:%f\tAverage TAT:%f\n",awt,atat);
}
int main(){
    int n=5;
    struct Process processess[]={
        {1,4},
        {2,3},
        {3,5}
    };
    int time_quantum=2;
    roundrobin(processess,time_quantum,n);
}