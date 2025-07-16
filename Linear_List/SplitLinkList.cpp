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
//拆分链表
void SplitLinkList(LinkList &A,LinkList &B,LinkList &C){
    LinkList pA = A->next;
    A->next = NULL;
    LinkList pB = B;
    LinkList pC = C;
    // while(pA){
    //     if(pA->data < 0){
    //         LinkList temp = pA;
    //         pA = pA->next;
    //         temp->next = pB->next;
    //         pB->next = temp;
    //         pB = temp;
    //     }else{
    //         LinkList temp = pA;
    //         pA = pA->next;
    //         temp->next = pC->next;
    //         pC->next = temp;
    //         pC = temp; 
    //     }
    // }
    while(pA){
    LinkList temp = pA;
    pA = pA->next;  // 先保存下一个节点
    
    if(temp->data < 0){
        temp->next = pB->next;  // 断开后重新连接
        pB->next = temp;
        pB = temp;
    } else if(temp->data > 0) {
        temp->next = pC->next;  // 断开后重新连接
        pC->next = temp;
        pC = temp;
    }
}
}
int main(){
    LinkList A;
    cout << "请输入A表的元素：" << endl;
    Insert_tail(A);
    Print(A);

    LinkList B = new LNode;
    B->next = NULL;
    LinkList C = new LNode;
    C->next = NULL;

    SplitLinkList(A,B,C);
    cout << "链表B: ";
    Print(B);
    cout << "链表C: ";
    Print(C);
    
    return 0;

}