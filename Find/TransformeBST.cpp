#include<iostream>
using namespace std;
//2013年真题
//二叉排序树，中序遍历、逆序
typedef int  ElemType;
typedef struct BiTNode{
    ElemType data;
    BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//插入结点
void InsertBST(BiTree &T,ElemType e){
    if(!T){
        BiTree s = new BiTNode;
        s->data = e;
        s->lchild = s->rchild = NULL;
        T = s;
    }else if(e > T->data){
        InsertBST(T->rchild,e);
    }else if(e < T->data){
        InsertBST(T->lchild,e);
    }else{
        return;
    }
}
//选序递归建立
void Create(BiTree &T){
    T = NULL;
    ElemType e;
    cin >> e;
    while(e != 9999){
        InsertBST(T,e);
        cin >> e;
    }
}
//中序遍历
void InOrderTraverse(BiTree T){
    if(!T){
        return;
    }
    InOrderTraverse(T->lchild);
    cout << T->data << " ";
    InOrderTraverse(T->rchild);
}
//二查排序树，中序遍历从小到大--->从大到小
void TransFormBST(BiTree &T){
    if(T == NULL){
        return;
    }

    TransFormBST(T->lchild);   // 递归处理左子树
    TransFormBST(T->rchild);  // 递归处理右子树
    
    // 处理当前节点：交换左右子树
    BiTree temp = T->lchild;
    T->lchild  = T->rchild;
    T->rchild = temp;
}
int main(){
    BiTree T;
    cout << "请输入二叉排序树元素：";
    Create(T);
    cout << "未修改：";
    InOrderTraverse(T);
    cout << endl;
    cout << "修改后：";
    TransFormBST(T);
    InOrderTraverse(T);
    return 0;
}