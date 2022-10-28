#include <stdio.h>
#include <stdlib.h>
void search_str(char *str,char *string);//查找字符串函数
int main(void){
    char s[50];//需要查找的字符串
    char str[100];
    printf("该程序将帮你查找第一段字符串是否存在于第二段字符串中\n");
    printf("请输入第一段字符串:\n");
    scanf("%s",s);
    getchar();
    printf("请输入第二段字符串:\n");
    gets(str);
    //最好使用scanf("%[^\n]",str),因为gets可能会出现字符串溢出
    //%[]读取字符合集
    //例如%[a-z]读取a-z的字符合集，
    //^代表反，%[^a-z]代表读取不是a-z的字符合集，遇到a-z之间的字符就停止
    //scanf数据类型前带*代表读取该数据但不保存
    //scanf同样可读取A-Z,0-9，也可以一次读取多种类型  例如[a-zA-Z]
    //scanf("%*[^\n]");scanf("%*c")   清空输入缓冲区
    //第一句丢弃除换行符之外的其他输入,键入回车后，缓冲区只留下换行符，第二句匹配换行符并丢弃，缓冲区清空
    search_str(s,str);
    return 0;
}

void search_str(char *str,char *string){
    int i,n,check=0;
    char *f=str;
    char *g=string;
    for(i=0;*str!='\0';i++)
        str++;
    str=f;
    for(;(*string!=*f)&&(*string!='\0');string++);
    for(n=0;n<i;n++){
        check=((*(str+n))==(*(string+n)));
    }
    
    if(check){
        printf("%s存在于%s中!\n",f,g);
        exit(0);
        }
    else{
        printf("无法在%s中查找到字符串%s!\n",g,f);
        exit(0);
        }
}