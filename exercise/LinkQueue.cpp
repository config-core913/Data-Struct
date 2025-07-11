#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct QNode{
    ElemType data;
    QNode *next;
}QNode,*Queueptr;
typedef struct{
    Queueptr front;
    Queueptr rear;
}LinkQueue;
//链队列的初始化
bool InitLinkQueue(LinkQueue &Q){
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
    return true;
}
//链队列入队
bool EnQueue(LinkQueue &Q,ElemType element){
    QNode *p = new QNode;
    p->data = element;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return true;
}
int main(){
    LinkQueue Q;


    return 0;
}