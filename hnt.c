#include <stdio.h>
int i=1;
void hnt(int,int,char,char,char);
int main(){
    hnt(3,2,'A','B','C');
    return 0;
}

void hnt(int r,int n,char A,char B,char C){
    //n1开始 n2辅助 n3终止
    if(n==1&&i==r){
        i++;
        if(i==r)printf("1\n");
    }
    else{
        hnt(r,n-1,A,C,B);//n-1个到辅助柱B
        i++;//最后一个到C
        if(i==r)printf("%d",n);
        hnt(r,n-1,B,A,C);//n-1从B到C
    }
}