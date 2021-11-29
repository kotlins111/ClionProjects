#include<iostream>
using namespace std;

#define MAXQSIZE 100 //最大队列长度
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define NOTFOUND -3

typedef char QElemType;
typedef int Status;


//队列链式结构体
typedef struct QNode{
    QElemType data;
    QNode *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front; //头指针
    QueuePtr rear; //尾指针
}LinkedQueue;


 


 //链队列初始化
 Status InitQueue(LinkedQueue &Q){
    Q.rear=Q.front=new QNode;
    if(!Q.front) exit(OVERFLOW);
    Q.front->next=NULL;
    return OK;

 }

 //链队列销毁
Status DestroyQueue(LinkedQueue &Q){
    while (Q.front)
    {
        QNode *p =Q.front->next;
        delete Q.front;
        Q.front=p;
    }
    return OK;
}

//链队列入队
Status EnQueue(LinkedQueue &Q,QElemType e){
    QNode *p = new QNode;
    if(!p) exit(OVERFLOW);
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}

//链队列出队
Status DeQueue(LinkedQueue &Q,QElemType &e){
    if(Q.rear==Q.front) return ERROR;
    QNode *p = Q.front->next;
    e=p->data;
    Q.rear->next=p->next;
    if(Q.rear==p) Q.rear==Q.front;
    delete p;
    return OK;
}

//获取队列队头元素
Status GetHead(LinkedQueue Q,QElemType &e){
    if(Q.rear==Q.front) return ERROR;
    e=Q.front->next->data;
    return OK;
}

int main(){
    return 0;
}