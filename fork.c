#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    pid_t p = fork();//return value of fork
    if(p<0){
        perror("Fork Failed");
        exit(1);
    }
    else if(p==0){
        printf("Hello from Child Process (PID:%d)\n",getpid());
    }
    else{
        printf("Hello from Parent Process (PID:%d)\n",getpid());
    }
    return 0;
}