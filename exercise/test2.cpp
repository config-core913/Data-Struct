//复习第一章 线性表 课后算法题 2025/7/26，星期六
#include<iostream>
using namespace std;

typedef int ElemType;
//链表结构
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
void PrintLinkList(LinkList L){
    LinkList p = L->next;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//（1）合并递增链表
void merge(LinkList &A,LinkList &B){
    LinkList p,q;
    p = A->next;
    q = B->next;
    B->next = NULL;
    LinkList temp = p;
    while(p && q){
        if(p->data < q->data){
            temp = p;
            p = p->next;
            temp->next = q;
            temp = q;
        }else{
            q = q->next;
            temp->next = p;
            temp = p;
        }
    }
    temp->next = p ? p : q;
}
int main(){
    LinkList A,B;
    cout << "请输入表A的元素：";
    Insert_tail(A);
    PrintLinkList(A);
    cout << "请输入表B的元素：";
    Insert_tail(B);
    PrintLinkList(B);
    cout << "合并后两条链表：";
    merge(A,B);
    PrintLinkList(A);
    return 0;

}