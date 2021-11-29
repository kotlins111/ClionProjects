/*
每一层最多有2^(i-1)个结点 深度为k的树最多包含2^k-1个结点
*/
/*
typedef int arrs[5];
typedef arrs * p_arr5;
typedef p_arr5 arrp10[10];
arrs togs;       // togs是具有5个元素的int数组
p_arr5 p2;      // p2是一个指针，指向具有元素的数组
arrp10  ap;    // ap是具有十个元素的指针数组，每个指针指向具有5个元素的int数组
*/
//二叉树顺序存储
#define MAXSIZE 100
#include <iostream>
using namespace std;
typedef char TElemType;

typedef TElemType SqBiTree[MAXSIZE]; //


int main(){
    SqBiTree bt;  //bt是具有100个元素的TElemType 数组
  
    return 0;
}