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
int main(){
    DLinkList DL;

    return 0;
}