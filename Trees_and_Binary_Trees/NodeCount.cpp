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
//统计节点数量
int NodeCount(BiTree T){
    if(T == NULL){
        return 0;
    }else{
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
    }
}
int main(){
    BiTree T;
    CreateBiTree(T);
    InOrderTraverse(T);

    int count = NodeCount(T);
    cout << "二叉树节点数量是：" << count << endl;
    return 0;
}