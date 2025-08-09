#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode,*LinkList;
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
void PrintList(LinkList L){
    LinkList p = L->next;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void reverse1(LinkList &L){
    LinkList curr,next,pre;
    curr = L->next;
    pre = NULL;
    L->next = NULL;
    while(curr){
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    L->next = pre;
}
void reverse2(LinkList &L){
    LinkList curr,next;
    curr = L->next;
    L->next = NULL;
    while(curr){
        next = curr->next;
        curr->next = L->next;
        L->next = curr;
        curr = next;
    }
}
int main(){
    LinkList L;
    Insert_tail(L);
    PrintList(L);

    reverse2(L);
    PrintList(L);
    return 0;
}