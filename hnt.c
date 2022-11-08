/*
写在前面的话:我写的函数本来是用来输出第r次移动的，所以有if(i==r)的判断
为了让你看到全部变化，所以就都注释掉了，如果你想看第r次移动，就把注释语句前的//删掉
hnt函数中，各形参的含义
r：第r次移动
n:多少个盘子
A:起始移动的柱子
B：辅助移动的柱子
C:最终到达的柱子
其实思路就是n个盘子从一个柱子到另一个柱子需要借助辅助柱进行移动
搞清楚逻辑关系就好了
*/

#include <stdio.h>
int i=0;
void hnt(int,int,char,char,char);//输出第r次移动
int main(){
    hnt(1,5,'A','B','C');//前面两个值自己改着看看，r不要超过最大移动次数哦
    //比方n=5的时候，r不要超过31  :)
    return 0;
}

void hnt(int r,int n,char A,char B,char C){
    //n1开始 n2辅助 n3终止
    if(n==1){
        i++;
        //if(i==r)
        printf("第%d次 1号移动%c-->%c\n",i,A,C);
    }
    else{
        hnt(r,n-1,A,C,B);//n-1个到辅助柱B
        //最后一个到C
        i++;
        //if(r==i)
        printf("第%d次 %d号移动%c-->%c\n",i,n,A,C);
        hnt(r,n-1,B,A,C);//n-1从B到C
    }
}