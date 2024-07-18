#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include <sys/types.h>

int calculatesum(int start,int end){
    int sum=0;
    for(int i=start;i<=end;i++){
        sum += i;
    }
    return sum;
}

int main(){
    int n;
    printf("Enter the digits");
    scanf("%d",&n);
    pid_t pid=fork();
    if(pid==-1){
        perror("Error Found");
        exit(EXIT_FAILURE);
    }
    else if(pid==0){
        int sum=calculatesum(0,n/2);
        printf("The sum of first numbers is:%d\n",sum);
        exit(sum);
    }
    else{
        pid_t pid2=fork();
        if(pid2==-1){
        perror("Error Found");
        exit(EXIT_FAILURE);
    }
    else if(pid2==0){
        int sum=calculatesum((n/2)+1,n);
        printf("The sum of last numbers is:%d\n",sum);
        exit(sum);
    }
    else{
        int status1,status2;
        waitpid(pid,&status1,0);
        waitpid(pid2,&status2,0);
        int total_sum = WEXITSTATUS(status1)+WEXITSTATUS(status2);
        printf("The total sum is:%d\n",total_sum);
    }
    }
}