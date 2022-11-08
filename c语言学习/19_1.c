#include <stdio.h>
int main(){
    int n=0,i=1;
    double sum=0;
    while(1){
        n++;
        if(n%2)
            sum+=1.0/i;
        else
            sum-=1.0/i;
        if(1.0/i<1e-6){
            /*验证倒数第二项和最后一项的数值
            printf("%.15f\n",1.0/(i-3));   0.000001000000000
            printf("%.15f\n",1.0/i);       0.000000999997000
            */
            break;
        }
        i+=3;
    }
    printf("%.4f",sum);
}