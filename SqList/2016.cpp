#include<iostream>
using namespace std;
//2016年第一大题
//顺序表逆置
void reverse(int A[],int begin,int end){
    int temp;
    int j = end - 1;
    int i = begin;
    while(i < j){
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        if(i == j) break;
        j--;
    }
}

void rotate(int A[],int length,int k){
    k = k % length;
    if(k == 0) return;
    // reverse(A,0,length - k);
    // reverse(A,length - k,length);
    // reverse(A,0,length);

    reverse(A,0,length);
    reverse(A,0,k);
    reverse(A,k,length);
}
int main(){
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int length = 10;
    cout << "移动前：";
    for(int i = 0;i < length;i++){
        cout << A[i] << " ";
    }
    cout << endl;

    rotate(A,length,2);
    cout << "移动后：";
    for(int i = 0;i < length;i++){
        cout << A[i] << " ";
    }
    return 0;
}