#include<iostream>
using namespace std;
//设计一算法，使得在尽可能少的时间内重排数组，将所有取负值的关键字放在所有取非负值的关键字之前。
void adjust(int A[],int len){
	int i = 0;
	int j = len;
	while(i < j){
		while(A[i] < 0){
			i++;
		}
		while(A[j] > 0){
			j--;
		}
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
}
int main(){
	int A[] = {1,2,3,0,4,5,-5,-4,-3,-2,-1};
	int len = 11;
	cout << "调整之前：";
	for(int i = 0;i < len;i++){
		cout << A[i] << " ";
	}
	cout << endl;
	adjust(A,len);
	cout << "调整之后：";
	for(int i = 0;i < len;i++){
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}