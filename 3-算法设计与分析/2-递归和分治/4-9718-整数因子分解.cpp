#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

using ll = long long;

ll f[1000001];

int n;

int factor(int a) {
    if (a == 1) return 1;
    if (a < 1) return 0;

    ll ret = 0;
    for(int i = 2; i <= a; i++) {
        if(a % i != 0) continue;
        int cur = a / i;
        if(f[cur] != -1) {ret += f[cur]; continue;}
        // f[cur] = 0;
        ret += factor(cur);
        // ret += f[cur];
    }
    f[a] = ret;
    return ret;
}

int main() {
    memset(f, -1, sizeof(f));
    cin >> n;
    cout << factor(n) << endl;
}