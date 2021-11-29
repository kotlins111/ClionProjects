#include<iostream>
using namespace std;

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define NOTFOUND -3

typedef char SElemType;
typedef int Status;

//链栈
typedef struct StackNode{
    SElemType data;
    StackNode *next;
}StackNode,*LinkStack;


//链栈的初始化

void InitStack(LinkStack &s){
    s=NULL;
}

//链栈判空

bool StackEmpty(LinkStack S){
    return S==NULL;
}

//链栈入栈
Status Push(LinkStack &S,SElemType e){
    StackNode *p = new StackNode;
    p->data=e;
    p->next=S;S=p;
    return OK;
}
//链栈出栈
Status Pop(LinkStack &s,SElemType &e){
    if(s==NULL) return ERROR;
    e=s->data;
    StackNode *p =s;
    s=s->next;
    delete p;
    return OK; 
}

//链栈获取栈顶元素

Status GetTop(LinkStack s,SElemType &e){
    if(s) return ERROR;
    e=s->data;
    return OK;
}
int main(){

    LinkStack s;
    return 0;
}