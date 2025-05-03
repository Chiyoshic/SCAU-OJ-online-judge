#include <iostream>
#include <vector>
// 移除不必要的algorithm头文件，因为代码中没有使用STL算法

using namespace std;

// 二分查找函数，返回目标值应插入的位置
// 参数：v-有序数组，left-左边界，right-右边界，tar-目标值
/**
 * 二分查找函数，返回目标值应插入的位置以保持数组有序
 * @param v 有序整数数组的引用
 * @param left 查找区间的左边界
 * @param right 查找区间的右边界
 * @param tar 要查找的目标值
 * @return 目标值应插入的位置索引
 */
int BinarySearch(vector<int> &v, int left, int right, int tar){
    // 递归终止条件：当查找区间缩小到只有一个元素时
    if (left >= right) {
        // 比较目标值与当前元素大小，决定插入位置
        return (tar > v[left]) ? left + 1 : left;
    }
    // 计算中间位置
    int mid = (left+right)/2;
    
    // 目标值大于中间值，在右半区间继续查找
    if(tar > v[mid]) return BinarySearch(v, mid+1, right, tar);
    
    // 目标值小于中间值，在左半区间继续查找
    if(tar < v[mid]) return BinarySearch(v, left, mid, tar);
    
    // 目标值等于中间值，继续在左半区间查找以保持稳定性
    return BinarySearch(v, left, mid, tar);
}

int main() {
    // 初始化有序数组
    vector<int> v;  // 存储有序整数序列
    int n;          // 用于存储输入的数量
    // 移除重复的vector和n声明
    // 读取初始有序数组
    cin >> n;
    while(n--) {
        int t;  // 临时存储输入的数字
        cin >> t;
        v.push_back(t);  // 将数字添加到数组末尾
    }

    // 读取要插入的数字数量
    cin >> n;
    while(n--) {
        int t;  // 临时存储要插入的数字
        cin >> t;
        
        // 使用二分查找确定插入位置
        int pos = BinarySearch(v, 0, v.size()-1, t);
        
        // 在正确位置插入数字，保持数组有序
        v.insert(v.begin()+pos, t);
        // 计算并输出当前中位数
        int size = v.size();
        
        // 数组长度为奇数时，中位数是中间元素
        if(size % 2 != 0) {
            cout << v[size/2] << endl;
        }
        // 数组长度为偶数时，中位数是中间两个数的平均值
        else {
            double median = (v[size / 2 - 1] + v[size / 2]) / 2.0;
            
            // 如果中位数是整数，输出整数形式；否则保留小数
            if (median == (int)median) {
                cout << (int)median << endl;
            } else {
                cout << median << endl;
            }
        }
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