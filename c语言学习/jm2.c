#include <stdio.h>
typedef struct{
    int num;
    char ch;
    char *p;
}SAME;

int jm(SAME *,char *);
int main(){
    char str[100],*p=str;
    SAME same,*po=&same;
    int c,i;
    fgets(str,100,stdin);
    while(c=jm(po,str)){
        if(c>0)
        for(i=0;i<po->num;i++)
            printf("%c",po->ch);
        else 
            printf("%c",po->ch);
    }
    return 0;
}

int jm(SAME *same,char *p){
    if(*p!='\n'){
        if(*p>='1'&&*p<='9'){  
            same->num=*p++-48;
            same->ch=*p++-2;
            same->p=p;
            return 1;
        }
        else{
            same->ch=*p++-2;
            same->p=p;
            return -1;
        }
    }
    return 0;
}