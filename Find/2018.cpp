#include <iostream>
using namespace std;
//2018年第一大题
//创建二叉排序树后计算叶子节点个数
typedef int ElemType;
typedef struct BiNode{
	ElemType data;
	BiNode *lchild,*rchild;
}BiNode,*BiTree;
//二叉排序树插入节点
void Insert(BiTree &T,ElemType element){
	if(!T){
		T = new BiNode;
		T->data = element;
		T->lchild = NULL;
		T->rchild = NULL;
	}else{
		if(T->data < element){
			Insert(T->rchild,element);
		}else if(T->data > element){
			Insert(T->lchild,element);
		}else{
			return;
		}
	}
}
//创建二叉排序树
void Create(BiTree &T){
	T = NULL;
	ElemType x;
	cin >> x;
	while(x != 9999){
		Insert(T,x);
		cin >> x;
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
//计算叶子结点数量
int LeafCount(BiTree T){
	if(T){
		
	}
}
int main(){
	BiTree T;
	cout << "请输入二叉排序树序列：";
	Create(T);
	InOrderTraverse(T);

	cout << "叶子节点数量：";
	int count = LeafCount(T);
	cout << count << endl;
	return 0;
}