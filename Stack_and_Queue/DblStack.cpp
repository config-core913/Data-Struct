#include<iostream>
using namespace std;

#define MaxSize 10
typedef int SElemType;
//双栈结构
typedef struct{
    int top[2],bot[2];
    SElemType *V;
    int m;
}DblStack;
//初始化
void Init_DblStack(DblStack &DS){
    DS.V = new SElemType[MaxSize];
    DS.m = MaxSize;

    DS.top[0] = -1;
    DS.bot[0] = 0;
    DS.top[1] = MaxSize;
    DS.bot[1] = MaxSize - 1;
}
//判断栈是否为空
bool Empty(DblStack DS,int i){
    if(i == 0){
        return DS.top[0] == -1;
    }else if(i == 1){
        return DS.top[1] == DS.m;
    }
}
//判断栈是否满
bool Full(DblStack DS){
    if(DS.top[0] + 1 == DS.top[1]){
        return true;
    }else{
        return false;
    }
}
//进栈
bool Push(DblStack &DS,int i,SElemType element){
    if(Full(DS)){
        return false;
    }
    if(i == 0){
        DS.top[0]++;
        DS.V[DS.top[0]] = element;
    }else if(i == 1){
        DS.top[1]--;
        DS.V[DS.top[1]] = element;
    }
    return true;
}
//出栈
bool Pop(DblStack &DS,int i,SElemType &element){
    if(Empty(DS,i)){
        return false;
    }
    if(i == 0){
        element = DS.V[DS.top[0]];
        DS.top[0]--;
    }else if(i == 1){
        element = DS.V[DS.top[1]];
        DS.top[1]++;
    }else{
        return false;
    }
    return true;
}
int main(){
    DblStack DS;
    Init_DblStack(DS);

    for(int i = 0;i < 5;i++){
        Push(DS,0,i);
    }
    for(int i = 9;i >= 5;i--){
        Push(DS,1,i);
    }
    cout << "数据元素已进栈！" << endl;

    // bool ret = Empty(DS,1);
    // if(ret){
    //     cout << "栈1为空";
    // }else{
    //     cout << "栈1不空";
    // }
    SElemType element;
    for(int i = 0;i < 5;i++){
        Pop(DS,0,element);
        cout << element << " ";
    }
    cout << endl;
    for(int i = 5;i < 10;i++){
        Pop(DS,1,element);
        cout << element << " ";
    }
    return 0;
}