#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, key;
    cin >> n; // 读取元素个数

    vector<int> ST(n);
    for (int i = 0; i < n; ++i) {
        cin >> ST[i]; // 读取元素值
    }

    cin >> key; // 读取要查找的key

    // 顺序查找
    for (int i = 0; i < n; ++i) {
        if (ST[i] == key) {
            cout << "The element position is " << i + 1 << "." << endl;
            return 0;
        }
    }

    // 未找到
    cout << "The element is not exist." << endl;
    return 0;
}
/*
输入格式
第一行:元素个数n 
第二行：依次输入n个元素的值 
第三行：输入要查找的关键字key的值


输出格式
输出分两种情形： 
1.如果key值存在，则输出其在表中的位置x(表位置从1开始),格式为The element position is x. 
2.如果key值不存在输出："The element is not exist."


输入样例
6
1 3 5 7 9 10
5


输出样例
*/