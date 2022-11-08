#include <stdio.h>
#include <stdlib.h>
void px(int *,int);
int main(){
    int n;
    if(!scanf("%d",&n)||!(n>0&&n<10)){
        printf("ERROR");
        exit(0);
    }
    int m[n],i;
    for(i=0;i<n;i++){
        if(!scanf("%d",&m[i])){
            printf("ERROR");
            exit(0);
        }
    }
    px(m,n);
    for(i=0;i<n;i++)printf("\t%d",m[i]);
    return 0;
}

void px(int *num,int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(num[j]>num[j+1]){
                temp=num[j+1];
                num[j+1]=num[j];
                num[j]=temp;
            }
        }
    }
}
