#include <stdio.h>
#include <stdlib.h>

typedef struct acc{
    unsigned long num;
    char name[20],pass[20];
}STU;//创建结构体STU

int main(){
    STU stu[]={0},*p=stu;
    FILE *fp;
    char an;
    int s;
    int i=0,n=0;
    printf("请输入账号、昵称、密码（中间用空格分隔,退出请在账号处输入exit）:\n");
    while(scanf("%lu%s%s",&stu[i].num,&stu[i].name,&stu[i].pass)==3){
        i++;
    }//i为数组中数据个数
    stu[i].num=0;
    if((fp=fopen("账号.txt","w+"))==NULL)printf("无法打开文件！");
    while((p->num)!=0){
        fprintf(fp,"账号：%lu  昵称：%s  密码：%s\n",p->num,p->name,p->pass);
        p++;
    }
    printf("是否进行账号查询?(y/n)\n");
    scanf("%c",&an);
    if(an=='y'){
        printf("输入账号查询:\n");
        scanf("%d",&s);
        for(n=0;n<=i;n++){
            if(s==p->num){
                printf("搜索到用户!\n昵称:%s  密码%s",p->name,p->pass);
                if(!fclose(fp))printf("无法关闭文件!\n");
                exit(0);
            }
            else p++;
        }
        if(!fclose(fp))printf("无法关闭文件!\n");
        printf("未查询到用户!");
    }

    return 0;
}