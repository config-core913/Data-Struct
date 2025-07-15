#include<iostream>
using namespace std;

#define MaxSize 500
typedef int ElemType;
typedef struct{
    ElemType *data;
    int length;
}SqList;
void InitSqList(SqList &L){         //初始化
    L.data = new ElemType[MaxSize];
    L.length = 0;
}
bool InsertList(SqList &L,int i,ElemType element){//插入元素
    if(i < 1 || i > L.length+1){
        return false;
    }
    for(int j = L.length;j >= i;j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = element;
    L.length++;
    return true;
}
void PrintSqList(SqList L){     //打印顺序表
    for(int i = 0;i < L.length;i++){
        cout << L.data[i] << "\t";
    }
    cout << endl;
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
//按值查找
int LocateElem(SqList L,ElemType e){
    for(int i = 0;i < L.length;i++){
        if(L.data[i] == e){
            return i+1;
        }
    }
    return -1;
}
int main(){
    SqList L;
    InitSqList(L);
    InsertList(L,1,1);
    InsertList(L,1,2);
    InsertList(L,1,3);
    InsertList(L,1,4);
    InsertList(L,1,5);
    InsertList(L,1,6);
    InsertList(L,1,7);
    InsertList(L,1,8);
    InsertList(L,1,9);
    InsertList(L,1,10);

    ElemType element;
    DeleteList(L,5,element);
    cout << "删除的元素是：" << element << endl;

    int find = LocateElem(L,100);
    if(find == -1){
        cout << "表内没有该元素" << endl;
    }else{
        cout << "元素的位置是：" << find << endl;
    }

    PrintSqList(L);
    return 0;
}