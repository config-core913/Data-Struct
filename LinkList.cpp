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
//头插法
void head_insertLinkList(LinkList &L){
    L = new LNode;
    L->next = NULL;
    ElemType x;
    cout << "请输入: " << endl;
    cin >> x;
    while(x != 9999){
        LinkList s = new LNode;
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }

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
//插入节点
bool insertList(LinkList &L,int i,ElemType element){
    if(i < 1){
        return false;
    }
    LinkList p = L;
    int j = 0;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL){
        return false;
    }
    LinkList s = new LNode;
    s->data = element;
    s->next = p->next;
    p->next = s;
    return true;
}
//删除指定节点
bool DeleteLinkList(LinkList &L,int i,ElemType &element){
    if(i < 1){
        return false;
    }
    int j = 0;
    LinkList p = L;
    while( p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL && p->next == NULL){
        return false;
    }
    LinkList q = p->next;
    element = q->data;
    p->next = q->next;
    delete q;
    return true;
}
int main(){
    LinkList L;
    // tail_insertLinkList(L);
    head_insertLinkList(L);
    

    PrintList(L);
    return 0;
}