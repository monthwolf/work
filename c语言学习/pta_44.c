#include <stdio.h>
void *getNum(int num,int *a);
void sort(int *a);
int main(){
    int num,a[3],x,y,i=1;
    scanf("%d",&num);
    do{
        getNum(num,a);
        sort(a);
        x=a[0]*100+a[1]*10+a[2];
        //printf("%d",x);
        y=a[2]*100+a[1]*10+a[0];
        num=x-y;
        printf("%d: %d - %d = %d\n",i++,x,y,num);
    }while(num!=495);
}

void *getNum(int num,int *a){
    int i=0;
    while(num){
        a[i]=num%10;
        num/=10;
        i++;
    }
}

void sort(int *a){
    int i,j,t;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            if(a[j]<a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}