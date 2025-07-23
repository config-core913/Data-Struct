#include<iostream>
using namespace std;

#define MaxSize 100
typedef char ElemType;
typedef struct{
    ElemType *data;
    int front,rear;
}SqStack;
//初始化栈
void Init_SqStack(SqStack &S){
    S.data = new ElemType[MaxSize];
    S.front = S.rear = 0; //尾指针指向栈顶元素后一个元素
}
//进栈
bool Push(SqStack &S,ElemType element){
    if(S.rear == MaxSize - 1){
        return false;
    }
    S.data[S.rear] = element;
    S.rear++;
    return true;
}
//出栈
bool Pop(SqStack &S,ElemType &element){
    if(S.front == S.rear){
        return false;
    }
    S.rear--;
    element = S.data[S.rear];
    return true;
}
//判断是否是回文数
bool is_palindrome(SqStack &S,char ch[],int length){
    int i = 0;
    //将字符串前一半元素进栈
    for(i;i < length/2;i++){
        Push(S,ch[i]);
    }
    //如果长度是奇数,那中间的字符不进栈，也不参与比较
    if(length % 2 == 1){
        i++;
    }
    //比较前一半字符和后一半字符
    ElemType e;
    for(i;i < length;i++){
        if(S.front == S.rear || !Pop(S,e) || e != ch[i]){
            return false;
        }
    }

    return true;
}
int main(){ 
    SqStack S;
    Init_SqStack(S);

    char ch[] = "abba"; 
    int length = 0;
    while(ch[length] != '\0'){
        length++;
    }
    bool ret = is_palindrome(S,ch,length);
    if(ret){
        cout << "字符串是回文数！" << endl;
    }else{
        cout << "字符串不是回文数！" << endl;
    }
    return 0;
}