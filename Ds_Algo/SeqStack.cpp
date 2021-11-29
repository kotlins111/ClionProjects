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

//栈的 顺序存储结构体定义

/*top 指向栈顶的上一个元素 base 指向栈底元素 
 栈的判空 base==top  
栈的判满 top-size==stacksize */
typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;


//顺序栈的初始化
Status InitStack(SqStack &s){
    s.base = new SElemType[MAXSIZE];
    if (!s.base)
    {
        /* code */
        exit(OVERFLOW);
    };
    s.top = s.base; //栈顶指针等于栈底指针 空栈
    s.stacksize =MAXSIZE;
    return OK;
}

//栈的判空
bool StackEmpty(SqStack s){

    return s.base == s.top;
}

//栈的判满
bool StackFull(SqStack s){
    return (s.top-s.base)==s.stacksize;
}
//求栈的长度
int StackLength(SqStack s){
    return s.top-s.base;
}

//清空顺序栈
Status ClearStack(SqStack S){
    if(S.base){
        S.top =S.base;
    }
    return OK;
}

//销毁一个顺序栈

Status DestroyStack(SqStack &s){
    if(s.base){
        delete s.base; //只是释放了base指针后的一段数组内存空间 指针的指向没有改变
        s.stacksize=0;
        s.base=s.top=NULL;
    }
    return OK;
}

/*
顺序栈的入栈 
1.判断栈是是否已经满
2.元素e压入栈顶
3.top指针上移*/
Status Push(SqStack &S,SElemType e){
    if (StackFull(S)) return ERROR;
    *S.top = e;
    S.top++; //top指针上移
    // *S.top++=e;
    return OK;
}

/*顺序栈的出栈
1.栈判空
2.top--
3.获取栈顶元素e 
*/
Status Pop(SqStack &S,SElemType &e){
    if(StackEmpty(S)) return ERROR;
    --S.top;
    e=*S.top;
    //e=*--S.top;
    return OK;
}

int main(){
    return 0;
}