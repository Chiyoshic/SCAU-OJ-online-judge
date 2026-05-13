#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    
    if (cin >> n) {
        long long Ln = n * (n + 1) / 2 + 1;
        long long Cn = n * n - n + 2;
        long long Zn = 2 * n * n - n + 1;
        long long ZZn = (9 * n * n - 7 * n) / 2 + 1;
        
        cout << Ln << " " << Cn << " " << Zn << " " << ZZn << "\n";
    }

    return 0;
}