#include<iostream>
using namespace std;
//2014年第一大题
//判断二叉树是否为平衡二叉树
typedef char ElemType;
typedef struct BiNode{
    BiNode *lchild,*rchild;
    ElemType data;
}BiNode,*BiTree;
//建立二叉树
void Create(BiTree &T){
    ElemType x;
    cin >> x;
    if(x == '#'){
        T = NULL;
    }else{
        T = new BiNode;
        T->data = x;
        Create(T->lchild);
        Create(T->rchild);
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
int height(BiTree T){
    if(!T){
        return 0;
    }else{
        return max(height(T->lchild),height(T->rchild)) + 1;// 树的高度 = 1 (根节点本身) + 左右子树中更高的那个的高度
    }
}
//判断是否为平衡二叉树
bool IsBalance(BiTree T){
    if(!T){
        return true;
    }else{
        
    }
}
int main(){
    BiTree T;
    cout << "请输入二叉树结点：";
    Create(T);
    cout << "中序遍历：";
    InOrderTraverse(T);
    //计算深度
    int h = height(T);
    cout << endl << "二叉树的深度为：" << h;


    return 0;
}