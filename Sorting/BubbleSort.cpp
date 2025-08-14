#include<iostream>
using namespace std;
//冒泡排序
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

void BubbleSort(SqList &L){
    int m = L.length - 1;
    int flag = 1;
    while( (m > 0) && (flag == 1)){
        flag = 0;
        for(int j = 1;j <= m;j++){
            if(L.r[j].key > L.r[j + 1].key){
                flag = 1;
                int t = L.r[j].key;
                L.r[j].key = L.r[j + 1].key;
                L.r[j + 1].key = t;
            }
        }
        --m;
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

    // 3. 调用冒泡排序函数
    BubbleSort(L);

    // 4. 打印排序后的序列
    cout << "排序后: ";
    for(int i = 1; i <= L.length; i++){
        cout << L.r[i].key << " ";
    }
    cout << endl;
    return 0;
}