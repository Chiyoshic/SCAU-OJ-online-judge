#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    if (n < 1) {
        cout << 0 << "\n";
        return 0;
    }

    vector<long long> Total(n + 1, 0);

    Total[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            Total[i] += Total[j] * Total[i - j];
        }
    }

    cout << Total[n] << "\n";

    return 0;
}