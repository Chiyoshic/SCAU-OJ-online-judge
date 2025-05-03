#include <iostream>
#include <vector>
using namespace std;

/*
 * 丑数生成算法
 * 使用动态规划方法生成丑数序列
 * 丑数定义：只包含质因子2、3、5的正整数
 */

int main() {
    // 优化输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    /*
     * 输入处理部分
     * 读取测试用例并找出最大的n值
     * 用于确定需要生成的丑数数量
     */

    int T;
    cin >> T;
    vector<int> cases(T);
    int max_n = 0;
    for (int i = 0; i < T; ++i) {
        cin >> cases[i];
        if (cases[i] > max_n) {
            max_n = cases[i];
        }
    }

    // 初始化丑数数组，第一个丑数为1
    vector<int> ugly(max_n);
    ugly[0] = 1;
    
    // 初始化三个指针，分别对应2、3、5的倍数
    int i2 = 0; // 指向下一个要乘以2的丑数
    int i3 = 0; // 指向下一个要乘以3的丑数
    int i5 = 0; // 指向下一个要乘以5的丑数

    /*
     * 动态生成丑数序列
     * 每个新丑数都是之前某个丑数乘以2、3或5得到的最小值
     */
    for (int i = 1; i < max_n; ++i) {
        // 计算三个候选丑数
        int next2 = ugly[i2] * 2;
        int next3 = ugly[i3] * 3;
        int next5 = ugly[i5] * 5;

        // 选择三个候选中的最小值作为下一个丑数
        int min_val = min(next2, min(next3, next5));
        ugly[i] = min_val;

        // 移动指针：哪个候选被选中，对应的指针就前进一位
        // 这样可以避免重复计算相同的丑数
        if (min_val == next2) ++i2;
        if (min_val == next3) ++i3;
        if (min_val == next5) ++i5;
    }

    for (int n : cases) {
        cout << ugly[n - 1] << '\n';
    }

    return 0;
}

/*
Description
“丑数”是指除了质因子2,3，5，不含其它质因子的正整数，例如由小到大前10个“丑数”为
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, ...
现要求编写一个程序，输出指定第几位的“丑数”。


输入格式
第一行为正整数T（T<=10000）, 表示case的数目。
此后T行，每行一个正整数 n (确定该第n个凑数不超过100000000).


输出格式
每一个n，输出第n个“丑数”


输入样例
3
1
2
9


输出样例
1
2
10

*/