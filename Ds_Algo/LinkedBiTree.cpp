

/*
1.在n个结点的二叉链表中 有n+1个空指针域 线索二叉树

*/
#include <iostream>
using namespace std;
typedef char TElemType;

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



/*
二叉树的遍历
1.先序遍历(PreOrderTraverse)
先访问根结点，再访问左子树 最后访问右子树

2.中序遍历(InOrderTraverse)

左子树->根节点->右子树

3.后序遍历(PostOrderTraverse)
左子树->右子树->根节点
*/
int main(){
    return 0;
}
