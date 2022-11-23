#include <stdio.h>

int main(){
    int x1,x2,x3,i=100,n=8,num;
    for(i;i<1000;i++){
        //printf("i=%d\n",i);
        if((i*7<1000)&&(i*7>=100)&&(i*9>=1000)){
        if(i*8<1000)n=9;
        for(x1=8;x1<=n;x1++){
            for(x2=0;x2<n;x2++){
                for(x3=8;x3<=n;x3++){
                num=x1*10000+7000+x2*100+x3*10;
                //printf("num=%d\n",num);
                if((num*i/100000000==0)&&(num*i/10000000!=0)){
                    printf("%d/%d=%d\n",num*i,i,num);
                    //print(num,i);
                }
                }
            
            }
        }
        }
    }
    return 0;
}

