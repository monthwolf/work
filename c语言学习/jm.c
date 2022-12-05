#include <stdio.h>
#include <string.h>
typedef struct{
    int num;
    char ch;
    char *po;
}same;

same getsame(same *,char *);
int main(){
    char str[100],*p=str,b[100];
    int i=0,j,a[100];
    same SAME,*po=&SAME;
    printf("请输入一串纯英文密码\n程序将自动进行加密\n");
    fgets(str,100,stdin);
    //len=strlen(str);
    for(;*p!='\n'&&*p!='\0';){
        getsame(po,p);
        a[i]=po->num;
        b[i++]=(po->ch)+2;
        p=po->po;
    }
    for(j=0;j<i;j++){
        printf("%d%c",a[j],b[j]);
    }
    printf("\n");
    return 0;
}
same getsame(same *p,char *str){
    int i=1;
    p->ch=*str;
    while(*(++str)==*(str-1))i++;
    p->num=i;
    p->po=str;
}