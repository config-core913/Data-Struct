#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct DLNode{
    ElemType data;
    DLNode *prior,*next;
}DLNode,*DLinkList;

//初始化循环双链表
void InitDList(DLinkList &DL){
    DL = new DLNode;
    DL->data = -1;
    DL->next = DL;
    DL->prior = DL;
}

//双循环链表尾插法 - 问题1：这里有bug
void Insert_tail(DLinkList &DL){
    ElemType x;
    cin >> x;
    DLinkList p = DL;
    while(x != 9999){
        DLinkList s = new DLNode;
        s->data = x;
        s->next = p->next;
        s->prior = p;
        
        // 问题在这里！应该修改 p->next 的 prior，而不是 p->prior
        // p->prior = s;  // 错误！这破坏了链表结构
        p->next->prior = s;  // 修正：应该是这样
        p->next = s;
        
        p = s;
        cin >> x;
    }
}

//打印链表
void Print(DLinkList DL){
    DLinkList p = DL->next;
    while(p->data != -1){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//交换特定节点及其前驱 - 问题2：条件判断错误
void change(DLinkList &DL,DLinkList p){
    // 原来的条件判断是错误的！
    // if(DL->next == DL || DL->prior == DL->prior){
    //     return;
    // }
    
    // 正确的判断应该是：
    if(p == NULL || p == DL->next || DL->next == DL){
        cout << "无法交换：节点为空、是第一个节点或链表为空" << endl;
        return;
    }
    
    cout << "交换前：p->data = " << p->data << ", p->prior->data = " << p->prior->data << endl;
    
    ElemType temp = p->data;
    p->data = p->prior->data;
    p->prior->data = temp;
    
    cout << "交换后：p->data = " << p->data << ", p->prior->data = " << p->prior->data << endl;
}

//返回指定结点的地址 - 需要添加返回NULL
DLinkList find_node(DLinkList DL,ElemType element){
    DLinkList p = DL->next;
    while(p != DL){
        if(p->data == element){
            return p;
        }
        p = p->next;
    }
    return NULL;  // 添加这一行！
}

// 调试用：打印链表结构
void PrintDebug(DLinkList DL){
    cout << "=== 链表结构调试信息 ===" << endl;
    if(DL->next == DL){
        cout << "空链表" << endl;
        return;
    }
    
    DLinkList p = DL->next;
    int count = 0;
    while(p != DL && count < 10){  // 防止死循环
        cout << "节点" << count+1 << ": data=" << p->data 
             << ", prior->data=" << p->prior->data 
             << ", next->data=" << p->next->data << endl;
        p = p->next;
        count++;
    }
    cout << "========================" << endl;
}

int main(){
    DLinkList DL;
    InitDList(DL);
    
    cout << "请输入结点：";
    Insert_tail(DL);
    
    cout << "插入后的链表：" << endl;
    Print(DL);
    
    // 调试信息
    PrintDebug(DL);
    
    //找到指定节点
    DLinkList find = find_node(DL,5);
    if(find == NULL){
        cout << "没有找到节点5" << endl;
    } else {
        cout << "找到节点5，开始交换..." << endl;
        change(DL,find);
        
        cout << "交换后的链表：" << endl;
        Print(DL);
    }
    
    return 0;
}

/*
问题分析：

1. Insert_tail函数中的错误：
   原代码：p->prior = s;  // 这会破坏链表结构！
   正确：  p->next->prior = s;  // 应该修改p的下一个节点的prior指针

2. change函数中的条件判断错误：
   原代码：if(DL->next == DL || DL->prior == DL->prior)
   这个条件判断没有意义，DL->prior == DL->prior 永远为真！
   
   正确应该检查：
   - p是否为空
   - p是否为第一个数据节点（无前驱可交换）
   - 链表是否为空

3. find_node函数缺少返回NULL的语句

修正后应该可以正常工作！
*/