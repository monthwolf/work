#include <stdio.h>
#include <stdlib.h>
void px(int *,int);
int main(){
    int n;
    if(!scanf("%d",&n)||!(n>0&&n<10)){
        printf("ERROR");
        exit(0);
    }
    int m[n],i;
    for(i=0;i<n;i++){
        if(!scanf("%d",&m[i])){
            printf("ERROR");
            exit(0);
        }
    }
    px(m,n);
    for(i=0;i<n;i++)printf("\t%d",m[i]);
    return 0;
}
/*
px(int *num,int n)

num:数组首地址
n:数组中元素个数

PS:关于里层循环的判断条件n-1-j
首先j与j+1进行比较，所以j最大为n-2(j+1即为n-1,也就是最大下标)
每次判断之后，都会有一个大的数到达数列后方
(例如第一次，最大数移动到数组最后一个，下一次判断不可能有比它更大的数，
i恰好可以代表已经排序的数,比方说第一次循环后，i=1相当于一个数已经排序完成,
这个时候就可以把这个数剔除出去,即判断语句可以写成j<n-1-i
)
*/
void px(int *num,int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){//排序n个数据，需要大循环比较n-1次,每次完成排序一个数
        for(j=0;j<n-1-i;j++){//从第一个数据开始比较
            if(num[j]>num[j+1]){
                temp=num[j+1];
                num[j+1]=num[j];
                num[j]=temp;
            }
        }
    }
}
