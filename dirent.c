#include<dirent.h>
#include<stdio.h>
int main(){
    DIR *dir = opendir(".");
    if(dir){
        struct dirent *entry;//Creating a new pointer
        printf("Curent Directory contents");
        while((entry=readdir(dir))!=NULL){//Reads each entry
        printf("%ds\n",entry->d_name);
        closedir(dir);}
    }
}