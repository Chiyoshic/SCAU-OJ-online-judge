#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    if (n % 2 != 0 && k < 3) {
        cout << 0 << "\n";
        return 0;
    }
    // n 为偶数时，颜色数 k 必须 >= 2
    if (n % 2 == 0 && k < 2) {
        cout << 0 << "\n";
        return 0;
    }

    vector<long long> a(n + 1, 0);

    if (n >= 1) a[1] = k;
    if (n >= 2) a[2] = k * (k - 1);
    if (n >= 3) a[3] = k * (k - 1) * (k - 2);

    for (int i = 4; i <= n; i++) {
        a[i] = (k - 2) * a[i - 1] + (k - 1) * a[i - 2];
    }

    cout << a[n] << "\n";

    return 0;
}