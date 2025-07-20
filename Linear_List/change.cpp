#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct DLNode{
    ElemType data;
    DLNode *prior,*next;
}DLNode,*DLinkList;
//初始化循环双链表
void InitDList(DLinkList &DL){
    DL = new DLNode;
    DL->data = -1;
    DL->next = DL;
    DL->prior = DL;
}
//双循环链表尾插法
void Insert_tail(DLinkList &DL){
    ElemType x;
    cin >> x;
    DLinkList p = DL;
    while(x != 9999){
        DLinkList s = new DLNode;
        s->data = x;
        s->next = p->next;
        s->prior = p;
        p->next->prior = s;
        p->next = s;
        p = s;
        cin >> x;
    }
}

//打印链表
void Print(DLinkList DL){
    DLinkList p = DL->next;
    while(p->data != -1){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//交换特定节点及其前驱
void change(DLinkList &DL,DLinkList p){
    if(p == NULL || DL->next == DL || p == DL->next){
        return;
    }
    ElemType temp = p->data;
    p->data = p->prior->data;
    p->prior->data = temp;
}
//返回指定结点的地址
DLinkList find_node(DLinkList DL,ElemType element){
    DLinkList p = DL->next;
    while(p != DL){   
        if(p->data == element){
            return p;
        }
        p = p->next;
    }
    return NULL;
}
int main(){
    DLinkList DL;
    InitDList(DL);
    cout << "请输入结点：";
    Insert_tail(DL);
    Print(DL);

    //找到指定节点
    DLinkList find = find_node(DL,5);
    change(DL,find);
    Print(DL);


    return 0;
}