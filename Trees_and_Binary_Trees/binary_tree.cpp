#include<iostream>
using namespace std;

//二叉树的顺序存储，将节点按完全二叉树标序
#define MAXSIZE 100 //二叉树的最大节点数
typedef int TElemType;
typedef TElemType SqBiTree[MAXSIZE];//0号单元存储根节点
SqBiTree bt;

//链式存储
typedef struct BiTNode{
    TElemType data;
    BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int main(){

    return 0;
}