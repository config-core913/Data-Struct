#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct DLNode{
    ElemType data;
    DLNode *next;
    DLNode *prior;
}DLNode,*DLinkList;
//初始化循环双链表
bool InitCircleDLinkList(DLinkList &DL){
    DL = new DLNode;
    if(DL == NULL){
        return false;
    }
    DL->next = DL;
    DL->prior = DL;
    return true;
}
//判断循环双链表是否为空
bool Empty(DLinkList DL){
    if(DL->next == DL){
        return true;
    }else{
        return false;
    }
}
//在p节点之后插入S节点
bool InsertDLInkList(DLinkList p,DLinkList s){
    s->next = p->next;
    p->next->prior = s;
    p->next = s;
    s->prior = p;
    return true;
}
//删除节点
bool Delete(DLinkList p,DLinkList q){
    p->next = q->next;
    q->next->prior = p;
    return true;
}
int main(){

    return 0;
}