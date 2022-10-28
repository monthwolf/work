#include <stdio.h>
//学习地址的赋予和修改

int main (void){
    int hoge=5;
    int piyo=10;
    int *hoge_p;
    /*输出每个变量的地址，
    &是地址运算符，
    %p即按十六进制输出地址,根据编译器输出相应位数
    （一般是32位或者64位左边空缺则会补0）
    (注意与%x区分,%x只是输出十六进制数，与地址无关,
    同时在编译器范围内有多少位输出多少位，不会在左边补0)
    
    */
    printf("&hoge..%p\n",&hoge);
    printf("&piyo..%p\n",&piyo);
    printf("&hoge_p..\n",&hoge_p);
    //将hoge的地址赋予hoge_p
    hoge_p=&hoge;
    printf("hoge_p..%p\n",hoge_p);
    //通过hoge_p输出hoge的内容
    printf("*hoge_p..%d\n",*hoge_p);
    //通过hoge_p修改hoge的内容
    *hoge_p=10;
    printf("hoge..%d\n",hoge);
    return 0;
}