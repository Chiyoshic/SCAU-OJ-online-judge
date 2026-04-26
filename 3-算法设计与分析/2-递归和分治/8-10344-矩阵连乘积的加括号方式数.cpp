#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long dp[21] = {0};
    dp[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        dp[i] = 0;
        for (int k = 1; k < i; ++k) {
            dp[i] += dp[k] * dp[i - k];
        }
    }
    
    cout << dp[n] << endl;
    return 0;
}