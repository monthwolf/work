#include <stdio.h>
#include <time.h>
#include <stdlib.h>
signed int X;
signed int Y; 
signed int X0;
signed int Y0;
char get_move;
char input;
void move();
void pos();
void start_up();
void start_pos();
void food_pos();

int main(){
    start_up();
    start_pos();
    food_pos();
    while (1){
    scanf("%c",&get_move);
     
    move();
    getchar();
    }
    return 0;
}

void start_up(){
    //初始化界面
    int num1;
    int num2;
    char line[4]="一";
    for(num1=1;num1<=50;num1++){
        printf("%s",line);
    }
    num1=1;
    for(num2=1;num2<=48;num2++){
        printf("\n│");
        int num3=1;
        while (num3<=49){
            printf("  ");
            num3++;
        }
        printf("│");
    }
    printf("\n");
    for (num1;num1<=50;num1++){
        printf("%s",line);
    }
}
void move(){
    //检测贪吃蛇向上移动
    if (get_move=='w')
        Y+=1;
    else if (get_move =='s')
    //检测贪吃蛇向下移动
        Y-=1;
    //检测贪吃蛇向左移动
    else if (get_move =='a')
        X-=1;
    //检测贪吃蛇向右移动
    else if (get_move == 'd')
        X+=1;
}

void food_pos(){
    //随机生成食物位置
    srand(time(0));
    X0=rand()%48+2;
    Y0=rand()%48+2;
    printf("food(%d,%d",X0,Y0);
}
void start_pos(){
    //初始化贪吃蛇位置
    X=25;
    Y=25;
}
void pos(){
    //检测贪吃蛇与食物目前位置
    
}
