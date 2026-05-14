#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> x(n);
    vector<int> y(n);

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int median_x = x[n / 2];
    int median_y = y[n / 2];

    long long min_distance = 0;

    for (int i = 0; i < n; ++i) {
        min_distance += abs(x[i] - median_x);
        min_distance += abs(y[i] - median_y);
    }

    cout << min_distance << "\n";

    return 0;
}