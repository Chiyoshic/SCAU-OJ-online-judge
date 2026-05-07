#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    
    priority_queue<int, vector<int>, greater<int>> min_heap;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;

        
        if (i < k) {
            min_heap.push(num);
        } 
        
        else {
            if (num > min_heap.top()) {
                min_heap.pop();     
                min_heap.push(num); 
            }
        }
    }

    
    
    vector<int> result(k);
    for (int i = k - 1; i >= 0; i--) {
        result[i] = min_heap.top();
        min_heap.pop();
    }

    for (int i = 0; i < k; i++) {
        cout << result[i];
        if (i < k - 1) {
            cout << " ";
        }
    }
    cout << "\n";

    return 0;
}