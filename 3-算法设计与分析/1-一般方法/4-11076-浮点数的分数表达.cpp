#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

long long simplify(long long &a, long long &b) {
    long long g = gcd(a, b);
    a = a / g;
    b = b / g;
}

long long pow10(long long n) {
    long long res = 1;
    for (int i = 0; i < n; i++) {
        res *= 10;
    }
    return res;
}

int main() {
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    bool ifRound = false;
    long long n=0, r=0;
    long long na=0, ra=0;
    long long u=0, d=0;

    for(int i=2; i < s.size(); i++) {
        char t = s[i];
        if(t == '(') ifRound = true;
        else if(t == ')') break;
        else if(ifRound) {r = r * 10 + t - '0'; ra++;}
        else {n = n * 10 + t - '0'; na++;}
    }

    if(ifRound) {
        u = (n * (pow10(ra) - 1)) + r;
        d = (pow10(ra) - 1) * pow10(na);
    } else {
        u = n;
        d = pow10(na);
    }

    simplify(u, d);

    cout << u << " " << d;

    return 0;
}