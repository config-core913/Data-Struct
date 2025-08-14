#include<iostream>
using namespace std;
//选择排序
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
void SelectSort(SqList &L){
    for(int i = 1;i <L.length;i++){
        int k = i;
        for(int j = i+1;j <= L.length;j++){
            if(L.r[j].key < L.r[k].key){
                k = j;
            }
        }
        if(k!=i){
            int t = L.r[i].key;
            L.r[i].key = L.r[k].key;
            L.r[k].key = t;
        }
    }
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

    // 3. 调用选择排序函数
    SelectSort(L);

    // 4. 打印排序后的序列
    cout << "排序后: ";
    for(int i = 1; i <= L.length; i++){
        cout << L.r[i].key << " ";
    }
    cout << endl;
    
    return 0;
}