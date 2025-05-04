#include <iostream> // 标准输入输出
#include <vector>   // 向量容器
#include <algorithm> // STL算法库，包含sort和next_permutation

using namespace std;

/*
算法思想：
1. 使用next_permutation生成所有可能的数字排列
2. 跳过有前导零的排列
3. 将数字组合转换为整数并检查是否能被K整除
4. 由于排列是按字典序生成的，第一个满足条件的数即为最小值

记忆方法：
- 必须先排序才能使用next_permutation
- 前导零检查：digits[0] == 0
- 数字组合转整数：num = num * 10 + d
- 整除检查：num % K == 0
*/
int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> digits(N);
    for (int i = 0; i < N; ++i) {
        cin >> digits[i];
    }
    
    if (N == 1) {
        if (digits[0] % K == 0) {
            cout << digits[0] << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    
    // 必须先排序才能保证next_permutation生成所有排列
    sort(digits.begin(), digits.end());
    bool found = false;
    long long min_num = -1; // Initialize with -1
    
    /*
    步骤详解：
    1. 生成下一个排列
    2. 检查是否有前导零，有则跳过
    3. 将数字组合转换为整数
    4. 检查是否能被K整除
    5. 找到第一个满足条件的数即为最小值
    */
    do {
        // 跳过有前导零的排列
        if (digits[0] == 0) {
            continue; // Skip numbers with leading zero
        }
        // 将数字组合转换为整数
        long long num = 0;
        for (int d : digits) {
            num = num * 10 + d;
        }
        // 检查是否能被K整除
        if (num % K == 0) {
            found = true;
            min_num = num;
            break; // Since we process in sorted order, the first valid is the smallest
        }
    } while (next_permutation(digits.begin(), digits.end()));
    
    if (found) {
        cout << min_num << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
/*
Description
用全部N(N<=10)个0-9的数字组成一个“有效”整数（即没有前置0的整数），
求这些组成的数中能被K(0<K<10^10)整除的最小数字。



输入格式
输入分两行，第一行输入N, K，第二行输入N个数字。


输出格式
输出满足条件的最小的数（不含前置0），如果没有满足条件的数输出 -1。


输入样例
4 7
4 0 1 3


输出样例
1043


提示
413 % 7 = 0， 但是有前置0，所以满足条件的最小数是 1043 % 7 = 0。
此类题目需注意特殊情况，比如n=1时,如只输入一个0，答案只能是0。
注意long long
*/