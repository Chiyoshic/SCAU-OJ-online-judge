#include <iostream>
#include <vector>

using namespace std;

int n;
long long cnt = 0;

bool Findsame(const vector<char>& list, int k, int i) {
    for (int j = k; j < i; j++) {
        if (list[j] == list[i]) {
            return true; 
        }
    }
    return false;
}

void PermExcludeSame(int k, vector<char>& list) {
    if (k == n) {
        cnt++;
        for (int i = 0; i < n; i++) {
            cout << list[i];
        }
        cout << "\n";
        return;
    }

    for (int i = k; i < n; i++) {
        if (Findsame(list, k, i)) {
            continue;
        }
        
        swap(list[k], list[i]);
        PermExcludeSame(k + 1, list);
        swap(list[k], list[i]);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    if (!(cin >> n)) return 0;
    
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    PermExcludeSame(0, v);

    cout << cnt << "\n";

    return 0;
}