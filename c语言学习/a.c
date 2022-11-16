#include <stdio.h>
int main(){
    int x,a[100]={0},b[]={2,4,5,3,6,5,-1};
    int i=0;
    while(b[i]>-1){
        x=b[i];
        a[x]++;
        i++;
    }
    for(x=0,i=0;i<100;i++){
        while(a[i]){
            x++;
            (x%3==0)?printf("%4d\n",i):printf("%4d",i);
            a[i]--;//a[5]=2 会运行两次
        }
    }
    return 0;
}