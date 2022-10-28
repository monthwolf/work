#include <stdio.h>
#include <stdlib.h>

typedef struct stu{
    unsigned long xh;
    char name[80];
    struct stu *next;
}STU;

STU *create(int n);//创建链表
void release(STU *head);//删除链表释放内存
void rdlb(STU *head);//读取链表数据
STU *addlb(STU *head);//添加链表成员
STU *dellb(STU *head);//删除链表成员

STU *create(int n){
    int i=0;
    STU *p,*q,*head=0;//*p用来存放每次获取的地址，*q用来存放进行链表连接的尾指针,*head用来存放首地址
    
    while(i++<n){
        if((p=(STU *)malloc(sizeof(STU)))==NULL){
            printf("Not able to allocate memory.\n");
            exit(-1);
        }
        //printf("%p",&p);
        printf("请输入第%d个学生学号、姓名\n",i);
        scanf("%lu%s",&p->xh,p->name);
        //printf("%lu %s\n",p->xh,p->name);
        if(head==0){
            head=p;
            q=p;
        }
        else{
            q->next=p;
            q=p;
        }
    }
    q->next=0;//链表的最后一个必须要将下一个连接设置为0；
    return(head);

}
void release(STU *head){
    STU *p;
    while(head){
        p=head;//从首地址开始释放
        head=head->next;//释放一个地址，将下一个地址设为首地址,直到下一个指向为0
        free(head);
    }
    printf("release success\n");
}

STU *addlb(STU *head){
    STU *q,*p=head,*f;
    if((q=(STU *)malloc(sizeof(STU)))==NULL){
        printf("failed!\n");
        exit(-1);
    }
    a:printf("请输入添加的学生学号、姓名：\n");
    scanf("%lu%s",&q->xh,q->name);
    q->next=0;
    if (q->xh<p->xh){
        q->next=p;
        head=q;
        return head;
    }
    while(p!=0&&(q->xh)>=(p->xh)){//p!=0判断应该在前面
    //若先判断第二个条件，则会出现p==0时,读取p->xh无法获取，程序出错
        if(q->xh==p->xh){
            printf("添加学号重复，请检查是否错误!\n");
            goto a;
        }
        f=p;//存放前一个链表成员
        //printf("%p",p->next);
        p=p->next;//存放后一个链表成员

    }
    f->next=q;
    q->next=p;
    return head;
}

void rdlb(STU *head){
    int i=1;
    STU *p=head;
    while(p!=0){
        printf("第%d个学生的学号是%lu,名字是%s\n",i,p->xh,p->name);
        p=p->next;
        i++;
    }
}
STU *dellb(STU *head){
    unsigned long num;
    STU *p=head,*f;
    printf("请输入学号查询需要删除的学生:\n");
    scanf("%lu",&num);
    while(p!=0&&p->xh!=num){
        f=p;
        p=p->next;
    }
    if(p!=0){
        f->next=p->next;
        return head;
    }
    else {
        printf("未查询到该学生!\n");
        return head;
    }
}
int main(){
    STU *head;
    int n;
    char a;
    printf("请输入录入学生数:\n");
    scanf("%d",&n);
    head=create(n);
    while(1){
        rdlb(head);
        printf("请检查数据,是否进行修改？(请输入y/n)\n");
        scanf("%*c%c",&a);
        switch(a){
            case 'y':{
                int i;
                printf("请问您要进行的操作是:\n1.添加学生信息\n2.删除学生信息\n");
                scanf("%d",&i);
                switch(i){
                    case 1:{
                        int n;
                        printf("请确定需要添加的学生数目:\n");
                        scanf("%d",&n);
                        while(n--){
                            head=addlb(head);
                        }
                        printf("添加成功!\n");
                        break;
                    }
                    case 2:{
                        printf("为避免恶意操作，一次只能删除一个学生信息\n");
                        head=dellb(head);
                        break;
                    }
                }
                break;
            }
            case 'n':{
                FILE *fp;
                STU *p=head;
                if((fp=fopen("学生信息.txt","w"))==NULL)printf("open failed!\n");
                while(p!=0){
                    fprintf(fp,"学号：%lu   姓名:%s\n",p->xh,p->name);
                    p=p->next;
                }
                if(fclose(fp)){
                    printf("can't close!\n");
                    exit(-1);
                }
                printf("文件写入成功!\n");
                exit(0);
            }
            default:printf("请规范输入!\n");break;
        }
    }
    return 0;
}

