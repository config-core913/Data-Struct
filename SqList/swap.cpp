#include<iostream>
using namespace std;
//顺序表中，交换两部分元素的位置
//顺序表逆置
void reverse(int A[],int begain,int end){
	int temp;
	while(begain < end){
		temp = A[begain];
		A[begain] = A[end];
		A[end] = temp;
		begain++;
		end--;
	}
}
//交换顺序表中两部分连续元素的位置
void swap(int A[],int mid,int length){
	reverse(A,0,mid-1);//先将前面一部分元素逆置
	reverse(A,mid,length-1);//后面一部分元素逆置
	reverse(A,0,length-1);//将整个顺序表逆置
}
int main(){
	int A[] = {1,2,3,4,5,6,7,8,9,10};
	int length = 10;
	cout << "交换前：";
	for(int i = 0;i < length;i++){
		cout << A[i] << " ";
	}
	cout << endl;
	swap(A,3,length);
	cout << "交换后：";
	for(int i = 0;i < length;i++){
		cout << A[i] << " ";
	}
	return 0;
}