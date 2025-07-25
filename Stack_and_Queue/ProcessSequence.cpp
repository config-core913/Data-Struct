#include<iostream>
using namespace std;

#define MaxSize 100
typedef int ElemType;
typedef struct {
    ElemType *data;
    int top,base;
}SqStack;
//初始化栈
void Init(SqStack &S){
    S.data = new ElemType[MaxSize];
    S.base = S.top = 0;
}
//判断栈满
bool Full(SqStack S){
    return S.top == MaxSize;
}
//判断栈空
bool Empty(SqStack S){
    return S.base == S.top;
}
//入栈
bool Push(SqStack &S,ElemType element){
    if(Full(S)){
        cout << "栈已经满，无法入栈！" << endl;
        return false;
    }else{
        cout << element << "入栈！" << endl;
        S.data[S.top] = element;
        S.top++;
        return true;
    }
}
//出栈
bool Pop(SqStack &S){
    if(Empty(S)){
        cout << "栈为空，无法出栈！" << endl;
        return false;
    }else{
        S.top--;
        int e = S.data[S.top];
        cout << e << "出栈！" << endl;
        
        return true;
    }
}

//输出栈顶元素
bool Print(SqStack S){
    if(S.top == S.base){
        return false;
    }else{
        cout << S.data[S.top - 1] << " ";
        return true;
    }
}
//处理整数序列
void ProcessSequence(){
    SqStack S;
    Init(S);
    cout << "请输入整数序列（输入 0 结束）：" << endl;
    
    int input_num;
    
    while(1){
        cin >> input_num;
        if(input_num == 0){
            cout << "结束！" << endl;
            return;
        }
        if(input_num != -1){
            Push(S,input_num);
        }else{
            Pop(S);
        }
    }
}
int main(){
    ProcessSequence();
    return 0;
}