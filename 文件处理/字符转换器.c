#include <stdio.h>
#include <stdlib.h>
//小记：之前运行了半天程序一直无法写入文件，而且也没有错误提示
//经过尝试后发现是因为在linux系统里面的用户读写权限没有完全获取
//可以通过 ls -al [文件夹/文件名]查询用户权限
//通过chmod [-R] 权限值 文件名  修改用户权限
//[-R]是表现连同子目录下所有文件
//各权限数字 r-->4   w-->2   x(execute)-->1
//所有者=rwx=4+2+1=7   所属组=rw-=4+2=6   其他人=r-x=5

int main(){
    char str[100];
    int i;
    FILE *fp;
    fp=fopen("test.txt","w");
    printf("请输入一行文字：");
    gets(str);
    //fopen成功打开文件返回文件缓存区地址，失败返回NULL
    if(fp==NULL){
        printf("fail to open the file!");
        exit(0);
        }
    else{
        for(i=0;str[i]!='\0';i++){
        if(str[i]>='a'&&str[i]<='z'){
            str[i]-=32;
            }
        fputc(str[i],fp);//输出当前字符，指针移向下一个字符
        //printf("%c",str[i]);
        }
    }
    //fclose成功关闭程序返回0，失败返回非零（负值）
    if(fclose(fp)){
        printf("fail to close the file!");
        exit(0);
    }
    return 0;
}