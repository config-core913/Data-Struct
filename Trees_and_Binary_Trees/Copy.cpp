#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct BiNode{
    ElemType data;
    BiNode *lchild,*rchild;
}BiNode,*BiTree;

//先序建立二叉树
void CreateBiTree(BiTree &T){
    ElemType ch;
    cin >> ch;
    if(ch == '#'){
        T = NULL;
    }else{
        T = new BiNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
//中序遍历
void InOrderTraverse(BiTree T){
    if(T){
        InOrderTraverse(T->lchild);
        cout << T->data << " ";
        InOrderTraverse(T->rchild);
    }
}
//复制二叉树
void Copy(BiTree T,BiTree &NewT){
    if(T == NULL){
        NewT = NULL;
        return;
    }else{
        NewT = new BiNode;
        NewT->data = T->data;
        Copy(T->lchild,NewT->lchild);
        Copy(T->rchild,NewT->rchild);
    }
}
int main(){
    BiTree T;
    CreateBiTree(T);
    cout << "原二叉树：";
    InOrderTraverse(T);

    BiTree NewTree;
    Copy(T,NewTree);

    cout << "新的二叉树：";
    InOrderTraverse(NewTree);
    return 0;
}