#include <iostream>
// 简单选择排序算法实现
// 算法思想：每次从待排序的数据元素中选出最小（或最大）的一个元素
// 存放在序列的起始位置，直到全部待排序的数据元素排完
// 记忆方法："打擂台" - 每次选出最小的元素放在前面
using namespace std;
int n;

int main(){
    // 输入数据
    cin >> n;
    int* a = new int[n];  // 动态分配数组
    
    // 读取待排序数据
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    // 简单选择排序主过程
    for(int i=0; i<n-1; i++){
        // 步骤1：找出[i,n-1]区间内的最小元素位置
        int pos = i;  // 初始化最小元素位置
        for(int j=i+1; j<n; j++){
            pos = (a[j] < a[pos])? j : pos;  // 更新最小元素位置
        }
        
        // 步骤2：交换当前元素与最小元素
        int t = a[i];
        a[i] = a[pos];
        a[pos] = t;

        // 输出当前排序结果（调试用）
        for(int j=0; j<n; j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
    
    // 释放内存
    delete[] a;
    return 0;
}
