#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>

inline long long aaa(long long a){
    return a<=0 ? -a : a;
}

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> v(n);
    int maxl = 1;
    for (int i = 0; i < n; i++) cin >> v[i];
    int i=n-1, j=n-1;
    while(i>=0 && j>0) {
        while(i >= 0 && j > 0 && v[i] <= aaa(v[j])) {
            maxl = max(maxl, j - i + 1);
            // cout << "i:" << i << ", j:" << j << endl;
            i--;
        }

        while(j > i && v[i] > aaa(v[--j]));
    }

    cout << maxl;
}