#include<iostream>
using namespace std;
//串的顺序存储
#define MAXLEN 255
typedef struct{
    char ch[MAXLEN + 1];
    int length;
}SString;
//串的堆式存储
typedef struct{
    char *ch;
    int length;
}HString;

int main(){
    return 0;
}