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
    cout <<  "请输入元素：" << endl;
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
//合并链表,不能有重复元素
LinkList mergeLinkList(LinkList &L1,LinkList &L2){
    LinkList p,q,r;
    p = L1->next;
    q = L2->next;
    r = L1;     //合并到L1，释放L2
    LinkList temp;  //释放重复节点
    while(p && q){
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
        else{//q->data == p->data
            r->next = p;
            r = p;
            p = p->next;
            //删除重复节点
            temp = q;
            q = q->next;
            delete temp;
        }
    }
    r->next = p ? p : q;
    //释放L2的头节点
    delete L2;
    L2 = NULL;//防止选空指针
    return L1;
}
int main(){
    LinkList L1;
    LinkList L2;

    insert_tail(L1);
    insert_tail(L2);
    cout << "链表1：";
    PrintList(L1);
    cout << "链表2：";
    PrintList(L2);

    LinkList L = mergeLinkList(L1,L2);
    PrintList(L);
    return 0;
}