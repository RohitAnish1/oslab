#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
    pid_t p = fork();
    if(p<0){
        perror("Unsuccessful");
        exit(1);
    }
    else if(p==0){
        printf("The Child Process(PID:%d)is executing 1s-1\n",getpid());
        //Replacing Child Process
        char *args[]={"1s","1",NULL};
        execvp(args[0],args);
        //if execvp fails
        perror("execvp failed");
        exit(1);
    }
    else{
        printf("Parent Process(PID:%d) waiting for process to be complete\n",getpid());
        wait(NULL);
        printf("Child Process Successfully Executed");
    }
}