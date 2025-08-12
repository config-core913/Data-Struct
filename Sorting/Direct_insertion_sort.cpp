#include<iostream>
using namespace std;
//直接插入排序
#define MAXSIZE 20
typedef int KeyType;
typedef struct{
    KeyType key;
    //InfoType otherinfo;
}RedType;
typedef struct {
    RedType r[MAXSIZE];
    int length;
}SqList;
//直接插入排序
void InsertSort(SqList &L){
    int i,j;
    for( i = 2;i <= L.length;++i){
        if(L.r[i].key < L.r[i-1].key){
            L.r[0].key = L.r[i].key;
            L.r[i].key = L.r[i-1].key;
            for( j = i-2;L.r[0].key < L.r[j].key;--j){
                L.r[j+1] = L.r[j];
            }
            L.r[j+1] = L.r[0];
        }
    }
}
int main(){
    SqList L;
    L.length = 1;
    cout << "请输入元素：" << endl;
    KeyType x;
    cin >> x;
    while(x != 9999){
        L.r[L.length].key = x;
        L.length++;
        cin >> x;
    }
    cout << "排序前：";
    for(int i = 1;i <= L.length;i++){
        cout << L.r[i].key << " ";
    }
    InsertSort(L);
    cout << endl << "排序后：";
    for(int i = 1;i <= L.length;i++){
        cout << L.r[i].key << " ";
    }
    return 0;
}