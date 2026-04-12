#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

using ll = long long;

ll memo[101][101][101];

ll dfs(int r, int k, int prev) {
    if (r == 0) return 1;
    if (k == 0) return 0;
    if (prev == 0) return 0;

    ll &res = memo[r][k][prev];
    if (res != -1) return res;

    res = 0;

    for(int i=1; i <= min(r, prev); i++) {
        res += dfs(r - i, k - 1, i);
    }

    return res;
}

ll initialiser(int m, int n) {
    memset(memo, -1, sizeof(memo));
    return dfs(m, n, m);
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << initialiser(m, n) << endl;
    return 0;
}