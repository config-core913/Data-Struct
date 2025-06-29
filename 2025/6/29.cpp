#include<iostream>
using namespace std;

#define MaxSize 100
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length;
}SqList;

int main(){
    SqList L;
    L.elem[0] = 1;
    L.elem[0] = 2;
    L.elem[0] = 3;
    L.elem[0] = 4;
    L.elem[0] = 5;
    
    return 0;
}