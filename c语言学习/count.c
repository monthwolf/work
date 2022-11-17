#include <stdio.h>
#define N 4
int fun(int x[][N],int a[],int b[]);
int main(){
    int a[N*N]={0},b[N*N]={0},x[N][N]={5,6,6,7,8,1,5,6,8,7,6,7,5,5,1,8};
    fun(x,a,b);
    return 0;
}

int fun(int x[][N],int a[],int b[]){
    int i,j,k,ist,n=0;
    a[0]=x[0][0];
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            ist=1;
            for(k=0;k<=n;k++){
                if(x[i][j]==a[k]){
                    //printf("%d\n",b[k]);
                    b[k]++;
                    ist=0;
                    break;
                }
            }
            if(ist){
                n++;
                a[n]=x[i][j];
                //b[n]=1;
            }
        }
    }

    for(k=0;k<=n;k++){
        printf("%d:%d  ",a[k],b[k]);
    }
    

    return 0;
}