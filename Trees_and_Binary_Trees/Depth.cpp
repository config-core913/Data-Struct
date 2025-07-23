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
//计算二叉树的深度
int Depth(BiTree T){
    if(T == NULL){
        return 0;
    }else{
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if(m > n){
            return m + 1;
        }else{
            return n + 1;
        }
    }
}
int main(){
    BiTree T;
    CreateBiTree(T);
    InOrderTraverse(T);

    int depth = Depth(T);
    cout << "二叉树的深度是：" << depth << endl;
    return 0;
}