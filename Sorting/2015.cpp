#include<iostream>
using namespace std;
//2015年真题
//将一个数组中的负数移到数组前面，非负数移到后面
void ReSortArray(int a[],int lengh){
    // int i,j,temp;
    // i = 0;
    // j = lengh - 1;

    // while(i < j){
    //     if(a[i] < 0 && a[j] >= 0){
    //         i++;
    //         j--;
    //     }else if(a[i] >= 0 && a[j] < 0){
    //         temp = a[i];
    //         a[i] = a[j];
    //         a[j] = temp;
    //     }else if(a[i] < 0 && a[j] < 0){
    //         i++;
    //     }else{
    //         j--;
    //     }
    // }

    int i = 0;
    int j = lengh - 1;

    while (i < j) {
        // 1. 从左向右找到第一个非负数
        // 如果 a[i] 是负数，说明它位置正确，i 就继续前进
        while (i < j && a[i] < 0) {
            i++;
        }

        // 2. 从右向左找到第一个负数
        // 如果 a[j] 是非负数，说明它位置正确，j 就继续后退
        while (i < j && a[j] >= 0) {
            j--;
        }

        // 3. 如果 i < j，说明在左边找到了非负数，在右边找到了负数，交换它们
        if (i < j) {
            std::swap(a[i], a[j]); // 使用 std::swap 更标准
            // 交换后，i和j位置的数都已正确，可以各自移动一位
            // （这句也可以不写，外层循环会继续处理）
            i++; 
            j--;
        }
    }//新的编译器注释
}
int main(){
    int a[] = {-1,10,-2,2,-31,65,0,0,-9,50,-40};
    int lengh = 11;
    cout << "未排序前：";
    for(int i = 0;i < lengh;i++){
        cout << a[i] << " ";
    }
    ReSortArray(a,lengh);
    cout << endl << "排序后：";
    for(int i = 0;i < lengh;i++){
        cout << a[i] << " ";
    }
    return 0;
}