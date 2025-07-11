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
//求队列长度
int QueueLength(SqQueue Q){
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}
//入队
bool EnQueue(SqQueue &Q,ElemType element){
    if((Q.rear + 1) % MaxSize == Q.front){
        return false;
    }
    Q.base[Q.rear] = element;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}
//出队
bool DeQueue(SqQueue &Q,ElemType &e){
    if(Q.front == Q.rear){
        return false;
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
//获取队头元素
ElemType GetHead(SqQueue Q){
    if(Q.front != Q.rear){
        return Q.base[Q.front];
    }
}
int main(){
    SqQueue Q;
    InitQueue(Q);

    EnQueue(Q,10);
    EnQueue(Q,2);
    EnQueue(Q,3);
    EnQueue(Q,4);
    EnQueue(Q,5);
    EnQueue(Q,6);
    
    ElemType test = GetHead(Q);
    cout << test << endl;
    return 0;
}