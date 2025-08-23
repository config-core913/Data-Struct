#include <algorithm>
#include<iostream>
using namespace std;
//2016年第二大题
//二叉排序树中查找特定节点
typedef struct node{
	int key;
	struct node *lchild,*rchild;
}BinNode,*BiTree;
//建立二叉树
void CreateTree(BiTree &T) {
    string input;
    cin >> input;

    if (input == "#") {
        T = NULL;
    } else {
        T = new BinNode;
        // 使用 stoi (string to integer) 将字符串转换为整数
        T->key = stoi(input);
        // 递归创建左子树
        CreateTree(T->lchild);
        // 递归创建右子树
        CreateTree(T->rchild);
    }
}
//中序遍历
void InOrderTraverse(BiTree T){
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->key << " ";
		InOrderTraverse(T->rchild);
	}
}
//二叉排序树中查找结点
BiTree findNode(BiTree T,int key){
	// while(T != NULL && T->key != key){
	// 	if(T->key > key){
	// 		T = T->lchild;
	// 	}else{
	// 		T = T->rchild;
	// 	}
	// }
	// return T;


    // 递归的终止条件1: 树为空，查找失败
    if (T == NULL) {
        return NULL;
    }
    // 递归的终止条件2: 找到了匹配的节点
    if (key == T->key) {
        return T;
    } 
    // 递归调用：根据比较结果在相应的子树中继续查找
    else if (key < T->key) {
        // key 小于当前节点值，向左子树递归查找
        return findNode(T->lchild, key);
    } 
    else { // key > T->key
        // key 大于当前节点值，向右子树递归查找
        return findNode(T->rchild, key);
    }
}

int main(){

	BiTree T = NULL; // 初始化一个空树

    cout << "请按先序遍历顺序输入二叉树节点值 (数字)，" << endl;
    cout << "空节点请用 '#' 表示，节点间用空格隔开：" << endl;

    CreateTree(T);
    cout << "\n--- 树已创建 ---" << endl;
    cout << "二叉树的中序遍历结果：";
    InOrderTraverse(T);
    cout << endl; 

    BiTree t = findNode(T,7);
    cout << t->key << endl;
	return 0;
}




