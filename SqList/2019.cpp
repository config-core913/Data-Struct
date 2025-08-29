// #include <iostream>
// using namespace std;
// //2019年第一大题
// //动态数组在最后插入元素，更新数组首地址
// typedef int ElemType;
// #define MAX_D_SIZE 500
// //插入数据在特定位置
// void Insert(int S[],ElemType D[],int i,ElemType x,int n,int &m){
// //S[]为首地址的数组
// //D[]为存储数组的连续空间的首地址
// //i为要插入的位置
// //x为插入的元素
// //m为数组的最大总量
// //n为S[]的最大
// 	 if(m >= MAX_D_SIZE){
//         return;
//     }
// 	if(i < 1 || i > n){
// 		return;
// 	}
// 	if(i == n){
// 		D[m] = x;
// 	}else{
// 		for(int j = m-1;j >= S[i+1];j--){
// 			D[j+1] = D[j];
// 		}
// 		D[S[i+1]] = x;
// 		for(int j = i+1;j<=n;j++){
// 			S[j]++;
// 		}
// 	}
// 	m++;
// }
// int main(){

// 	return 0;
// }
#include <iostream>
#include <iomanip> // 用于设置输出格式，比如 setw

using namespace std;

typedef int ElemType;
#define MAX_D_SIZE 50 // 将最大容量调小一些，方便测试“容量耗尽”的情况

// --------------------------------------------------------------------
// 我们之前已经完善的 Insert 函数
// --------------------------------------------------------------------
/**
 * @brief 在由S和D管理的数据结构中，向第i个数据组末尾插入元素x
 * @param S 存储各数据组首地址的数组 (逻辑上从 S[1] 开始)
 * @param D 存储所有数据的连续空间数组
 * @param i 目标数据组的序号 (范围: 1 <= i <= n)
 * @param x 待插入的数据元素
 * @param n 数据组的总个数
 * @param m 对当前数据元素总量的引用，函数会修改此值
 */
void Insert(int S[], ElemType D[], int i, ElemType x, int n, int &m) {
    // 步骤1: 检查存储空间是否已满
    if (m >= MAX_D_SIZE) {
        cout << "[函数消息] 错误：存储空间已满，无法插入！" << endl;
        return;
    }
    
    // 步骤2: 检查目标组号i是否在有效范围内
    if (i < 1 || i > n) {
        cout << "[函数消息] 错误：指定的数据组序号 " << i << " 不合法。" << endl;
        return;
    }
    
    // 步骤3: 执行插入操作
    if (i == n) {
        // 情况一: 在最后一个数据组末尾插入，无需移动元素
        D[m] = x;
    } else {
        // 情况二: 在中间数据组末尾插入，需要移动后续元素
        for (int j = m - 1; j >= S[i + 1]; j--) {
            D[j + 1] = D[j];
        }
        D[S[i + 1]] = x;
        for (int j = i + 1; j <= n; j++) {
            S[j]++;
        }
    }
    
    // 步骤4: 更新总数据量
    m++;
    cout << "[函数消息] 成功将 " << x << " 插入到第 " << i << " 组。" << endl;
}


// --------------------------------------------------------------------
// 辅助函数，用于打印当前 S 和 D 数组的状态
// --------------------------------------------------------------------
void printState(int S[], ElemType D[], int n, int m) {
    cout << "------ 当前状态 ------" << endl;
    cout << "数据组数量 n = " << n << ", 总元素数量 m = " << m << endl;

    // 打印 S 数组 (注意我们从 S[1] 开始)
    cout << "S 数组 (首地址):" << endl << "  ";
    for (int i = 1; i <= n; ++i) {
        cout << "S[" << i << "]=" << S[i] << "  ";
    }
    cout << endl;

    // 打印 D 数组，并用'|'分隔不同组
    cout << "D 数组 (数据):" << endl << "  ";
    if (m == 0) {
        cout << "(空)" << endl;
    } else {
        for (int i = 0; i < m; ++i) {
            // 检查当前位置是否是某个组的开头，以便打印分隔符
            bool is_start = false;
            for(int j = 1; j <= n; ++j) {
                if (S[j] == i) {
                    is_start = true;
                    break;
                }
            }
            if (is_start && i != 0) {
                cout << "| ";
            }
            cout << D[i] << " ";
        }
        cout << endl;
    }
    cout << "----------------------" << endl;
}


// --------------------------------------------------------------------
// Main 函数，用于初始化和执行测试
// --------------------------------------------------------------------
int main() {
    // 1. 初始化数据结构
    int n = 4; // 假设有4个数据组
    int m = 15; // 初始总元素数量

    int S[10] = {0}; // S 数组，大小留足余量，忽略 S[0]
    ElemType D[MAX_D_SIZE] = {0}; // 数据数组

    // 手动设置一个初始状态：
    // 第1组: 4个元素 {10, 11, 12, 13}
    // 第2组: 5个元素 {20, 21, 22, 23, 24}
    // 第3组: 0个元素 (空组)
    // 第4组: 6个元素 {40, 41, 42, 43, 44, 45}
    S[1] = 0;  // 第1组从 D[0] 开始
    S[2] = 4;  // 第2组从 D[4] 开始
    S[3] = 9;  // 第3组从 D[9] 开始 (大小为0)
    S[4] = 9;  // 第4组从 D[9] 开始

    int data_idx = 0;
    for (int i = 0; i < 4; ++i) D[data_idx++] = 10 + i;
    for (int i = 0; i < 5; ++i) D[data_idx++] = 20 + i;
    // 第3组为空
    for (int i = 0; i < 6; ++i) D[data_idx++] = 40 + i;
    
    cout << "===== 初始状态 =====" << endl;
    printState(S, D, n, m);

    // 2. 执行测试用例
    cout << "\n===== 测试用例 1: 在中间组(第2组)末尾插入 99 =====" << endl;
    Insert(S, D, 2, 99, n, m);
    printState(S, D, n, m);

    cout << "\n===== 测试用例 2: 在最后一个组(第4组)末尾插入 88 =====" << endl;
    Insert(S, D, 4, 88, n, m);
    printState(S, D, n, m);

    cout << "\n===== 测试用例 3: 在第一个组(第1组)末尾插入 77 =====" << endl;
    Insert(S, D, 1, 77, n, m);
    printState(S, D, n, m);

    cout << "\n===== 测试用例 4: 在一个空组(第3组)中插入 66 =====" << endl;
    Insert(S, D, 3, 66, n, m);
    printState(S, D, n, m);
    
    cout << "\n===== 测试用例 5: 尝试使用无效组号(i=5)插入 =====" << endl;
    Insert(S, D, 5, 55, n, m);
    printState(S, D, n, m);
    
    cout << "\n===== 测试用例 6: 将数组填满直到触发容量耗尽错误 =====" << endl;
    int insertions_needed = MAX_D_SIZE - m;
    cout << "当前容量 " << m << "/" << MAX_D_SIZE << "。需要再插入 " << insertions_needed << " 个元素来填满数组。" << endl;
    for (int i = 0; i < insertions_needed; ++i) {
        Insert(S, D, 4, 100 + i, n, m); // 全部插入到最后一组
    }
    cout << "数组已满，当前 m = " << m << "。尝试再次插入..." << endl;
    Insert(S, D, 4, 999, n, m);
    printState(S, D, n, m);

    return 0;
}