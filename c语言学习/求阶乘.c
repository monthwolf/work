#include <stdio.h>
//运用递归函数
int jc(int n);

int main(void){
    int res=jc(5);
    printf("%d",res);
    return 0;
}
int jc(int n){
    while(n!=1){
        return n*jc(n-1);
    }
    return n;
}
