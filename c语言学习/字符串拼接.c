#include <stdio.h>
char *str_pj(char *a,char *b);

int main(void){
    char str1[200],str2[80],*p;
    printf("please input string1:\n");
    fgets(str1,200,stdin);
    fflush(stdin);
    printf("please input string2:\n");
    fgets(str2,80,stdin);
    /*
    char *p1,*p2;
    p1=str1;//指针指向数组首项,*p获取单项的值，p获取整个数列，直到匹配到'\0'停止
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
    p=str_pj(str1,str2);
    printf("%s",p);
}

//拓展：字符串拼接函数

char *str_pj(char *a,char *b){
    int i=0;
    while(*a!='\0'&&*a!='\n'){
        a++;
        i++;
    }
    while(*b!='\0'){
        *a=*b;
        a++;
        b++;
        i++;
    }
    while(i>0){
        a--;
        i--;
    }
    return a;
}