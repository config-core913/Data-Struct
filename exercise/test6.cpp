#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct BiTNode{
    ElemType data;
    BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//插入
void Insert(BiTree &T,ElemType e){
    if(!T){
        BiTree s = new BiTNode;
        s->data = e;
        s->lchild = s->rchild = NULL;
        T = s;
    }else if(T->data > e){
        Insert(T->lchild,e);
    }else if(T->data < e){
        Insert(T->rchild,e);
    }else{
        return;
    }
}
void Create(BiTree &T){
    T = NULL;
    ElemType x;
    cin >> x;
    while(x != 9999){
        Insert(T,x);
        cin >> x;
    }
}
void Print(BiTree T){
    if(!T) return;
    BiTree p = T;
    Print(p->lchild);
    cout << p->data << " ";
    Print(p->rchild);
}
//修改二叉排序树
void reverse(BiTree &T){
    // if(!T){
    //     return;
    // }else{
    //     BiTree temp = T->lchild;
    //     T->lchild = T->rchild;
    //     T->rchild = temp;
    // }
    // reverse(T->lchild);
    // reverse(T->rchild);

    if(!T) return;
    reverse(T->lchild);
    reverse(T->rchild);
    BiTree temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
}
int main(){
    BiTree T;
    cout << "请输入二叉排序树：";
    Create(T);
    Print(T);
    cout << endl;
    cout << "修改后：";
    reverse(T);
    Print(T);
    return 0;
}