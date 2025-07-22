#include<iostream>
using namespace std;

#define MaxSize 100
//二叉树结构
typedef char ElemType;
typedef struct BiNode{
    ElemType data;
    BiNode *lchild,*rchild;
}BiNode,*BiTree;
//顺序栈结构
typedef struct{
    BiTree *data;
    int top;
}SqStack;
//先序建立二叉树
void CreateBiTree(BiTree &T){
    ElemType ch;
    cin >> ch;
    if(ch == '#'){  //'#'表示空结点
        T = NULL;   //当前指针置空
    }else{
        T = new BiNode;
        T->data = ch;
        CreateBiTree(T->lchild);//递归建立左子树
        CreateBiTree(T->rchild);//递归建立右子树
    }
}
//中序遍历的递归算法
void InOrderTraverse(BiTree T){
    if(T){
        InOrderTraverse(T->lchild);//中序遍历左子树
        cout << T->data << " ";     //访问根节点
        InOrderTraverse(T->rchild); //中序遍历右子树
    }
}
//初始化栈
void InitStack(SqStack &S){
    S.data = new BiTree[MaxSize];
    S.top = -1;
}
//入栈
bool Push(SqStack &S,BiTree T){
    if(S.top == MaxSize-1){
        return false;
    }else{
        S.top++;
        S.data[S.top] = T;
        return true;
    }
}
//出栈
bool Pop(SqStack &S,BiTree &T){
    if(S.top == -1){
        return false;
    }else{
        T = S.data[S.top];
        S.top--;
        return true;
    }
}
//中序遍历--非递归
void InOrderTraverse_F(BiTree T){
    SqStack S;
    InitStack(S);
    BiTree p = T;
    while(S.top != -1 || p != NULL){
        while(p){
            Push(S,p);
            p = p->lchild;
        }
        if(S.top != -1){
            Pop(S,p);
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}
int main(){
    BiTree T;
    cout << "数据元素：";
    CreateBiTree(T);
    cout << "递归遍历：";
    InOrderTraverse(T);
    cout << endl;
    cout << "非递归遍历：";
    InOrderTraverse_F(T);
    
    return 0;
}