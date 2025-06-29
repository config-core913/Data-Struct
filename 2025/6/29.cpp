#include<iostream>
using namespace std;

#define MaxSize 100
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length;
}SqList;

void printList(SqList L)
{
    for(int i = 0;i < L.length;i++)
    {
        cout << L.elem[i] << " ";
    }
}
int main(){
    SqList L;
    L.length = 5;
    L.elem[0] = 1;
    L.elem[1] = 2;
    L.elem[2] = 3;
    L.elem[3] = 4;
    L.elem[4] = 5;
    L.elem[4] = 5;
    printList(L);
    return 0;
}