#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<double> x(n);
    vector<double> a(n);

    for(int i=0; i<n; i++) cin >> x[i];
    a[0] = x[0];
    for(int i=1; i<n; i++) {
        a[i] = (a[i-1] * i + x[i]) / (double)(i+1);
    }

    for(int i=0; i<n; i++) cout << fixed << setprecision(2) << a[i] << " ";
    
    return 0;
}