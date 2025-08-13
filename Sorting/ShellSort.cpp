#include<iostream>
using namespace std;
//希尔排序
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

//希尔排序一趟插入函数
void ShellInsert(SqList &L,int dk){
    int i,j;
    for(i = dk + 1;i <= L.length;++i){
        if(L.r[i].key < L.r[i - dk].key){
            L.r[0].key = L.r[i].key;
            for(j = i - dk;j > 0 && L.r[0].key < L.r[j].key;j -= dk){
                L.r[j + dk] = L.r[j];
            }
            L.r[j + dk].key = L.r[0].key;
        }
    }
}
//希尔排序主函数
void ShellSort(SqList &L,int dt[],int t){
    for(int k = 0;k < t;k++){
        ShellInsert(L,dt[k]);
    }
}
int main(){
    SqList L;
    L.length = 0;

    // 1. 定义增量序列(dt)和其长度(t)
    //    你可以修改这个序列来观察排序过程的变化
    int dt[] = {5, 3, 1}; 
    int t = 3;

    // 2. 提示并接收用户输入
    cout << "请输入待排序序列 (以9999结束): ";
    int x;
    cin >> x;
    // 注意：数据从 r[1] 开始存放，因为 r[0] 被用作临时空间
    while(x != 9999 && L.length < MAXSIZE - 1){
        L.length++;
        L.r[L.length].key = x;
        cin >> x;
    }

    // 3. 打印排序前的序列
    cout << "排序前: ";
    for(int i = 1; i <= L.length; i++){
        cout << L.r[i].key << " ";
    }
    cout << endl;

    // 4. 调用希尔排序函数
    ShellSort(L, dt, t);

    // 5. 打印排序后的序列
    cout << "排序后: ";
    for(int i = 1; i <= L.length; i++){
        cout << L.r[i].key << " ";
    }
    cout << endl;

    return 0;
}