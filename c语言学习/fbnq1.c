#include <stdio.h>
int main(){
    int m,k,a[45],n=45,i=0;
    long sum=0;
    for(i;i<45;i++){
        if(i==0||i==1)a[i]=1;
        else a[i]=a[i-1]+a[i-2];
    }
    if(scanf("%d%d",&m,&k)!=2||!(m>0&&m<=k&&k<45))printf("ERROR");
    else{
        for(i=m-1;i<k;i++){
            sum+=a[i];
        }
        printf("sum=%ld\n",sum);
    }

    return 0;
}