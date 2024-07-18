#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
    char *filename="my_file.txt";
    int fd;//File discriptor
    //Create FIle
    fd=open(filename,O_CREAT | O_WRONLY,0644);
    if(fd==-1){
        perror("unable to open");
        exit(EXIT_FAILURE);
    }
    //Writedata
    const char*data="Hello World";
    ssize_t bytes_written = write(fd,data,strlen(data));
    close(fd);
    //Reopen
    fd=open(filename,O_RDONLY);
    if(fd==-1){
        perror("unable to open");
        exit(EXIT_FAILURE);
    }
    //Readdata
    char buffer[100];
    ssize_t bytes_read= read(fd,buffer,sizeof(buffer));
    if(bytes_read>0){
        printf("%ld",bytes_read);
    }
    close(fd);
}