#include <stdio.h>
#define NUM 30
void mybubble(int *pArr, int num)
{//使用冒泡排序法对数组pArr进行从小到大排序，num为数组元素的个数
	int i, j, t;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - i - 1; j++)
		{
			if (pArr[j] > pArr[j + 1])
			{
				t = pArr[j + 1];
				pArr[j + 1] = pArr[j];
				pArr[j] = t;
			}
		}
	}
}
int myfind(int *pArr, int key, int num)
{	//数组pArr已按从小到大排好序，key为要查找的关键字值，num为数组元素的个数
	//查找成功，返回该关键字值所在位置的下标，若查找失败则返回-1
	int m,a=0,b=num-1;
	if(pArr[a]==key){
		return a;
	}
	else if(pArr[b]==key){
		return b;
	}
	else{
		for(m=(a+b)/2;m!=a&&m!=b;m=(a+b)/2)
		if(pArr[m]>key){
			b=m;
		}
		else if(pArr[m]<key){
			a=m;
		}
		else return m;
	}
	return -1;

//填入实验s04128的相关代码


}
int myinsert(int *pArr, int key, int *num)
{	//数组pArr已按从小到大排好序，num为数组元素的个数，key为要插入的关键字值，插入后数组保持有序
	//插入成功后，返回插入位置的下标，若插入失败则返回-1
	//如果已经存在该关键字值元素，则插入失败
	int i,p;
	//检测是否重复
	if(myfind(pArr,key,*num)!=-1)return -1;
	else{
		//循环查找并存储位置
		for(i=0;i<*num;i++){
			if(pArr[i]>key){
				*num++;
				p=i;//存储插入位置
				break;
			}
		}
		//将原数组从插入位置开始向后移位
		for(i=p+1;i<*num;i++){
			pArr[i]=pArr[i-1];
		}
		//将数据插入
		pArr[p]=key;
		return p;
	}
//补充实现代码


}
int mydelete(int *pArr, int key, int *num)
{	//数组pArr已按从小到大排好序，num为数组元素的个数，key为要删除的值，删除后数组保持有序
	//删除成功后，返回该元素的下标，若删除失败则返回-1
	//如果不存在该关键字值元素，则删除失败
	int i,p;
	//检测是否存在,并用p存储下标
	if((p=myfind(pArr,key,*num))==-1)return -1;
	else{
		//更新数组元素个数
		*num--;
		//将原数组从插入位置开始向前移位
		for(i=p;i<*num;i++){
			pArr[i]=pArr[i+1];
		}
		//返回删除数据下标
		return p;
	}
//补充实现代码
}
void printarray(int *pArr, int num)
{
	int i;
	for (i = 0; i < num; i++)
		printf("\t%d", *pArr++);
	printf("\n");
}

int main()
{
	int MA[NUM] = { 34, 76, 23, 67, 345, 234, 21, 78, 172, 90 };
	int nums = 10;//数组元素个数
	int mkey, nkey, k;
	mybubble(MA, nums);
	scanf("%d%d", &mkey, &nkey);//输入2个整数
	k = myinsert(MA, mkey, &nums);
	if (k < 0)
		printf("insert ERROR\n");
	else
		printf("insert SUCCESS\t%d\n", k);
	k = mydelete(MA, nkey, &nums);
	if (k < 0)
		printf("delete ERROR\n");
	else
		printf("delete SUCCESS\t%d\n", k);
	printarray(MA, nums);
	return 0;
}