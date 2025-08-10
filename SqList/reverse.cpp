#include<iostream>
using namespace std;
//2013年真题，讲顺序表由 降序--> 升序
//顺序表结构

typedef struct{
    int *data;
    int length;
}SqList;

void reverse(SqList &L,int length){
    for(int i = 0;i < L.length/2;i++){
        
    }
}
int main(){
    SqList L;
    L.length = 0;
    cout << "降序输出" << endl;
    for(int i = 0;i < 10;i++){
        L.data[i] = 10 - i;
        cout << L.data[i] << " ";
        L.length++;
    }
    
    return 0;
}