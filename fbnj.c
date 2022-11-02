#include <stdio.h>
unsigned long fbnj(int,int,int);

int main(){
    int T,i,x,a,b;
    unsigned long s;
    scanf("%d%d%d",&T,&a,&b);
    for(i=0;i<T;i++){
        scanf("%d",&x);
        s=fbnj(a,b,x);
        printf("%lu\n",s);
    }
    return 0;
}

unsigned long fbnj(int A,int B,int n){
    int x=1,y=1,temp;
    int i=0;
    for(i;i<n;i++){
        x%=1000000007;
        if(i<2);
        else{
            temp=y;
            y=(A*x+B*y)%1000000007;
            x=temp;
        }
    }
    return y;

}