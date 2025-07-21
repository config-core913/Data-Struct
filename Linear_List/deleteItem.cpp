#include<iostream>
using namespace std;

//打印顺序表
void Print(int A[],int length){
    for(int i = 0;i < length;i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
//删除元素
void deleteItem(int A[],int item,int &length){
    int k = 0;
    for(int i = 0;i < length;i++){
        if(A[i] != item){
            A[k] = A[i];
            k++;
        }
    }
    length = k;
}
int main(){
    int A[] = {1,2,3,4,4,5,4,6,7,4,10};
    int length = sizeof(A)/sizeof(A[0]);
    cout << "原始数组：" << endl;
    Print(A,length);

    cout << "修改后的数组：" << endl;
    deleteItem(A,4,length);
    Print(A,length);
    return 0;
}