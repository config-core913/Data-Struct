#include<iostream>
using namespace std;

#define MaxSize 10
struct Node{
    int data;
    int next;
};
typedef struct{
    int data;
    int next;
}SLinkList[MaxSize];

void testSLinkList(){
    struct Node x;
    cout << "sizeX = " << sizeof(x) << endl;

    struct Node a[MaxSize];
    cout << "sizeA = " << sizeof(a) << endl;

    SLinkList b;
    cout << "sizeofB = " << sizeof(b) << endl;
}
int main(){
    testSLinkList();

    return 0;
}