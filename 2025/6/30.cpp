#include<iostream>
#include<cstdlib> //malloc 和 free
using namespace std;

//动态分配
typedef int ElemType;
#define InitSize 100
#define MaxSize 500
typedef struct {
    ElemType *data;
    int length;
}SqList;
//初始化顺序表
void InitList(SqList &L){
    // L.data = (ElemType*)malloc(MaxSize * sizeof(ElemType));
    L.data = new ElemType[InitSize];
    L.length = 0;
}
//插入元素
bool InsertList(SqList &L,int i,ElemType element){
    if(i < 1 || i > L.length + 1)//插入位置是否合法
    {
        return false;
    }
    if(L.length >= MaxSize){    //存储空间是否已满
        return 0;
    }
    for(int j = L.length;j >= i;j--)//将 i 元素后的元素后移
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = element;
    L.length++;
    return true;
}
void PrintList(SqList L){   //打印顺序表
    for(int i = 0;i < L.length;i++){
        cout << L.data[i] << "\t";
    }
}
//删除元素
bool DeleteList(SqList &L,int i,ElemType &element){
    if(i < 1 || i > L.length){
        return false;
    }
    element = L.data[i-1];
    for(int j = i;j < L.length;j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}
//按值查找元素
int LocateElem(SqList L,ElemType element){
    for(int i = 0;i < L.length;i++){
        if(L.data[i] == element){
            return i;
        }
    }
    return 0;
} 
//查找顺序表钟的最小值
ElemType findsmall(SqList L){
    int i = 0;
    ElemType small = L.data[i];
    

}
int main(){
    SqList L;
    InitList(L);
    L.length = 10;

    L.data[0] = 10;
    L.data[1] = 5;
    L.data[2] = 2;
    L.data[3] = 7;
    L.data[4] = 8;
    L.data[5] = 9;
    L.data[6] = 45;
    L.data[7] = 100;
    L.data[8] = 1;
    L.data[9] = 78;


    PrintList(L);
    //free(L.data);
    delete[] L.data;
}