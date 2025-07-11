#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct StackNode{
    ElemType data;
    StackNode *next;    //链表头部作为栈顶
}StackNode,*LinkStack;
//初始化琏栈
bool InitStack(LinkStack &S){
    S = NULL;
    return true;
}
//入栈
bool Push(LinkStack &S,ElemType element){
    LinkStack p = new StackNode;
    p->data = element;
    p->next = S;
    S = p;
    return true;
}
//出栈
bool Pop(LinkStack &S,ElemType &element){
    if(S==NULL){
        return false;
    }
    element = S->data;
    LinkStack p = S;    //用p临时保存栈顶元素的空间，以备释放
    S = S->next;
    delete p;
    return true;
}
//取栈顶元素
ElemType GetTop(LinkStack S){
    if(!S == NULL){
        return S->data;
    }
}
int main(){
    LinkStack S;
    InitStack(S);
    Push(S,15);
    ElemType test = GetTop(S);
    cout << test << endl;
    return 0;
}