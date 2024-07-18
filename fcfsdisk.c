#include<stdio.h>
#include <stdlib.h>

#define MAX_REQUEST 100
int calctotalseektime(int *request,int numRequest){
    int totalseektime=0;
    int currenttrack=0;
    //Iterate through process
    for(int i=0;i<numRequest;i++){
        int seektime=abs(currenttrack-request[i]);
        currenttrack=request[i];
        totalseektime+=seektime;
    }
    return totalseektime;
}

int main(){
    int request[MAX_REQUEST];
    int numRequest;
    printf("Enter the number of requests");
    scanf("%d",&numRequest);
    if(numRequest<0 || numRequest>MAX_REQUEST){
        printf("Invalid Response");
    }
    printf("Enter the requests");
    for(int i=0;i<numRequest;i++){
        scanf("%d",&request[i]);
    }
    int totalseektime=calctotalseektime(request,numRequest);
    printf("Total seek time:%d",totalseektime);
}