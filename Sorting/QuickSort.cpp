#include<iostream>
using namespace std;
//快速排序
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
int Partition(SqList &L,int low,int high){
    L.r[0] = L.r[low];
    int pivotkey = L.r[low].key;
    while(low < high){
        while(low < high && L.r[high].key >= pivotkey){
            --high;
        }
        L.r[low] = L.r[high];
        while(low < high && L.r[low].key <= pivotkey){
            ++low;
        }
        L.r[high] = L.r[low];
    }
    L.r[low] = L.r[0];
    return low; //返回枢纽位置
}
void QSort(SqList &L,int low,int high){
    if(low < high){
        int pivotloc = Partition(L,low,high);
        QSort(L,low,pivotloc - 1);
        QSort(L,pivotloc + 1,high);
    }
}
void QuickSort(SqList &L){
    QSort(L,1,L.length);
}
int main(){
    SqList L;
    L.length = 0;

    // 1. 提示并接收用户输入
    cout << "请输入待排序序列 (以9999结束): ";
    int x;
    cin >> x;
    // 注意：数据从 r[1] 开始存放
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

    // 3. 调用快速排序函数
    QuickSort(L);

    // 4. 打印排序后的序列
    cout << "排序后: ";
    for(int i = 1; i <= L.length; i++){
        cout << L.r[i].key << " ";
    }
    cout << endl;
    return 0;
}