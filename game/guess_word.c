#include <stdio.h>
#include <stdlib.h>
char *getWord(char *,FILE *);

int main(){
    char *str1="hello",*str2="dog";
    char *str[51]={str1,str2},ch;
    FILE *fp;
    printf("%p\n",*str);//字符串首地址
    printf("%p\n",*(str+1));//
    printf("%p\n",str);//字符型数组首地址
    printf("请创建单词列表（不超过50个单词）\n");
    a:printf("创建完成输入y/Y");
    if(!(scanf("%[yY]",&ch))){
        printf("请创建文件!\n");
        goto a;
    }
    if(fp=fopen("wordlist.txt","r")==NULL)printf("failed!");
    getWord(str,fp);
    return 0;
}

char *getWord(char *w_l,FILE *fp){
    int i;
    //i=fscanf(fp,"%[^\n]",*(w_l++));
    printf("%p",w_l);
    
}