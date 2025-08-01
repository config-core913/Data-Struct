#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct{
    ElemType *data;
    int length;
}SSTable;
//折半查找
int Search_Bin(SSTable S,ElemType key){
    int height = S.length;
    int low = 1;
    int mid = (height + low)/2;
    while(low <= height){
        if(S.data[mid] == key){
            return mid;
        }else if(key > mid){
            low = mid + 1;
        }else{
            height = mid - 1;
        }
    }
    return 0;
}
int main(){
    SSTable S;
    S.data = new int[10];
    S.length = 10;
    
    S.data[1] = 1;
    S.data[2] = 2;
    S.data[3] = 3;
    S.data[4] = 4;
    S.data[5] = 5;
    S.data[6] = 6;
    S.data[7] = 7;
    S.data[8] = 8;
    S.data[9] = 9;  

    int ret = Search_Bin(S,5);
    cout << ret << endl;
    return 0;
}