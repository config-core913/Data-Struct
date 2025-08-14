#include<iostream>
using namespace std;
//堆排序
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
//调整堆
void HeapAdjust(SqList &L,int s,int m){
    int rc = L.r[s].key;
    for(int j = 2 * s;j <= m;j *= 2){
        if(j < m && L.r[j].key < L.r[j + 1].key){
            ++j;
        }
        if(rc >= L.r[j].key){
            break;
        }
        L.r[s].key = L.r[j].key;
        s = j;
    }
    L.r[s].key = rc;
}
//建初堆
void CreateHeap(SqList &L){
    int n = L.length;
    for(int i = n/2;i > 0;--i){
        HeapAdjust(L,i,n);
    }
}
//堆排序
void HeapSort(SqList &L){
    CreateHeap(L);
    for(int i = L.length;i > 1;--i){
        int x = L.r[1].key;
        L.r[1].key = L.r[i].key;
        L.r[i].key = x;
        HeapAdjust(L,1,i - 1);
    }
}
int main(){
     SqList L;
    L.length = 0;

    // 1. 提示并接收用户输入
    cout << "请输入待排序序列 (以9999结束): ";
    int x;
    cin >> x;
    // 注意：数据从 r[1] 开始存放，因为堆排序通常基于 1-based index
    while(x != 9999 && L.length < MAXSIZE - 1){
        L.length++;
        L.r[L.length].key = x;
        cin >> x;
    }

    // 2. 打印排序前的序列
    cout << "排序前: ";
    for(int i = 1; i <= L.length; i++){
        cout << L.r[i].key << " ";
    }
    cout << endl;

    // 3. 调用堆排序函数
    HeapSort(L);

    // 4. 打印排序后的序列
    cout << "排序后: ";
    for(int i = 1; i <= L.length; i++){
        cout << L.r[i].key << " ";
    }
    cout << endl;
    
    return 0;
}