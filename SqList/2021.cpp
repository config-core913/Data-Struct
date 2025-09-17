#include<iostream>
using namespace std;
//21年双调序列找最大值

//枚举法，非高效做法
int findMAX1(int A[],int length){
	for(int i = 1;i < length;i++){
		if(A[i] > A[i-1] && A[i] > A[i+1]){
			return A[i];
		}
	}
	return 0;
}
//二分查找法
int findMAX2(int A[],int length){
	if (length <= 0) {
        return -1; // 表示输入无效
    }
    if (length == 1) {//只有一个元素
        return A[0];
    }
	int low = 0;
	int hight = length-1;
	int mid;
	while(low < hight){
		mid = (low + hight)/2;
		if(A[mid] > A[mid-1] && A[mid] > A[mid+1]){
			return A[mid];
		}else if(A[mid] > A[mid-1] && A[mid] < A[mid+1]){
			low = mid;
		}else{
			hight = mid;
		}
	}
	return -1;
}
int main(){
	int A[] = {1,2,3,4,5,6,7,8,100,120,7,6,5,4,3,2,1,0};
	int length = 18;
	int ret = findMAX2(A,length);
	if(ret){
		cout << "最大值为：" << ret << endl;
	}else{
		cout << "查找失败！" << endl;
	}
	return 0;
}