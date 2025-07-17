#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode,*LinkList;
//尾插法
void Insert_tail(LinkList &L){
    L = new LNode;
    L->next = NULL;
    LinkList p = L;
    ElemType x;
    cin >> x;
    while(x != 9999){
        LinkList s = new LNode;
        s->data = x;
        s->next = p->next;
        p->next = s;
        p = s;
        cin >> x;
    }
}
//打印链表
void Print(LinkList L){
    LinkList p = L->next;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//找到值最大的结点
LinkList findMaxNode(LinkList L){
    LinkList p = L->next;
    LinkList maxP = p;
    while(p){
        if(p->data > maxP->data){
            maxP = p;
        }
        p = p->next;
    }
    return maxP;
}
int main(){
    LinkList L;
    cout << "请输入链表的结点：";
    Insert_tail(L);
    Print(L);

    LinkList max = findMaxNode(L);
    cout << "链表中最大的结点的值是：" << max->data << endl;
    return 0;
}