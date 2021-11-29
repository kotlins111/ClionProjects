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

typedef char ElemType;
typedef int Status;

typedef struct {
    ElemType* elem;
    int length;
}SqList;




//线性表的初始化
Status InitList_Sq(SqList &L){
    L.elem = new ElemType[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return OK;
}

//销毁线性表
void destroy(SqList &L){
    if(!L.elem){
        delete L.elem;
    }
}
//清空线性表
void ClearList(SqList &L){
    L.length = 0;
}
//获取线性表的长度
int GetLength(SqList L){
    return L.length;
}

//判断表是否为空
bool IsEmpty(SqList L){
    return L.length==0;
}

//线性表取值 随机存取 复杂度O（1）
int GetElem(SqList L,int i,ElemType &e){
    if(i<1 ||i>L.length){
        return ERROR;
    }
    e = L.elem[i-1];
    return OK;
}

//查找表中元素 顺序遍历
int GetIndex(SqList L,ElemType e,int &index){
    for (int i = 0; i < L.length; i++)
    {
        /* code */
        if (L.elem[i]==e)
        {
            index = i+1;
            return OK;
        }
        
    }
    return NOTFOUND;
    
}
//线性表插入 插入到第i个位置 1<=i<=n+1  
//length-1 -> index-1

Status Insert(SqList &L,int index,ElemType e){
    if(L.length==MAXSIZE) return ERROR;
    if (i<1||i>L.length+1)
    {
        /* code */
        return ERROR;
    }
    for (int i = L.length-1; i >=index-1; i--)
    {
        /* code */
        L.elem[i+1]=L.elem[i];
    }
    
    L.elem[i-1] = e;
    L.length++;
    return OK;
}

//线性表删除 返回更新后的表和被删除的数据元素
Status Delete(SqList &L,int index,ElemType &e){
    // if(!L.elem||L.length==0) return ERROR;
    if(i<1||i>L.length) return ERROR;
    e=L.elem[index-1];
    for(int i=index,i<=L.length-1,i++){
        L.elem[i-1]=L.elem[i]
    }
    L.length--;
    return OK;
}

int main(){
     SqList L;

    // L.elem =(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    // free(L.elem);
    int a = InitList_Sq(L);
    cout<<a<<endl;
    cout<<"分配空间后的线性表地址："<<&L.elem<<endl;
    return 0;
}