#include<iostream>
using namespace std;
//21年双调序列找最大值
//枚举法，非高效做法
int findMAX(int A[],int length){
	for(int i = 1;i < length;i++){
		if(A[i] > A[i-1] && A[i] > A[i+1]){
			return A[i];
		}
	}
	return 0;
}
//
int main(){
	int A[] = {1,2,3,4,5,6,7,8,100,8,7,6,5,4,3,2,1,0};
	int length = 18;
	int ret = findMAX(A,length);
	if(ret){
		cout << "最大值为：" << ret << endl;
	}else{
		cout << "查找失败！" << endl;
	}
	return 0;
}