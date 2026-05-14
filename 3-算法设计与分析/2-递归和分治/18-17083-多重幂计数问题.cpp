#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> dp(n + 1, 0);

    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= i - 1; k++) {
            dp[i] += dp[k] * dp[i - k];
        }
    }

    cout << dp[n] << "\n";

    return 0;
}