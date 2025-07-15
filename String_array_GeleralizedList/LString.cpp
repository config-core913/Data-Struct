#include<iostream>
using namespace std;

#define CHUNKSSIZE 80
typedef struct Chunk{
    char ch[CHUNKSSIZE];
    Chunk *next;
}Chunk;
typedef struct {
    Chunk *head,*tail;//串的头尾指针
    int length;
}LString;

int main(){

    return 0;
}