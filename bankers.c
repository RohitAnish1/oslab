#include<stdio.h>

int main(){
    int n,m,i,j,k;
    n=5;
    m=3;
    int allot[5][3]={
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };
    int max[5][3]={
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };
    int avail[]={3,3,2};
    
    int f[n],ans[n],ind=0;
    //Initilise f[n]
    for(k=0;k<n;k++){
        f[k]=0;
    }
    //Need Matrix
    int need[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-allot[i][j];
        }
    }
    int y=0;
    //Check if there is any available resource
    for(k=0;k<n;k++){
        int flag;
        for(i=0;i<n;i++){
            if(f[i]==0){
                flag=0;
                for(j=0;j<m;j++){
                    if(need[i][j]>avail[j]){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0){
                ans[ind++]=i;//Added to safe sequence
                for(y=0;y<n;y++){
                    avail[y]+=allot[i][y];//Avail update
                }
                f[i]=1;
            }
        }
    }
    int flag=1;
    for(i=0;i<n;i++){
        if(f[i]==0){
            flag=0;
            printf("This is not a safe sequence");
        }
    }
    if(flag==1){
        printf("The following is the safe sequence:\n");
        for(i=0;i<n-1;i++){
            printf("P%d->",ans[i]);
        }
            printf("P%d",ans[n-1]);
    }
}