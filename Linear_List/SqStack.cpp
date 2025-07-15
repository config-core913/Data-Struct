#include<iostream>
using namespace std;

#define MaxSize 100
typedef int ElemType;
typedef struct{
    ElemType *base;     //栈底指针，始终指向栈底
    ElemType *top;      //栈顶指针，初始时也指向栈底，栈非空时top指针指向栈顶元素的上一个元素
    int stacksize;      //栈的最大容量
}SqStack;
//顺序栈的初始化
bool InitSqStack(SqStack &S){
    S.base = new ElemType[MaxSize]; //为顺序栈动态分配一个容量为MaxSize的数组空间
    if(!S.base){
        return false;
    }
    S.top = S.base;
    S.stacksize = MaxSize;
    return true;
}
//入栈
bool Push(SqStack &S,ElemType element){
    if(S.top - S.base == S.stacksize){
        return false;   //栈满
    }
    *S.top++=element;
    // S.stacksize[S.top] = element;
    // S.top++;
    return true;
}
//出栈
bool Pop(SqStack &S,ElemType &e){
    if(S.top == S.base){
        return false;   //栈空
    }
    e=*--S.top;
    //--S.top;
    //e = *S.top;
    return true;
}
//取栈顶元素
ElemType GetTop(SqStack S){
    if(S.base != S.top){
        return *(S.top-1);
    }
}

int main(){
    SqStack S;
    InitSqStack(S);
    Push(S,10);
    ElemType test = GetTop(S);
    cout << test << endl;

    return 0;
}