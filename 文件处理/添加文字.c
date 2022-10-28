#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *fp;
    char str[100],ch;
    if((fp=fopen("test.txt","a+"))==NULL)printf("can't open test.txt!");
    gets(str);
    if(fputs(str,fp)==-1)printf("puts failed!");//fputs会让文件位置指针移到末尾
    rewind(fp);
    //printf("%ld",ftell(fp));
    while(!feof(fp)){
        if((ch=fgetc(fp))!=255)//255会在末尾输出菱形问号
        printf("%c",ch);
    }
    printf("\n");
    if(fclose(fp))printf("can't close test.txt");
    return 0;
}