#include<iostream>
using namespace std;
//静态分配
#define MaxSize 100
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

void printList(SqList L)
{
    for(int i = 0;i < L.length;i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
void InitList(SqList &L)
{
    L.length = 0;
}
int main(){
    SqList L;
    InitList(L);

    L.length = 10;

    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.data[4] = 5;
    L.data[5] = 6;
    L.data[6] = 7;
    L.data[7] = 8;
    L.data[8] = 9;
    L.data[9] = 10;

    printList(L);
    return 0;
}