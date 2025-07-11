#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode,*LinkList;
//初始化循环链表
bool InitList(LinkList &L){
    L = new LNode;
    if (L == NULL)
    {
        return false;
    }
    L->next = L;
    return true;
}
//判断循环单链表是否为空
bool Empty(LinkList L){
    if(L->next == L){
        return true;
    }else{
        return false;
    }
}
//判断节点p是否为循环单链表的标为节点
bool isTail(LinkList L,LinkList p){
    if(p->next == L){
        return true;
    }else{
        return;
    }
}
int main(){

    return 0;
}