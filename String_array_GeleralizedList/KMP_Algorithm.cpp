#include<iostream>
using namespace std;

#define MAXLINE 255
typedef struct{
    char ch[MAXLINE + 1];
    int length;
}SString;
//next数组
void get_next(SString T,int next[]){
    int i = 1;
    next[1] = 0;
    int j = 0;
    while(i < T.length){
        if(j == 0 || T.ch[i] == T.ch[j]){
            ++i;
            ++j;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}
//nextval
void get_nextval(SString T,int nextval[]){
    int i = 1;
    nextval[1] = 0;
    int j = 0;
    while(i < T.length){
        if(j == 0 || T.ch[i] == T.ch[j]){
            ++i;
            ++j;
            if(T.ch[i] != T.ch[j]){
                nextval[i] = j;
            }else{
                nextval[i] = nextval[j];
            }
        }else{
                j = nextval[j];
            }
    }
}
//KMP
int Index_KMP(SString S,SString T,int pos){
    int i = pos;
    int j = 1;
    int next[MAXLINE];
    get_next(T, next);
    while(i <= S.length && j <= T.length){
        if(j == 0 || S.ch[i] == T.ch[j]){
            ++i;
            ++j;
        }else{
            j = next[j];
        }
    }
    if(j > T.length){
        return i - T.length;
    }else{
        return 0;
    }
}
int main(){

    return 0;
}