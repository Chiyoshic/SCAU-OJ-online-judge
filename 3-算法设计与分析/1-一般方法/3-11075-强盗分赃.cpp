#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>

using namespace std;

int f(int a,int t) {
    if (a <= 0) return 0;
    if (t >= 6) return 1;
    a--;
    if (a <= 0) return 0;

    if (a % 5 == 0) {
        return f(a / 5 * 4, ++t);
    } else {
        return 0;
    }
}

int main() {
    long long n;
    cin >> n;
    int flag = 0;

    for(int i=1; i<=n; i++) {
        if(f(i, 1)) {
            cout << i << " ";
            flag = 1;
        }
    }

    if(!flag) cout << "impossible";
    return 0;
}