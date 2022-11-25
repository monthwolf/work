#include <stdio.h>
#define NUM 30
void mybubble(int *pArr, int num)
{//ʹ��ð�����򷨶�����pArr���д�С��������numΪ����Ԫ�صĸ���
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
{	//����pArr�Ѱ���С�����ź���keyΪҪ���ҵĹؼ���ֵ��numΪ����Ԫ�صĸ���
	//���ҳɹ������ظùؼ���ֵ����λ�õ��±꣬������ʧ���򷵻�-1
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

//����ʵ��s04128����ش���


}
int myinsert(int *pArr, int key, int *num)
{	//����pArr�Ѱ���С�����ź���numΪ����Ԫ�صĸ�����keyΪҪ����Ĺؼ���ֵ����������鱣������
	//����ɹ��󣬷��ز���λ�õ��±꣬������ʧ���򷵻�-1
	//����Ѿ����ڸùؼ���ֵԪ�أ������ʧ��
	int i,p;
	//����Ƿ��ظ�
	if(myfind(pArr,key,*num)!=-1)return -1;
	else{
		//ѭ�����Ҳ��洢λ��
		for(i=0;i<*num;i++){
			if(pArr[i]>key){
				*num++;
				p=i;//�洢����λ��
				break;
			}
		}
		//��ԭ����Ӳ���λ�ÿ�ʼ�����λ
		for(i=p+1;i<*num;i++){
			pArr[i]=pArr[i-1];
		}
		//�����ݲ���
		pArr[p]=key;
		return p;
	}
//����ʵ�ִ���


}
int mydelete(int *pArr, int key, int *num)
{	//����pArr�Ѱ���С�����ź���numΪ����Ԫ�صĸ�����keyΪҪɾ����ֵ��ɾ�������鱣������
	//ɾ���ɹ��󣬷��ظ�Ԫ�ص��±꣬��ɾ��ʧ���򷵻�-1
	//��������ڸùؼ���ֵԪ�أ���ɾ��ʧ��
	int i,p;
	//����Ƿ����,����p�洢�±�
	if((p=myfind(pArr,key,*num))==-1)return -1;
	else{
		//��������Ԫ�ظ���
		*num--;
		//��ԭ����Ӳ���λ�ÿ�ʼ��ǰ��λ
		for(i=p;i<*num;i++){
			pArr[i]=pArr[i+1];
		}
		//����ɾ�������±�
		return p;
	}
//����ʵ�ִ���
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
	int nums = 10;//����Ԫ�ظ���
	int mkey, nkey, k;
	mybubble(MA, nums);
	scanf("%d%d", &mkey, &nkey);//����2������
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