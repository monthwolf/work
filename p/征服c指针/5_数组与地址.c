#include <stdio.h>

int main(void){
    int array[5];
    int i;
    //为数组各元素赋值
    for (i=0;i<5;i++){
        array[i]=i;
    }
    //输出数组元素值
    for (i=0;i<5;i++){
        printf("%d\n",array[i]);
    }
    //输出数组各元素地址
    for (i=0;i<5;i++){
        printf("&array[%d]..%p\n",i,&array[i]);
    }
    return 0;
}
/*输出结果如下
0
1
2
3
4
&array[0]..0x7fd9abcfc0
&array[1]..0x7fd9abcfc4
&array[2]..0x7fd9abcfc8
&array[3]..0x7fd9abcfcc
&array[4]..0x7fd9abcfd0

可见相邻元素间相差4字节，恰为int型的长度
*/