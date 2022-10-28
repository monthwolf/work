#include <stdio.h>
void str_pj(char *a,char *b);

int main(void){
    char str1[80]="Welcome to ",str2[20]="C language";
    /*
    char *p1,*p2;
    p1=str1;//指针指向数组首项,*p获取单项的值，p获取整个数列，知道匹配到'\0'停止
    p2=str2;
    while(*p1!='\0')p1++;
    while(*p2!='\0'){
        *p1=*p2;
        p1++;
        p2++;
    }
    p1=str1;//切记将指针返回首项
    printf("%s",p1);
    */
    str_pj(str1,str2);
}

//拓展：字符串拼接函数

void str_pj(char *a,char *b){
    int i=0;
    while(*a!='\0'){
        a++;
        i++;
    }
    while(*b!='\0'){
        *a=*b;
        a++;
        b++;
    }
    while(i>0)a--;
    printf("%s",a);
}