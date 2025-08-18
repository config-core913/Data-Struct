#include<iostream>
using namespace std;


struct Node{
    char data;
    Node *next;
};
//尾插法
void Insert_tail(struct Node * &L){
    L = new Node;
    L->next = NULL;
    struct  Node * p = L;
    char x;
    cin >> x;
    while(x != '#'){
        struct Node *s;
        s = new Node;
        s->data = x;
        s->next = p->next;
        p->next = s;
        p = s;
        cin >> x;
    }
}
//打印输出
void PrintList(struct Node *L){
    Node * p = L->next;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//逆置
void reverse(Node * L){
    Node *pre,*curr,*next;
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
int main(){
    Node *L;
    cout << "请输入元素：";
    Insert_tail(L);
    cout << "排序前：";
    PrintList(L);
    cout  << "排序后：";
    reverse(L);
    PrintList(L);
    return 0;
}