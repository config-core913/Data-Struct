#include <iostream>
#include <string> // 需要用 string 来读取输入
#include <limits> // 需要用 numeric_limits

using namespace std;

typedef int DataType;

// 二叉树节点结构体
struct BinTNode {
    DataType data;
    BinTNode *lchild;
    BinTNode *rchild;
};

void CreateTree(BinTNode* &T) {
    string input;
    cin >> input;

    if (input == "#") {
        T = NULL;
    } else {
        T = new BinTNode;
        // 使用 stoi (string to integer) 将字符串转换为整数
        T->data = stoi(input);
        // 递归创建左子树
        CreateTree(T->lchild);
        // 递归创建右子树
        CreateTree(T->rchild);
    }
}

// 中序遍历打印，用于验证树是否创建成功
void InOrderTraversal(BinTNode* T) {
    if (T == NULL) {
        return;
    }
    InOrderTraversal(T->lchild);
    cout << T->data << " ";
    InOrderTraversal(T->rchild);
}

// bool IsBST_Recursive(BinTNode* T, long long &pre_data) {
//     if (T == NULL) {
//         return true;
//     }
//     //递归判断左子树
//     if (!IsBST_Recursive(T->lchild, pre_data)) {
//         return false;
//     }
//     //判断当前结点的值是否满足要求
//     if (T->data <= pre_data) {
//         return false;
//     }
//     //满足条件，将pre_data更新
//     pre_data = T->data;
//     return IsBST_Recursive(T->rchild, pre_data);
// }


bool IsBST_Recursive(BinTNode *T,long long &pre_data){
    if(T == NULL){
        return true;
    }
    if(!IsBST_Recursive(T->lchild,pre_data)){
        return false;
    }
    if(T->data <= pre_data){
        return false;
    }
    pre_data = T->data;
    return IsBST_Recursive(T->rchild,pre_data);
}


bool IsBinarySortTree(BinTNode* T) {
    // C++ 中获取最小值的方式
    long long pre_val = numeric_limits<long long>::min();
    return IsBST_Recursive(T, pre_val);
}

// 释放树的内存
void FreeTree(BinTNode* T) {
    if (T == NULL) {
        return;
    }
    FreeTree(T->lchild);
    FreeTree(T->rchild);
    delete T;
}

int main() {
    BinTNode* myTree = NULL; // 初始化一个空树

    cout << "请按先序遍历顺序输入二叉树节点值 (数字)，" << endl;
    cout << "空节点请用 '#' 表示，节点间用空格隔开：" << endl;
    
    // 调用函数，通过用户输入创建二叉树
    CreateTree(myTree);

    cout << "\n--- 树已创建 ---" << endl;
    
    cout << "中序遍历结果: ";
    InOrderTraversal(myTree);
    cout << endl;

    cout << "开始判断该树是否为二叉排序树..." << endl;
    if (IsBinarySortTree(myTree)) {
        cout << "结果: 是二叉排序树。" << endl;
    } else {
        cout << "结果: 不是二叉排序树。" << endl;
    }

    // 释放内存
    FreeTree(myTree);

    return 0;
}