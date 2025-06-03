#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; ++i) {
        cin >> list[i];
    }

    cout << "The List is:";
    for (int i = 0; i < n; ++i) {
        cout << list[i] << " ";
    }
    cout << endl;

    reverse(list.begin(), list.end());

    cout << "The turned List is:";
    for (int i = 0; i < n; ++i) {
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
输入格式
第一行：输入顺序表的元素个数
第二行：输入顺序表的各元素，用空格分开


输出格式
第一行：逆置前的顺序表元素列表
第二行：逆置后的顺序表元素列表


输入样例
10
1 2 3 4 5 6 7 8 9 10


输出样例
The List is:1 2 3 4 5 6 7 8 9 10 
The turned List is:10 9 8 7 6 5 4 3 2 1


作者 yqm
*/