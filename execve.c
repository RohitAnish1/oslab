#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    pid_t p = fork();
    if(p==-1){
        perror("Error");
        exit(EXIT_FAILURE);
    }
    else if(p==0){
        char *args[]={"/usr/bin/env",NULL};
        char *envp[]={
        "MY VARIABLE=HELLO WORLD",
        "PATH=/usr/bin:/bin",
        NULL
        };
        if(execve("/usr/bin/env",args,envp)==-1){
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else{
           wait(NULL);
        }
}