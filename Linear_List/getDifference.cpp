#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode,*LinkList;
//尾插法
void insert_tail(LinkList &L){
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
//求两条链表的差集
LinkList getDifference(LinkList A,LinkList B){
    LinkList C = new LNode;
    C->next = NULL;
    LinkList r = C;
    LinkList p = A->next;
    LinkList q = B->next;
    while(p && q){
        if(p->data < q->data){
            LinkList s = new LNode;
            s->next = r->next;
            r->next = s;
            s->data = p->data;
            r = s;
            p = p->next;
        }else if(p->data > q->data){
            q = q->next;
        }else{
            p = p->next;
            q = q->next;
        }
    }
    while(p){//将A链表剩余的节点直接链接到C，在删除A链表时会出错
        LinkList s = new LNode;
        s->data = p->data;
        s->next = r->next;
        r->next = s;
        r = s;
        p = p->next;
    }
    return C;
}
//释放A，B两条链表的节点
void freeList(LinkList &L){
    LinkList p = L;
    while(p){
        LinkList temp = p;
        p = p->next;
        delete temp;
    }
    L = NULL;
}
int main(){
    LinkList A;
    cout << "请输入链表A：" << endl;
    insert_tail(A);
    Print(A);
    LinkList B;
    cout << "请输入链表B：" << endl;
    insert_tail(B);
    Print(B);
    LinkList C = getDifference(A,B);
    cout << "两条链表的差集是：" << endl;
    Print(C);
    freeList(A);
    freeList(B);
    return 0;
}