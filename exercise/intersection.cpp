#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode,*LinkList;
//尾插法
void insert(LinkList &L){
    L = new LNode;
    L->next = NULL;
    LinkList p =L;
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
//求链表交集
void intersection(LinkList &A,LinkList B){
    if(A == NULL || B == NULL){
        return;
    }
    LinkList pA,pB,tail;//tail指针为合并链表的尾指针
    pA = A->next;
    pB = B->next;
    tail = A;//尾指针指向A，结束时若相等，则没有交集
    while(pA && pB){
        if(pA->data < pB->data){
            LinkList temp = pA;
            pA = pA->next;
            delete temp;
        }else if(pA->data > pB->data){
            pB = pB->next;
        }else{
            tail->next = pA;
            tail = pA;
            pA = pA->next;
            tail->next = NULL;
            pB = pB->next;
        }
    }
    while(pA){
        LinkList temp = pA;
        pA = pA->next;
        delete temp;
    }
    tail->next = NULL;//无论有没有交集，尾指针后面都是NULL
}
int main(){
    LinkList A;
    cout << "请输入表A的数据元素：" << endl;
    insert(A);
    Print(A);
    LinkList B;
    cout << "请输入表B的数据元素：" << endl;
    insert(B);
    Print(B);
    cout << "交集结果：" << endl;
    intersection(A,B);
    Print(A);
    return 0;
}