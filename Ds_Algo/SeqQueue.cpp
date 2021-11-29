#define MAXQSIZE 100
#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define NOTFOUND -3

typedef char QElemType;
typedef int Status;

//队列的顺序表示
typedef struct {
    QElemType *base;  //初始化动态分配内存空间
    int front; //头指针 若队列不空，指向队首元素
    int rear;  //尾指针 若队列不空，指向队尾元素的下一位置 少用一个元素空间 
}SqQueue;


/*
循环队列
少用一个元素空间
队空 rear==front 
队满 (Q.rear+1)%QSIZE == front 
EnQUeue Q.rear=(Q.rear+1)%QSize
DeQUeue Q.front=(Q.front+1)%QSize

*/
//队列初始化

Status InitQueue(SqQueue &Q){
    //为队列数组分配内存空间
    Q.base = (QElemType*)malloc(sizeof(QElemType)*MAXQSIZE);
    if (!Q.base)
    {
        exit(OVERFLOW);
    }
    Q.front=0;Q.rear=0;
    
    return OK;
}

//获取循环队列的长度
int QueueLength(SqQueue Q){
    if(!Q.base) return ERROR;
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}


//循环队列入队
Status EnQueue(SqQueue &Q,QElemType e){
    if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return OK;
}

//循环队列出队 
Status Dequeue(SqQueue &Q,QElemType &e){
    if(Q.rear==Q.front) return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return OK;
}

//取队头元素 
Status GetHead(SqQueue Q,QElemType &e){
    if (Q.rear!=Q.front)
    {
        e=Q.base[Q.front];
        return OK;
    }
    return ERROR;

}
int main(){
    return 0;
}