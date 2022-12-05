#include <stdio.h>
#include <stdlib.h>

int main(){
    /*
    char *str1="hello",*str2="dog";
    char *str[51]={str1,str2},ch;
    FILE *fp;
    printf("%p\n",*str);//字符串首地址
    printf("%p\n",*(str+1));//
    printf("%p\n",str);//字符型数组首地址
    */
    int i=0,n=0;
    char str[50][100],ch;
    /*
    for(i;i<50;i++){
        fgets(str[i],100,stdin);
        printf("%s",str[i]);
    }
    */
    //printf("%p %d %p\n",str,str[0],str[2]);
    FILE *fp;
    printf("请创建单词列表（不超过50个单词）\n");
    a:printf("创建完成输入y/Y");
    if(!(scanf("%[yY]",&ch))){
        printf("请创建文件!\n");
        goto a;
    }
    if((fp=fopen("wordlist.txt","r"))==NULL)printf("failed!");
    while(1){
        if(fscanf(fp,"%s",str[i])==-1)break;
        //printf("%s\n",str[i]);
        i++;
    };
    /*success
    for(n=0;n<i;n++){
        printf("%s\n",str[n]);
    }
    */
    
    return 0;
}

