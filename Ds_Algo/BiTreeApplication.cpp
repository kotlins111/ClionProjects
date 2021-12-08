

/*
1.在n个结点的二叉链表中 有n+1个空指针域 线索二叉树

*/
#include <iostream>
using namespace std;
typedef char TElemType;

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define NOTFOUND -3


//三叉链表 二叉链表新增一个prior指针 用来寻找父结点地址
typedef struct TriNode{
    TElemType data;
    TriNode *lchild,*rchild,*parent;
}TriNode,*TriTree;

//二叉树的链式存储 
typedef struct BiNode{
    TElemType data;
    BiNode *lchild,*rchild;
}BiNode,*BiTree;

typedef int Status;


typedef BiNode SElemType;


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

/*
二叉树的遍历
1.先序遍历(PreOrderTraverse)
先访问根结点，再访问左子树 最后访问右子树

2.中序遍历(InOrderTraverse)

左子树->根节点->右子树

3.后序遍历(PostOrderTraverse)
左子树->右子树->根节点
*/
void opeartion(BiNode *T);
Status PreOrderTraverse(BiTree T){
    if(T==NULL) return OK;
    else{
        opeartion(T); 
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    return OK;
}

Status InOrderTraverse(BiTree T){
    if(T==NULL) return OK;
    else{
        InOrderTraverse(T->lchild);
        opeartion(T);
        InOrderTraverse(T->rchild);
    }
    return OK;
}


Status PostOrderTraverse(BiTree T){
    if(T==NULL) return OK;
    else{
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        opeartion(T); 
    }
    return OK;
}

void opeartion(BiNode *T){
    printf("%d\t",T->data);
}


//非递归遍历二叉树  使用辅助栈

Status InOrderTraverse_(BiTree T){
    BiTree p,q;
    SqStack S;
    InitStack(S);
    p=T;
    while (p||!StackEmpty(S))
    {
        /* code */
        if(p){
            Push(S,p); p=p->lchild;
        }else{
            Pop(S,q); opeartion(q);
            p=q->rchild;
        }
    }
    return OK;
}

//先序遍历方式创建 二叉链表 recursion
Status CreateBiTree(BiTree T){
    char ch;
    cin>>ch;
    if (ch=="#") T=NULL; return OK;
    else{
        BiNode* T = new BiNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
        return OK;
    }
    
/*
复制二叉树
利用已有的一颗二叉树复制得到一颗与其完全相同的二叉树
1.若二叉树不为空 首先复制根节点 
2.分别复制根节点的左子树和右子树

*/
Status Copy(BiTree Source,BiTree &Targer){
    //复制一颗和Source完全相同的二叉树
    if(Source==NULL){
        Target=NULL;
        return OK;
    }
    else{
        Target=new BiNode; //新建一个二叉结点 分配内存
        Targer->data=Source->data; //复制根节点
        Copy(Source->lchild,Target->lchild); //递归复制左子树
        Copy(Source->rchild,Target->rchilid); //递归复制右子树

        return OK;
    }
}

/*
计算二叉树的深度
1.如果是空树 递归结束 返回0
2.递归计算左子树的深度m
3.递归计算右子树的深度n
4.如果m>n 二叉树的深度为m+1 否则为n+1
计算二叉树深度是在后序遍历的基础上完成的*/

Status Depth(BiTree T,int &depth){
    if(T==NULL) depth=0; return OK;
    else{
        m=Depth(T->lchild);
        n=Depth(T->rchild);
        depth=(m>n)?m++:n++;
        return OK;
    }

}

// 计算二叉树结点个数 递归遍历左子树和右子树 返回二者结点数量之和再加根节结点

Status NodeCount(BiTree T,int &count){
    if(T==NULL) count=0;return OK;
    int lcount,rcount;
    else{
        NodeCount(T->lchild,lcount);
        NodeCount(T->rchild,rcount);
        count=lcount+rcount+1;
        return OK;
    }
}

int main(){
    return 0;
}
