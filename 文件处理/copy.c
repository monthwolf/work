#include <stdio.h>
int main(){
    FILE *fp1;
    FILE *fp2;
    int ch;
    if((fp1=fopen("test.txt","r"))==NULL)printf("can't open test.txt!");
    if((fp2=fopen("copy.txt","w"))==NULL)printf("can't open copy.txt!");
    //下面该句中用feof(fp1)来进行判断会比较好
    while((ch=fgetc(fp1))!=-1){
        fputc(ch,fp2);
    }
    if(fclose(fp1))printf("can't close test.txt");
    if(fclose(fp2))printf("can't close copy.txt");
    return 0;
}