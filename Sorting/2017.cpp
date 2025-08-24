#include<iostream>
using namespace std;
//2017年第二大题
//判断二叉树是不是平衡二叉树
typedef char ElemType;
typedef struct BiNode{
	ElemType data;
	BiNode *lchild,*rchild;
}BiNode,*BiTree;
//先序建立二叉树
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
//计算二叉树的高度
int hight(BiTree T){
	if(!T){
		return 0;
	}else{
		return max(hight(T->lchild),hight(T->rchild)) + 1;
	}
}
//判断是否是平衡二叉树
bool IsBalance(BiTree T){
	if(!T) return true;
	if(abs(hight(T->lchild)-hight(T->rchild)) > 1) return false;
	return IsBalance(T->lchild) && IsBalance(T->rchild);
}
int main(){
	BiTree T;
	cout << "请输入二叉树元素：";
	Create(T);
	InOrderTraverse(T);
	cout << endl;

	bool ret = IsBalance(T);
	if(ret){
		cout << "是平衡二叉树" << endl;
	}else{
		cout << "不是平衡二叉树" << endl;
	}
	return 0;
}