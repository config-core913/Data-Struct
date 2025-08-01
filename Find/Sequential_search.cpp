#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct{
    ElemType *data;
    int length;
}SSTable;
//顺序查找(初始)
int Search_Seq1(SSTable S,ElemType key){
    for(int i = S.length;i >= 1;--i){
        if(S.data[i] == key){
            return i;
        }
    }
    return 0;
}
//顺序查找(改进)
int Search_Seq2(SSTable S,ElemType key){
    S.data[0] = key;
    int i;
    for(i = S.length;S.data[i] != key;--i);
    return i;
}
int main(){
    SSTable S;
    S.data = new int[10];
    S.length = 10;
    
    S.data[1] = 1;
    S.data[2] = 5;
    S.data[3] = 3;
    S.data[4] = 4;
    S.data[5] = 1;
    S.data[6] = 6;
    S.data[7] = 7;
    S.data[8] = 9;
    S.data[9] = 9;  
    int ret = Search_Seq2(S,5);
    cout << ret << endl;    
    return 0;
}