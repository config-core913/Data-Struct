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
//打印链表
void Print(LinkList L){
    LinkList p = L->next;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//链表逆置
void reverseLinkList(LinkList &L){
    if(L == NULL || L->next == NULL) return;  // 空链表或只有头节点
    
    LinkList pre, curr, next;
    pre = NULL;
    curr = L->next;     // 从第一个节点开始
    L->next = NULL;     // 头节点先指向NULL
    
    while(curr != NULL){
        next = curr->next;  // 保存下一个节点
        curr->next = pre;   // 逆转当前节点指针
        pre = curr;         // 移动pre指针
        curr = next;        // 移动curr指针
    }
    L->next = pre;
}
int main(){
    LinkList L;
    cout << "请输入链表的结点：";
    Insert_tail(L);
    Print(L);

    reverseLinkList(L);
    cout << "逆置后链表为：" << endl;
    Print(L);
    return 0;
}