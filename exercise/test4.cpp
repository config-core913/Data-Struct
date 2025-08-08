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
        cin >> x;
    }
}
//打印输出
void PrintList(LinkList L){
    LinkList p = L->next;
    while(p){
        cout << p->data  << " ";
        p = p->next;
    }
    cout << endl;
}
//链表逆置
void reverse1(LinkList &L){
    // LinkList pre, curr, next;
    // pre = NULL;
    // curr = L->next;     // 从第一个节点开始
    // L->next = NULL; 
    // while(curr != NULL){
    //     next = curr->next;
    //     curr->next = pre;
    //     pre = curr;
    //     curr = next;
    // }
    // L->next = pre;
    LinkList curr,pre,next;
    pre = NULL;
    curr = L->next;
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
    // LinkList curr,next;
    // curr = L->next;
    // L->next = NULL;
    // while(curr){    //注意L指针的变化，L.next指向的节点一直在变，但是始终指向修改后的第一个结点
    //     next = curr->next;
    //     curr->next = L->next;
    //     L->next = curr;
    //     curr = next;
    // }
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
    cout << "请输入链表元素：";
    Insert_tail(L);
    PrintList(L);

    reverse2(L);
    cout << "链表逆置后：";
    PrintList(L);
    return 0;
}