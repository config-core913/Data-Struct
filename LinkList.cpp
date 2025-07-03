#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode,*LinkList;
//初始化
bool Init_LinkList(LinkList &L){
    L = new LNode;
    L->next = NULL;
    return true;
}
//尾插法
void tail_insertLinkList(LinkList &L){
    L = new LNode;
    L->next = NULL;
    cout << "请输入：" << endl;
    ElemType x;
    LinkList s,q = L;
    cin >> x;
    while (x != 9999){
        s = new LNode;
        s->data = x;
        s->next = q->next;
        q->next = s;
        q = s;
        cin >> x;
    }
}
//打印链表
void PrintList(LinkList L){
    LinkList p = L->next;
    while (p != NULL)
    {
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl;
}
int main(){
    LinkList L;
    tail_insertLinkList(L);
    PrintList(L);
    return 0;
}