#include <stdio.h>
//指针的加法运算
//对地址进行加1，地址会增加当前指针指向的数据类型的长度
//该环境下int型长度为4
int main(){
    int hoge;
    int *hoge_p;
    hoge_p=&hoge;
    printf("hoge_p..%p\n",hoge_p);
    hoge_p++;
    printf("hoge_p..%p\n",hoge_p);
    printf("hoge_p..%p\n",hoge_p+3);
    return 0;
}