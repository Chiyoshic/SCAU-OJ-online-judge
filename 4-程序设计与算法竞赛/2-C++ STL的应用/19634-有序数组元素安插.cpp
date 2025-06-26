#include <iostream>
#include <vector>
#include <algorithm>

/*
 * 计算中位数的函数
 * 记忆要点：
 * 1. 奇数长度：直接取中间元素 (n/2 索引)
 * 2. 偶数长度：取中间两个元素的平均值 ((nums[n/2-1] + nums[n/2])/2.0)
 * 注意：除以2.0确保结果是浮点数
 */
double findMedian(const std::vector<int>& nums) {
    int n = nums.size();
    if (n % 2 == 1) {
        return nums[n / 2];  // 奇数长度，直接返回中间元素
    } else {
        return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;  // 偶数长度，返回中间两数平均值
    }
}

int main() {
    // 第一阶段：读取初始有序序列
    int n;  // 初始序列长度
    std::cin >> n;
    
    std::vector<int> sequence(n);  // 创建存储序列的vector
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];  // 读取初始有序序列
    }
    
    // 第二阶段：处理插入操作
    int m;  // 插入操作次数
    std::cin >> m;
    
    for (int i = 0; i < m; ++i) {
        int num;  // 要插入的数字
        std::cin >> num;
        
        /*
         * 使用lower_bound找到合适的插入位置：
         * 1. lower_bound返回第一个不小于num的元素位置
         * 2. 这保证了插入后序列仍然有序
         * 记忆要点：
         * - lower_bound使用二分查找，时间复杂度O(log n)
         * - 它适用于有序序列
         */
        auto it = std::lower_bound(sequence.begin(), sequence.end(), num);
        sequence.insert(it, num);  // 在找到的位置插入新元素
        
        // 计算并输出当前中位数
        double median = findMedian(sequence);
        std::cout << median << std::endl;
    }

    return 0;
}

/*
19634 有序数组元素安插

描述：
给定n个有序整数构成的序列，之后做m次操作，每次操作给定一个整数，要求将该整数安插到有序序列当中，之后序列仍然保持有序，每一次操作之后，输出当前序列的中位数。(中位数是指，当序列为奇数个数时，中位数为排在中间的那个数字，当序列为偶数个数时，中位数为排在中间的两个数之和的一半)

输入格式：
第一行为n
第二行为n个整数，以空格分割
第三行为m
第四行为m个整数，以空格分割

输出格式：
m行，每行一个输出的中位数

输入样例：
3
1 5 9
2
3 10

输出样例：
4
5
*/
