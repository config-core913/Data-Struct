#include<iostream>
using namespace std;

//链表逆置练习
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
//打印输出
void PrintList(LinkList L){
    LinkList p = L->next;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//链表逆置
LinkList reverge(LinkList L){//头插法
    LinkList p,r;
    p = L->next;
    L->next = NULL;
    while(p){
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}
int main(){
    LinkList L;
    cout << "请输入链表元素：";
    Insert_tail(L);
    PrintList(L);
    reverge(L);
    cout << "链表逆置后：";
    PrintList(L);
    return 0;
}