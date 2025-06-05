#include <iostream>
#include <vector>
using namespace std;

int Search_Bin(const vector<int>& ST, int key) {
    int low = 0, high = ST.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (ST[mid] == key) {
            return mid;
        } else if (ST[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // 未找到
}

int main() {
    int n, key;
    cin >> n; // 读取元素个数

    vector<int> ST(n);
    for (int i = 0; i < n; ++i) {
        cin >> ST[i]; // 读取有序元素
    }

    cin >> key; // 读取要查找的key

    int pos = Search_Bin(ST, key); // 折半查找
    if (pos != -1) {
        cout << "The element position is " << pos << "." << endl;
    } else {
        cout << "The element is not exist." << endl;
    }

    return 0;
}

/*
Description 编写Search_Bin函数，实现在一个递增有序数组ST中采用折半查找法确定元素位置的算法.


输入格式
第一行:元素个数n 
第二行：依次输入n个元素的值（有序） 
第三行：输入要查找的关键字key的值


输出格式
输出分两种情形： 
1.如果key值存在，则输出其在表中的位置x(表位置从0开始),格式为The element position is x. 
2.如果key值不存在输出："The element is not exist."


输入样例
6
1 3 5 7 9 10
5


输出样例
The element position is 2.
*/