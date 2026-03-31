#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n;
    long long a;
    cin >> n;
    cin >> a;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        int t = a % 10;
        a /= 10;
        v[i] = t;
    }

    sort(v.begin(), v.end());
    long long cnt = 1;

    do {
        cout << cnt++ << " ";
        for(int i=0; i<n; i++) {
            cout << v[i];
        }
        cout << endl;
    } while(next_permutation(v.begin(), v.end()));

    return 0;
}