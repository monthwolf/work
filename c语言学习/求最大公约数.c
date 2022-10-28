#include <stdio.h>
int gcd(int m,int n);
int main(void){
    int res;
    res=gcd(133,23);
    printf("%d",res);
    return 0;
}

int gcd(int m,int n){
     while(m%n!=0){
        return gcd(n,m%n);
     }
    return n;


}