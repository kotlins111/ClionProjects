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

//数据域与指针域分开定义
typedef struct ElemType{
    char num[8];
    char name[8];
    int score; 
    bool operator == (const ElemType &e1); 
    bool operator != (const ElemType &e1);
}ElemType;

bool ElemType::operator==(const ElemType &e1){
    return ((num==e1.num)&&(name==e1.name)&&(score==e1.score));
}
bool ElemType::operator!=(const ElemType &e1) {
    return (num!=e1.num);
}
typedef int Status;

//指向某个结点 LNode *P;指向整个链表 LinkedList L;
typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode,*LinkedList;

//双向链表结构体定义 
typedef struct DuLNode 
{
    /* data */
    ElemType data;
    /*ptr*/
    DuLNode *prior;
    DuLNode *next;

}DuLNode,*DuLinkedList;


/*初始化一个链表
1.生成新结点作为头结点，用头指针指向头结点
2.头结点的指针域置空
*/
Status InitList(LinkedList &L){
    L=new LNode;
    // L=(LinkedList)malloc(sizeof(LNode));
    L->next=NULL;  //L指向头结点 L->next 就是头结点的指针域
    return OK;
}

/*判断一个链表是否为空
头结点指针域为空就是空表*/
bool IsEmpty(LinkedList L){
    return L->next==NULL;
}

//销毁链表 从头指针开始 依次释放链表的全部结点地址
Status Destroy(LinkedList &L){
    LNode *p;
    // for (size_t i = 0; i < count; i++)
    // {
    //     p=L;
    //     L=L->next;
    //     delete p;
    //     if(!L) break;
    // }
    while (L)
    {

        /* code */
        p=L;
        L=L->next;
        delete p;
    }   
   return OK;   
}

//清空链表 依次释放所有结点 将头结点指针域置空
Status ClearList(LinkedList &L){
    LNode *p,*q;
    p = L->next;
    while (p)
    {
        /* code */
        q = p->next;
        delete p;
        p=q;
    }
    L->next =NULL;
    return OK;

}

//求链表的表长 从首元结点开始 依次计数所有结点
Status Count(LinkedList L,int &count){
    LNode *p;
    p=L->next; //p指向首元结点
    if (!p) count =0;
    count =0;
    while(p){
        p=p->next;
        count++;
        
    }
    return OK;
}

//查找链表的第i个元素 L.elem[i-1]
Status GetElem(LinkedList L,int index,ElemType &e){
    LNode *p;
    p=L->next;
    int j=1;
    while(p&&j<index){
        p=p->next;
        j++;
    }
    if(!p||j>index) return ERROR;
    e=p->data;
    return OK;
}

//给定一个元素 查找该元素在链表中的位置 应该返回该元素的指针而不是该元素在链表中的位置 因为链表无法随机存取 指针要比index更加高效
Status GetIndex(LinkedList L,ElemType e,int &index){
    LNode *p=L->next;
    
    int j=1;
    while(p&&(e!=p->data)){
        p=p->next;
        j++;
    }
    index = j;
    return OK;
}
/*链表插入 
1.查找插入位置的前一个结点 用一个新的指针p指向它 
2.新建一个结点 数据域置为e 先建立与后继结点的链接 s->next=p->next 
再建立前趋结点的链接 p->next=s; p的后继结点为s；*/
Status Insert(LinkedList &L,ElemType e,int index){
    LNode *p=L;
    int j=0;
    //使得指针p指向结点i-1
    while(p&&(j<index-1)){
        ++j;
        p=p->next;

    }
    LNode *s =new LNode;
    s->data = e;
    s->next=p->next;
    p->next=s;
    return OK;
   
}

/*单链表的创建 遍历存储数据元素 前插法
1.创建一个只有头结点的空链表
2.对需要插入的元素 作循环操作
生成一个新结点p 元素赋值给结点的数据域 将结点插入到头结点之后 
*/

void CreateList_H(LinkedList &L,ElemType e[]){
    L = new LNode;
    L->next=NULL;
    for(int i=10;i>=0;i--){
        LNode *p=new LNode;
        p->data=e[i]; //倒序插入 
        p->next=L->next;L->next=p; //插入操作 新插入的结点为首元结点 L->next=p;
    }
    
}
/*
尾插法
*/
void CreateList_T(LinkedList &L,ElemType e[]){
    L=new LNode;
    // L=LinkedList(malloc(sizeof(LNode)));
    L->next=NULL;

    LNode *r;
    r=L;
    for(int i=0;i<10;i++){
        LNode *p=new LNode;
        p->data=e[i];
        p->next=NULL; //p是当前插入的尾结点 指针域需要置为NULL
        r->next=p;
        r=p;
    }
}

//单链表的删除 p->next=p->next->next; 跳跃一个结点 非法参数index 返回ERROR
Status Delete(LinkedList &L,int index,ElemType &e){
    LNode *p=L;
    int j=0;
    while(p&&j<index-1){
        ++j;
        p=p->next;
    }
    LNode *q=p->next;
    e=q->data;
    p->next=p->next->next;
    delete q;
    return OK;
}

//查找链表的第i个结点 并返回指向该结点的指针
LNode *GetElemPointer(LinkedList L,int i){
    int j =0; 
    LNode *p = L;

    while (p&&(j<i))
    {
        /* code */
        p=p->next;
        j++;
    }
    if (!p||j>i)
    {
        return NULL;
    }
    return p;
    
}
//带尾指针的循环链表的合并 L1 L2 是链表的尾结点  O(1)
LinkedList Connect(LinkedList L1,LinkedList L2){
    //用临时指针p保存L1头结点地址
    LNode *p =L1->next;
    L1->next=L2->next->next;
    delete L2->next;
    L2->next=p;
    return L2;

}

/*
双向链表插入操作 在第i个位置前插入
p->next->prior=p->prior->next=p;
*/ 
void ListInsert_DuL(DuLinkedList &L,int i,ElemType e){

    DuLNode *p=L;
    int j=0;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    if(!p||j>i) exit(INFEASIBLE);
    DuLNode *q=p->prior;
    DuLNode *s = new DuLNode;
    s->data=e;
    s->prior=q;
    q->next=s;
    s->next=p;
    p->prior=s;
    
}

//获取双向链表第i个元素的指针
DuLinkedList GetElemP_DuL(DuLinkedList L,int i){
    DuLNode *p=L;
    int j=0;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    if(!p||j>i) exit(INFEASIBLE);
    return p;
}
//双向链表删除 删除带头结点的双向循环链表L的第i个元素 并用e返回
Status ListDelete_DuL(DuLinkedList &L,int i,ElemType &e){
    DuLNode *p;

    p=GetElemP_DuL(L,i);
    if (!p)
    {
        /* code */
        return ERROR;
    }
    e=p->data;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    delete p;
    return OK;
}
int main(){

    LinkedList L;
    // LNode *p;
    return 0;
}