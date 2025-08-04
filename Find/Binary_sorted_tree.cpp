#include<iostream>
using namespace std;

//二叉排序树
typedef int KeyType;
typedef int InfoType;
typedef struct{
    KeyType key;    
    //InfoType otherinfo;
}ElemType;
typedef struct BSTNode{
    ElemType data;
    BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
//插入
void InsertBST(BSTree &T,ElemType e){
    if(!T){
        BSTree S = new BSTNode;
        S->data = e;
        S->lchild = S->rchild = NULL;
        T = S;
    }else if(e.key < T->data.key){
        InsertBST(T->lchild,e);
    }else if(e.key > T->data.key){
        InsertBST(T->rchild,e);
    }else{
        return;
    }
}
//创建二叉排序树
void CreateBST(BSTree &T){
    T = NULL;
    ElemType e;
    cin >> e.key;
    while(e.key != 9999){    //'$'为结束标志
        InsertBST(T,e);
        cin >> e.key;
    }
}
//中序遍历
void InOrderTraverse(BSTree T){
    BSTree p = T;
    if(T){
        InOrderTraverse(T->lchild);
        cout << T->data.key << " ";
        InOrderTraverse(T->rchild);
    }
}
int main(){
    BSTree T;
    cout << "请输入二叉排序树的信息：";
    CreateBST(T);
    InOrderTraverse(T);
    return 0;
}