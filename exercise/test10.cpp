#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <map>

/**
 * @brief 统计比赛选手分数的频率。
 * * @param scores 一个已排序的整数向量，包含所有选手的分数。
 * @param k 统计窗口的大小，即以中位数为中心，计算相邻的k个分数的平均值。
 * @return 一个map，键为平均值，值为该平均值出现的频率。
 */
std::map<int, int> analyzeScores(const std::vector<int>& scores, int k) {
    // 使用map存储平均值及其对应的频率
    std::map<int, int> frequency_map;
    
    int n = scores.size();
    if (n < k) {
        // 如果数据总数小于k，无法形成有效的k个分数的窗口
        return frequency_map;
    }

    // 遍历整个分数数组，将每个分数都作为“中位数”来计算
    for (int i = 0; i < n; ++i) {
        // 计算以当前分数(scores[i])为中心的k个分数的起始和结束索引
        int start_index = i - k / 2;
        int end_index = i + k / 2;

        // 检查窗口是否超出边界
        if (start_index >= 0 && end_index < n) {
            long long sum = 0;
            // 计算窗口内分数的总和
            for (int j = start_index; j <= end_index; ++j) {
                sum += scores[j];
            }
            
            // 计算平均值并取整
            int average = static_cast<int>(std::round(static_cast<double>(sum) / k));
            
            // 统计该平均值的频率
            frequency_map[average]++;
        }
    }
    
    return frequency_map;
}

// 辅助函数：打印频率统计结果
void printFrequency(const std::map<int, int>& frequency_map) {
    if (frequency_map.empty()) {
        std::cout << "无法进行统计，窗口大小k不符合要求或数据不足。" << std::endl;
        return;
    }
    std::cout << "统计结果如下 (平均值 -> 频率):" << std::endl;
    for (const auto& pair : frequency_map) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}

// 主测试函数
int main() {
    // 示例数据，已按升序排序
    std::vector<int> scores = {65, 70, 75, 80, 85, 90, 95};
    int k = 3; // 窗口大小

    std::cout << "原始分数数据: ";
    for (int score : scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    
    std::cout << "窗口大小 k = " << k << std::endl;

    // 调用分析函数
    std::map<int, int> result_map = analyzeScores(scores, k);

    // 打印结果
    printFrequency(result_map);

    std::cout << "\n---" << std::endl;
    
    // 另一个测试用例，偶数个分数
    std::vector<int> scores2 = {60, 65, 70, 75, 80, 85, 90, 95};
    int k2 = 5;

    std::cout << "原始分数数据: ";
    for (int score : scores2) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    
    std::cout << "窗口大小 k = " << k2 << std::endl;

    // 调用分析函数
    std::map<int, int> result_map2 = analyzeScores(scores2, k2);

    // 打印结果
    printFrequency(result_map2);

    return 0;
}