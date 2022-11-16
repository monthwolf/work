#include <stdio.h>
#include <stdlib.h>
int main(){
    int sum=0,i=0,n,m,j=0,a[20]={0};
    if((scanf("%d%d",&n,&m)!=2)||!(n<20&&m>0&&m<20)){
        printf("ERROR\n");
        exit(0);    
    };
    for(i=0;i<n;i++){
        a[i]=i+1;
    }
    while(1){
        for(i=0;i<n;i++){
        if(a[i])j++;
        //printf("%d\n",n);
        if(j==m){
            printf("%d\n",a[i]);
            a[i]=0;
            j=0;
            sum++;
            //printf("sum:%d\n",sum);
        }
    }
    if(sum==n)break;
    }
    return 0;
}