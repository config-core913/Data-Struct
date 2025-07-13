#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode,*LinkList;
//尾插法
void Insert(LinkList &L){
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
void PrintList(LinkList L){
    LinkList p = L->next;
    while(p != NULL){
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl;
}
//合并链表
LinkList mergeLinkList(LinkList &L1,LinkList &L2){
    LinkList p,q,r,temp;
    p = L1->next;
    q = L2->next;
    r = L1;
    L2->next = NULL;
    while (p && q){
        if(p->data < q->data){
            r->next = p;
            r = p;
            p = p->next;
        }
        else if(p->data > q->data){
            r->next = q;
            r = q;
            q = q->next;
        }
        else{
            r->next = p;
            r = p;
            p = p->next;
            temp = q;
            q = q->next;
            delete temp;
        }
    }
    r->next = p ? p : q;
    delete L2;
    L2 = NULL;
    return L1;
}
int main(){
    LinkList L1;
    LinkList L2;
    cout << "请输入L1的值：" << endl;
    Insert(L1);
    cout << "请输入L2的值：" << endl;
    Insert(L2);
    PrintList(L1);
    PrintList(L2);
    LinkList L = mergeLinkList(L1,L2);
    PrintList(L);
    return 0;
}