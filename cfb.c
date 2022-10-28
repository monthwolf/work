#include <stdio.h>
void cfb();
int main(){
    int num1,num2;
    printf("请输入横纵最大数：");
    scanf("%d%d",&num1,&num2);
    cfb(num1,num2);
    return 0;
}
void cfb(int c,int d){
    printf("让我给你输出一个乘法表:)\n");
    int a,b;
    for(a=1;a<=c;a++){
        for(b=1;b<=d;b++){
            printf("%d\t",a*b);
        }
        printf("\n");
    }
}
