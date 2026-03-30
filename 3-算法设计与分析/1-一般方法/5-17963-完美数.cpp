#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

bool isPrime(long long a) {
    long long b = sqrt(a);
    for(int i=2; i<=b; i++) {
        if(a % i == 0) return false;
    }
    return true;
}

long long pow2(int a) {
    long long b = 1;
    for(int i=0; i<a; i++) b *= 2;
    return b;
}

int main() {
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int cnt = 1;

    for(int i=2; cnt < 9; i++) {
        long long t = pow2(i) - 1;
        if(isPrime(t)) {
            long long ret = pow2(i - 1) * (pow2(i) - 1);
            cout << cnt++ << " " << ret << endl;
        }
    }

    return 0;
}