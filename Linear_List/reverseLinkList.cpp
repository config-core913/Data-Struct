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
//链表逆置
void reverseLinkList(LinkList &L){
    LinkList p,q,r;
    p = L;
    q = p->next;
    r = q->next;
    
}
int main(){
    LinkList L;
    cout << "请输入链表的结点：";
    Insert_tail(L);
    Print(L);

    
    return 0;
}