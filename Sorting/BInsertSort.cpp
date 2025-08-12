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
//折半插入排序
void BInsertSort(SqList &L){
    int i,j,low,hight,m;
    for(i = 2;i <= L.length;++i){
        L.r[0] = L.r[i];
        low = 1;
        hight = i - 1;
        while(low <= hight){
            m = (low + hight)/2;
            if(L.r[0].key < L.r[m].key){
                hight = m - 1;
            }else{
                low = m + 1;
            }
        }
        for(j = i - 1;j >= hight + 1;--j){
            L.r[j + 1] = L.r[j];
        }
        L.r[hight + 1] = L.r[0];
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
    BInsertSort(L);
    cout << endl << "排序后：";
    for(int i = 1;i <= L.length;i++){
        cout << L.r[i].key << " ";
    }
    return 0;
}