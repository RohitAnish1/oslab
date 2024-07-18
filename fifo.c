#include<stdio.h>
#define MAX_FRAMES 100

int frames[MAX_FRAMES];
int rear=-1;
void initialize(){
    for(int i=0;i<MAX_FRAMES;i++){
        frames[i]=-1;
    }
}

void display(){
    for(int i=0;i<rear;i++){
        printf("%d",frames[i]);
    }
    printf("\n");
}

void FIFO(int pages[],int n){
    int page_fault=0;
    int front=0;
    for(int i=0;i<n;i++){
        int page=pages[i];
        int found=0;
        for(int j=0;j<MAX_FRAMES;j++){
            if(frames[j]==page){
                found=1;
                printf("The page is found at %d",page);
            }
        }
        if(!found){
            page_fault++;
            if(rear<MAX_FRAMES-1){
                rear++;
            }
            else{
                rear=0;
            }
             frames[rear] = page;
            printf("Page %d added to frame %d\n", page, rear);
        }
        display();
    }
    printf("The number of page faults:%d",page_fault);
}

int main(){
    int n=7;
    int pages[]={1,3,0,3,5,6,3};
    initialize();
    FIFO(pages,n);
}