#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct DLNode{
    ElemType data;
    DLNode *next;
    DLNode *prior;
}DLNode,*DLinkList;
//双链表初始化
bool InitDLinkList(DLinkList &DL){
    DL = new DLNode;
    if(DL == NULL){
        return false;
    }
    DL->next = NULL;
    DL->prior = NULL;
    return true;
}
//判断双链表是否为空
bool Empty(DLinkList DL){
    if(DL->next == NULL){
        return false;
    }else{
        return true;
    }
}
//在p节点之后插入节点s
bool InsertDLLinkList(DLinkList p,DLinkList s){
    if(p == NULL || s == NULL){
        return false;
    }
    s->next = p->next;
    if(p->next != NULL){
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return false;
}
//循环释放多个节点
bool DeleteDLinkList(DLinkList &DL){
    while(DL->next != NULL){
        
    }
}
int main(){
    DLinkList DL;
    
    return 0;
}