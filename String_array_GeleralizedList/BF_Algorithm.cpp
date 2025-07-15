#include<iostream>
using namespace std;
//串的顺序存储
#define MAXLEN 255
typedef struct{
    char ch[MAXLEN + 1];
    int length;
}SString;
int Index_BF(SString S,SString T,int pos){
    int i = pos;
    int j = 1;
    while(i <= T.length && j <= S.length){
        if(S.ch[i] == T.ch[j]){
            j++;
            i++;
        }else{
            i = i - j + 2;
            j = 1;
        }
    }
    if(j > T.length){
        return i - T.length;
    }else{
        return 0;
    }
}
int main(){
    SString T;
    SString S;

    return 0;
}