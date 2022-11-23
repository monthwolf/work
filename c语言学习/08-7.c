#include <stdio.h>
int check(int,int);
int main(){
    int x1,x2,x3,i=100,n=8,num,count=0;
    for(i;i<1000;i++){
        //printf("i=%d\n",i);
        if((i*7<1000)&&(i*7>=100)&&(i*9>=1000)){
        if(i*8<1000)n=9;
        for(x1=8;x1<=n;x1++){
            for(x2=1;x2<n;x2++){
                for(x3=8;x3<=n;x3++){
                num=x1*10000+7000+x2*100+x3*10;
                //printf("num=%d\n",num);
                if((num*i/100000000==0)&&(num*i/10000000!=0)){
                    if(check(num,i)){
                        printf("%d/%d=%d\n",num*i,i,num);
                        count++;
                    }
                    //print(num,i);
                }
                }
            
            }
        }
        }
    }
    printf("sum:%d",count);
    return 0;
}
int check(int num,int i){
    int j,a[4],x=num/10,y,d=10000;
    for(j=0;j<4;j++){
        a[j]=x%10;
        x/=10;
        //printf("a[%d]=%d\n",j,a[j]);
    }
    x=i*num/d-i*a[--j];
    if(x<100&&x>=10){
        y=x*10+i*num%d/1000;
        d/=10;
        x=y-i*a[--j];
        if(x<1000&&x>=100){
            y=x*10+i*num%d/100;
            x=y-i*a[--j];
            if(x<100&&x>=10)return 1;
        }

    }
    return 0;
}