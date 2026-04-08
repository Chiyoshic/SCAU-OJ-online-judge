#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int n;
int mode = 1e9;
int modeMaxLength = 0;

int partition(vector<int> &v, int left, int right) {
    int index = (right + left) / 2;

    swap(v[index], v[right]);
    int i = left;
    int pri = v[right];

    for(int j = left; j < right; j++){
        if(v[j] < pri) {
            swap(v[j], v[i]);
            i++;
        }
    }

    swap(v[right], v[i]);
    return i;
}

int quickSelect(vector<int> &v, int left, int right, int targetIndex) {
    if(left >= right) {
        return v[left];
    }

    int partitionIndex = partition(v, left, right);

    if(partitionIndex == targetIndex) {
        return v[targetIndex];
    } else if(partitionIndex > targetIndex) {
        return quickSelect(v, left, partitionIndex - 1, targetIndex);
    } else if(partitionIndex < targetIndex) {
        return quickSelect(v, partitionIndex + 1, right, targetIndex);
    }
}

void findMode(vector<int> &v, int left, int right) {
    int middleIndex = (left + right) / 2;
    int middle = quickSelect(v, left, right, middleIndex);
    // cout << middleIndex << " " << middle << endl;

    if(left > right) return;

    if(left == right && modeMaxLength <= 1) {
        mode = min(mode, v[right]);
        return;
    }

    int l = left;
    int r = right;
    int i = left;
    
    while(i <= r) {
        if(v[i] < middle) {
            swap(v[i], v[l]);
            l++;
            i++;
        } else if(v[i] > middle) {
            swap(v[i], v[r]);
            r--;
        } else {
            i++;
        }
    }

    int middleLength = r - l + 1;

    if(middleLength > modeMaxLength) {
        modeMaxLength = middleLength;
        mode = middle;
    }

    if(middleLength == modeMaxLength) 
        mode = min(mode, middle);
    
    // cout << mode << " " << middleLength << endl;
    // cout << "----------" << endl;
    
    if(l - left + 1 >= middleLength) findMode(v, left, l - 1);
    if(right - r + 1 >= middleLength) findMode(v, r + 1, right);

}
    


int main() {
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    findMode(v, 0, n-1);
    cout << mode << " " << modeMaxLength << endl;
    return 0;
}