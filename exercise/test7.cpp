#include<iostream>
using namespace std;

#define MAXSIZE 20
typedef int KeyType;
typedef struct {
    KeyType key;
}RedType;
typedef struct{
    RedType data[MAXSIZE];
    int length;
}SqList;
//直接插入排序
void InsertSort(SqList &L){
    int i,j;
    for(i = 2;i <= L.length;++i){
        if(L.data[i].key < L.data[i - 1].key){
            L.data[0].key = L.data[i].key;
            L.data[i].key = L.data[i - 1].key;
            for(j = i - 2;L.data[j].key > L.data[0].key;--j){
                L.data[j + 1] = L.data[j];
            }
            L.data[j + 1].key = L.data[0].key;
        }
    }
}
//折半插入
void BInsertSort(SqList &L){
    int i,j,low,hight,mid;
    for(i = 2;i <=L.length;++i){
        L.data[0].key = L.data[i].key;
        low = 1;
        hight = i - 1;
        while(low <= hight){
            mid = (low + hight)/2;
            if(L.data[mid].key > L.data[0].key){
                hight = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        for(j = i - 1;j >= hight + 1;--j){
                L.data[j + 1].key = L.data[j].key;
            }
        L.data[hight + 1].key = L.data[0].key;
    }
}
// int main(){
//     SqList L;
//     L.length = 0;
//     L.data[L.length].key = 0;
//     L.length++;
//     cout << "请输入元素：";
//     int x;
//     cin >> x;
//     while(x != 9999){
//         L.data[L.length].key = x;
//         cin >> x;
//         L.length++;
//     }
//     cout << "排序前：";
//     for(int i = 0;i <= L.length;i++){
//         cout << L.data[i].key << " ";
//     }
//     cout << endl << "排序后：";

//     BInsertSort(L);
    
//     for(int i = 0;i <= L.length;i++){
//         cout << L.data[i].key << " ";
//     }
//     return 0;
// }
int main() {
    SqList L;
    L.length = 0;
    cout << "请输入元素（输入9999结束）：";
    int x;
    cin >> x;
    // 关键：数据从 L.data[1] 开始存放
    while (x != 9999) {
        L.length++; 
        L.data[L.length].key = x; 
        cin >> x;
    }

    cout << "排序前：";
    // 从索引1开始打印
    for (int i = 1; i <= L.length; i++) {
        cout << L.data[i].key << " ";
    }

    cout << endl << "排序后：";
    BInsertSort(L);

    // 从索引1开始打印
    for (int i = 1; i <= L.length; i++) {
        cout << L.data[i].key << " ";
    }
    cout << endl;
    return 0;
}