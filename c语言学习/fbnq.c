#include <stdio.h>
int getNum(int *,int);

int main(){
    int a[45],m,k;
    getNum(a,45);
    //printf("%d",a[0]);
    if((scanf("%d%d",&m,&k)!=2)||!(m>0&&m<=k&&k<45))printf("ERROR");
    else{
        int i=m-1;
        long sum=0;
        for(i;i<k;i++){
            sum+=a[i];
        }
        printf("sum=%ld\n",sum);
    }
    return 0;
}

int getNum(int *a,int n){
    if(n==1||n==2){
        return a[n-1]=1;
    }
    else{
        return a[n-1]=(getNum(a,n-1)+getNum(a,n-2));
    }
}