#include<iostream>
using namespace std;
//堆排序
#define MAXSIZE 20
typedef int KeyType;
typedef struct{
    KeyType key;
    //InfoType otherinfo;
}RedType;
typedef struct {
    RedType r[MAXSIZE];
    int length;
}SqList;
//两个相邻有序表的合并
void Merge(RedType R[],RedType T[],int low,int mid,int high){
    int i = low;
    int j = mid + 1;
    int k = low;
    while(i <= mid && j <= high){
        if(R[i].key <= R[j].key){
            T[k++] = R[i++];
        }else{
            T[k++] = R[j++];
        }
    }
    while(i <= mid){
        T[k++] = R[i++];
    }
    while(j <= high){
        T[k++] = R[j++];
    }
}
//二路归并
void MSort(RedType R[],RedType T[],int low,int high){
    if(low == high){
        T[low] = R[low];
    }else{
        int mid = (low + high)/2;
        MSort(R,S,low,mid);
        
    }
}
int main(){
    
}