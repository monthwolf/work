#include <stdio.h>
//介绍可以定义指向任意类型指针的void *p

int main(){
    int hoge=5;
    void *huge_p;  
    huge_p =&huge;
    //printf("%d\n",*huge_p);
    //前句将输出invalid use of void expression
    //因为在赋予该指针地址后需要声明其类型
    printf("%d\n",*(int*)huge_p);
    //此句首先将huge_p变量类型转换为int*
    //然后通过解引用（即*）式使地址指向huge的值
    return 0;
    //void *p写法比较繁琐，一般不采用
}