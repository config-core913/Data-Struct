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
        cin >>x;
    }
}
//打印链表
void PrintList(LinkList L){
    LinkList p = L->next;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//删除结点
void DeleteRange(LinkList &L,ElemType mink,ElemType maxk){
    if(L == NULL || L->next == NULL){
        return;
    }
    LinkList p,q;
    p = L;
    //查找第一个值大于mink的节点
    while(p->next != NULL && p->next->data <= mink){
        p = p->next;
    }
    //删除值在(mink, maxk)范围内的节点
    while(p->next != NULL && p->next->data < maxk){
        q = p->next;
        p->next = q->next;
        delete q;
    }
}
int main(){
    LinkList L;
    cout << "请输入链表的元素：";
    Insert_tail(L);
    PrintList(L);

    DeleteRange(L,5,9);
    PrintList(L);
    return 0;
}