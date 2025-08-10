#include<iostream>
using namespace std;
//2013年真题，讲顺序表由 降序--> 升序
//顺序表结构

typedef struct{
    int *data;
    int length;
}SqList;
//首位交换元素
//排序算法-------
void reverse(SqList &L,int length){
    for(int i = 0;i < L.length/2 ;i++){
        int temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
    delete[] L.data;
}
int main(){
    SqList L;
    L.length = 0;
    L.data = new int[10];
    cout << "降序输出" << endl;
    for(int i = 0;i < 10;i++){
        L.data[i] = 10 - i;
        cout << L.data[i] << " ";
        L.length++;
    }
    cout << endl << "修改后：" << endl;
    reverse(L,L.length);
    for(int i = 0;i < 10;i++){
        cout << L.data[i] << " ";
    }
    return 0;
}