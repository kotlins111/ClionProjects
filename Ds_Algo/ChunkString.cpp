#include<iostream>
using namespace std;

#define CHUNKSIZE 80  // 块的大小
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define NOTFOUND -3


typedef struct Chunk{
    char ch[CHUNKSIZE];
    Chunk *next;
}Chunk;

typedef struct ChunkString{
    Chunk *head;
    Chunk *tail;
    int curLocation;  //串的当前长度
}ChunkString;  //字符的块链结构

int main(){
    return 0;

}
