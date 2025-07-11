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
//链队列出队
bool DeQueue(LinkQueue &Q,ElemType &element){
    if(Q.front == Q.rear){
        return false;
    }
    QNode *p = Q.front->next;
    element = p->data;
    Q.front->next = p->next;
    if(Q.rear == p){
        Q.rear = Q.front;
    }
    delete p;
    return true;
}
//取队头元素
ElemType GetHead(LinkQueue Q){
    if(Q.front != Q.rear){
        return Q.front->next->data;
    }
    return 0;
}

int main(){
    LinkQueue Q;
    InitLinkQueue(Q);

    EnQueue(Q,10);
    EnQueue(Q,2);
    EnQueue(Q,3);
    EnQueue(Q,4);
    EnQueue(Q,5);

    int test = GetHead(Q);
    cout << test << endl;
    return 0;
}