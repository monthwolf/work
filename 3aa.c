#include<stdio.h>
int main (void)
{
    int num;
    float score;
    double s;
    printf("请依次输入变量num,score,s的值\n");
    scanf("%d",&num);
    scanf("%f",&score);
    scanf("%lf",&s);
    printf("num=%d,score=%f,s=%.2f\n",num,score,s);
    return 0;
}