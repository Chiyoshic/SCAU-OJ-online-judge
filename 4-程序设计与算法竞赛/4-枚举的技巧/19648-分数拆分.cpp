#include <iostream> // 只需要iostream头文件，用于输入输出
using namespace std;

/*
算法思想：
1. 从基本等式出发：1/n = 1/x + 1/y
2. 通分变形：1/y = 1/n - 1/x => (x-n)/(n*x) = 1/y
3. 交叉相乘得：y = (n*x)/(x-n)
4. 由于x和y必须是正整数，所以x必须大于n且(n*x)必须能被(x-n)整除
5. 引入变量d = x - n，则y = (n*(n+d))/d = n + n²/d
6. 因为y必须是整数，所以n²/d必须是整数，即d必须是n²的约数
7. 由于x = n + d ≥ y = n + n²/d，推导出d ≤ n

数学推导详细说明：
- 从1/n = 1/x + 1/y出发，通过代数变形得到y = (n*x)/(x-n)
- 令d = x - n，则x = n + d
- 代入y的表达式：y = n*(n+d)/d = (n² + n*d)/d = n + n²/d
- 因为y必须是整数，n²/d必须是整数，所以d必须是n²的约数
- 由于x ≥ y => n + d ≥ n + n²/d => d ≥ n²/d => d² ≥ n² => d ≥ n
- 但d ≤ n，因为当d > n时，y = n + n²/d < n + n = 2n，而x = n + d > 2n，此时x > y

记忆技巧：
- 关键公式：y = n + d, x = n + n²/d
- d的范围：1 ≤ d ≤ n
- d必须是n²的约数
- 输出时x ≥ y
*/
int main() {
    long long n;
    cin >> n; // 读取输入的正整数n
    vector<pair<long long, long long> > solutions; // 存储所有解(x,y)的容器

    // 枚举所有可能的d值(1到n)
    for (long long d = 1; d <= n; ++d) {
        // 检查d是否是n²的约数
        if ((n * n) % d == 0) {
            // 根据公式计算y和x
            long long y = n + d; // y = n + d
            long long x = n + (n * n) / d; // x = n + n²/d
            solutions.push_back(make_pair(x, y)); // 存储有效解
        }
    }

    // 输出所有解，按题目要求格式
    for (size_t i = 0; i < solutions.size(); ++i) {
        long long x = solutions[i].first;
        long long y = solutions[i].second;
        // 输出格式：1/n=1/x+1/y
        cout << "1/" << n << "=1/" << x << "+1/" << y << endl;
    }

    return 0;
}
/*
描述：
输入一个正整数，找到所有的正整数x>=y,使得1/k=1/x+1/y

输入格式：
一个正整数n，n<=100000

输出格式：
一行一个分式等式
小的分数显示在前面；多个等式，等式右边第一个分数小的先输出

输入样例：
2

输出样例：
1/2=1/6+1/3
1/2=1/4+1/4
*/