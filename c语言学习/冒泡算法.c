#include <stdio.h>
void mp(int a[],int n);
int main(void){
    int a[]={1,65,23,97,324,87,44,16,76,22,906,2,55,34,67};
    mp(a,15);
    return 0;
}

void mp(int a[],int n){
    int i,tmp,j=n;
    while(n!=1){
        for(i=0;i<j;i++){
            if(a[i]>=a[i+1])continue;
            else{
                tmp=a[i];
                a[i]=a[i+1];
                a[i+1]=tmp;
            }
        }
        n--;
    }
    for(i=0;i<=j;i++){
        printf("%d  ",a[i]);
    }
}