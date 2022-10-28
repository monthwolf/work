#include <stdio.h>
//直接调用函数获取变量的值是无法使变量的值交换的

/*函数基础补充
形参：接受实参的一方,如func(int hoge)←hoge是形参
实参：调用函数时的参数，如func(5)←5是实参

从主函数直接进行变量的交换可以正确输出
#include <stdio.h>
int main (){
    int a=5,b=10,itemp;
    temp=a;
    a=b;
    b=temp;
    printf("a..%d   b..%d",a,b);
    return 0;
}
可知函数对变量值的调换
在不改变地址的情况下只能在函数内部实现

PS：仅仅只是交换整型变量的值可以使用宏定义
#define SWAP(a,b)(a+＝b,b=a-b,a-=b)
但是该宏定义不可用于颠倒使用同一个变量
eg:SWAP(a[i],a[j])且恰好i＝＝j是不行的
*/
void swap2(int *x,int *y);
//int swap(int x,int y);

int main (){
    int a=5,b=10;
    //int *a_p=&a,*b_p=&b;
    /*
    swap(a,b);
    printf("a..%d  b..%d",a,b);
    输出的数值不会交换
    */
    swap2(&a,&b);
    printf("a..%d  b..%d",a,b);
    return 0;
}

void swap2(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

/*
int swap(int x,int y){
    int temp;
    temp=x;
    x=y;
    y=temp;
    return 0;
}
*/