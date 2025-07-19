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
    if(ch == '#'){  //'#'表示空结点
        T = NULL;   //当前指针置空
    }else{
        T = new BiNode;
        T->data = ch;
        CreateBiTree(T->lchild);//递归建立左子树
        CreateBiTree(T->rchild);//递归建立右子树
    }
}
//中序遍历
void InOrderTraverse(BiTree T){
    if(T){
        InOrderTraverse(T->lchild);//中序遍历左子树
        cout << T->data << " ";     //访问根节点
        InOrderTraverse(T->rchild); //中序遍历右子树
    }
}
int main(){
    BiTree T;
    CreateBiTree(T);
    InOrderTraverse(T);

    
    return 0;
}