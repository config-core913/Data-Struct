#include<iostream>
using namespace std;

#define MaxSize 100
typedef int ElemType;
typedef struct{
    ElemType *base;
    int front;
    int rear;
}SqQueue;
//初始化
bool InitQueue(SqQueue &Q){
    Q.base = new ElemType[MaxSize];
    if(!Q.base){
        return false;
    }
    Q.front = Q.rear = 0;
    return true;
}
int main(){
    SqQueue Q;
    InitQueue(Q);
    
    return 0;
}