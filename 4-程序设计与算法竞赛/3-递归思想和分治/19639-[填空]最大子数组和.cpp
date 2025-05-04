#include <iostream>
#include <vector>
/*
 * 查找跨越中点的最大子数组和
 * 算法思想：
 * 1. 从中点向左扫描，计算包含中点在内的最大左子数组和
 * 2. 从中点向右扫描，计算包含中点在内的最大右子数组和
 * 3. 返回左右子数组和的总和
 * 
 * 记忆口诀：
 * 中点分界左右扫，最大和值要记牢
 * 左加右加得总和，跨越中点最值找
 */
int maxCrossingSum(const std::vector<int>& arr, int low, int mid, int high) {
        // 计算包含中点向左的最大和
    int leftSum = 0;
    int maxLeftSum = -999999; // 初始化为极小值
    for (int i = mid; i >= low; --i) {  // 从中点向左扫描
        leftSum += arr[i];
        if (leftSum > maxLeftSum) {
            maxLeftSum = leftSum;  // 更新最大左子数组和
        }
    }
    
    // 计算包含中点向右的最大和
    int rightSum = 0;
    int maxRightSum = -999999; // 初始化为极小值
    for (int i = mid + 1; i <= high; ++i) {  // 从中点向右扫描
        rightSum += arr[i];
        if (rightSum > maxRightSum) {
            maxRightSum = rightSum;  // 更新最大右子数组和
        }
    }
    
    // 返回跨越中点的最大子数组和
    return maxLeftSum + maxRightSum;
}
/*
 * 分治法求解最大子数组和
 * 算法思想：
 * 1. 分解：将数组分成左右两部分
 * 2. 解决：递归求解左右子数组的最大和
 * 3. 合并：计算跨越中点的最大子数组和，并与左右结果比较
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(logn) 递归栈空间
 * 
 * 记忆口诀：
 * 一分为二递归求，左右两边各自优
 * 跨越中点别忘记，三者最大是所求
 */
int maxSubArraySum(const std::vector<int>& arr, int low, int high) {
        // 递归终止条件：当子数组只有一个元素时
    if (low == high) {
        return arr[low];  // 单个元素的最大子数组和就是它本身
    }

//-------------该行开始是填空的内容--------------
        // 分治步骤：
    int mid = (low+high)/2;  // 计算中点
    int leftMax = maxSubArraySum(arr, low, mid);  // 递归求解左半部分最大和
    int rightMax = maxSubArraySum(arr, mid+1, high);  // 递归求解右半部分最大和
    int crossMax = maxCrossingSum(arr, low, mid, high);  // 计算跨越中点的最大和
//-------------该行之上是填空的内容--------------

        // 合并步骤：返回三者中的最大值
    return std::max({leftMax, rightMax, crossMax});
}
int main() {
    std::vector<int> arr;
    int n, data;
    std::cin>>n;
    for(int i=0; i<n; i++)
   {
        std::cin>>data;
        arr.push_back(data);
   }
    int maxSum = maxSubArraySum(arr, 0, n);
    std::cout <<  maxSum << std::endl;
    return 0;
} 
/*
Description
给定一个整数数组，找到一个具有最大和的连续子数组，返回其最大和，请使用分治的解法完成填空。
（注：分治法并不是解这题最快的算法，更快的DP算法能达到O(N)的复杂度，请自行了解相关知识。）


#include <iostream>
#include <vector>

int maxCrossingSum(const std::vector<int>& arr, int low, int mid, int high) {
        // 计算包含中点向左的最大和
    int leftSum = 0;
    int maxLeftSum = -999999; // 初始化为极小值
    for (int i = mid; i >= low; --i) {  // 从中点向左扫描
        leftSum += arr[i];
        if (leftSum > maxLeftSum) {
            maxLeftSum = leftSum;  // 更新最大左子数组和
        }
    }
    
    // 计算包含中点向右的最大和
    int rightSum = 0;
    int maxRightSum = -999999; // 初始化为极小值
    for (int i = mid + 1; i <= high; ++i) {  // 从中点向右扫描
        rightSum += arr[i];
        if (rightSum > maxRightSum) {
            maxRightSum = rightSum;  // 更新最大右子数组和
        }
    }
    
    // 返回跨越中点的最大子数组和
    return maxLeftSum + maxRightSum;
}

int maxSubArraySum(const std::vector<int>& arr, int low, int high) {
        // 递归终止条件：当子数组只有一个元素时
    if (low == high) {
        return arr[low];  // 单个元素的最大子数组和就是它本身
    }
_______________________
        // 合并步骤：返回三者中的最大值
    return std::max({leftMax, rightMax, crossMax});
}
int main() {
    std::vector<int> arr;
    int n, data;
    std::cin>>n;
    for(int i=0; i<n; i++)
   {
        std::cin>>data;
        arr.push_back(data);
   }
    int maxSum = maxSubArraySum(arr, 0, n);
    std::cout <<  maxSum << std::endl;
    return 0;
} 

输入格式
第1行一个整数N,N<=1000
第2行N个整数，以空格分隔


输出格式
输出连续子数组最大和


输入样例
8
-2 -5 6 -2 -3 1 5 -6


输出样例
7
*/