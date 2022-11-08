#include <stdio.h>
#include <math.h>

int isPrime(int);//判断素数

int main(){
    int n=1,i=0;
    while(n<=100){
        if(isPrime(n)){
            i++;
            printf("%d ",n);
            if(i%5==0)
                printf("\n");
        }
        n++;
    }
    return 0;
}
int isPrime(int n){
    int i;
    for(i=2;i<=sqrt(n);i++){
        if(n%i==0)return 0;
    }
    return 1;
}