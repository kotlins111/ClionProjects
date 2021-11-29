#include<iostream>
using namespace std;
#define MAXLEN 255

#define OK 1
#define ERROR -1
#define OVERFLOW -2

typedef struct {
    char ch[MAXLEN+1];
    int length;
}SString;

void prefixFunc(SString pattern,int prefix[]);
//字符串模式匹配 BF算法 主串text  子串pattern
//i 遍历text j 遍历pattern  主串回退位置 i-j+2 匹配成功返回子串位置 i-pattern.length
//匹配失败返回-1
int Index_BF(SString text,SString pattern,int pos){
    int i=pos,j=1;
    while(j<=pattern.length&&i<=text.length){
        if(text.ch[i]==pattern.ch[j]){
            i++;
            j++;
        }
        else{
            i=i-j+2;
            j=1;
        }

    }
    if(j>pattern.length) return i-pattern.length;
    else return -1;
}


//模式匹配KMP算法 
/*
prefixFunc函数求pattern在text中第pos个字符后的位置
*/
int Index_KMP(SString text,SString pattern,int pos){

    int j=1;int i=pos;int next[pattern.length];
    while(i<=text.length&&j<=pattern.length){
        if(j==0||text.ch[i]==pattern.ch[j]){
            i++;j++;
        }else{
            prefixFunc(pattern,next);
            j=next[j];
        }
    }
    if(j>pattern.length){
        return i-pattern.length;
    }
    return -1;

}
// KMP 前缀函数
void prefixFunc(SString pattern,int prefix[]){
    int i=1;
    prefix[1]=0;
    int j=0;
    while(i<pattern.length){
        if(j==0||pattern.ch[i]==pattern.ch[j]){
            i++;j++;
            prefix[i]=j;
        }
        else{
            j=prefix[j];
        }
    }
}
int main(){
    return 0;  
}