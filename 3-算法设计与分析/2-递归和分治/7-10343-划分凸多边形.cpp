#include <iostream>
#include <vector>

using namespace std;

long long memo[25]; 

long long solve(int n) {
    if (n == 2) return 1;
    if (n == 3) return 1;

    if (memo[n] != -1) {
        return memo[n];
    }

    long long sum = 0;
    // 固定边 1-n，遍历第三个顶点 k
    for (int k = 2; k <= n - 1; k++) {
        // 左边是 k 边形，右边是 n - k + 1 边形
        sum += solve(k) * solve(n - k + 1);
    }

    return memo[n] = sum;
}

int main() {
    int n;
    for (int i = 0; i < 25; i++) {
        memo[i] = -1;
    }

    if (cin >> n) {
        // 处理不合法的输入
        if (n < 3) {
            cout << "No answer\n";
        } else {
            cout << solve(n) << "\n";
        }
    }
    
    return 0;
}