#include <stdio.h>
int main(void){
    int array[5];
    int *p;
    int i;
    //给数组array的各元素设定值
    for (i=0;i<5;i++){
        array[i]=i;
    }
    //输出数组各元素的值（指针）
    for (p=&array[0];p!=&array[5];p++){
        printf("%d\n",*p);
        //实际上并不存在array[5]
    }

    /*另一种书写方法
    for (i=0;i<5;i++){
        printf("%d\n",*(p+i))
    }
    这种写法指针并没有就前进，而是固定不变的，只是在打印时增加i
    */
}