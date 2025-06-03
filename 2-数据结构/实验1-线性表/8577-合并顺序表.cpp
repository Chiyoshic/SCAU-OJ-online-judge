#include <iostream>
#include <vector>
using namespace std;

int main() {
    int na, nb;
    cin >> na;
    vector<int> A(na);
    for (int i = 0; i < na; ++i) {
        cin >> A[i];
    }
    
    cin >> nb;
    vector<int> B(nb);
    for (int i = 0; i < nb; ++i) {
        cin >> B[i];
    }
    
    vector<int> C;
    int i = 0, j = 0;
    while (i < na && j < nb) {
        if (A[i] <= B[j]) {
            C.push_back(A[i++]);
        } else {
            C.push_back(B[j++]);
        }
    }
    while (i < na) {
        C.push_back(A[i++]);
    }
    while (j < nb) {
        C.push_back(B[j++]);
    }
    
    cout << "List A:";
    for (int i = 0; i < na; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    cout << "List B:";
    for (int i = 0; i < nb; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;
    
    cout << "List C:";
    for (size_t i = 0; i < C.size(); ++i) {
        cout << C[i] << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Description
若线性表中数据元素相互之间可以比较，且数据元素在表中按值递增或递减，则称该表为有序表。

编写算法，将两个非递减有序顺序表A和B合并成一个新的非递减有序顺序表C。



输入格式
第一行：顺序表A的元素个数
第二行：顺序表A的各元素（非递减），用空格分开
第三行：顺序表B的元素个数
第四行：顺序表B的各元素（非递减），用空格分开


输出格式
第一行：顺序表A的元素列表
第二行：顺序表B的元素列表
第三行：合并后顺序表C的元素列表


输入样例
5
1 3 5 7 9
5
2 4 6 8 10


输出样例
List A:1 3 5 7 9 
List B:2 4 6 8 10 
List C:1 2 3 4 5 6 7 8 9 10 


提示
输出时注意大小写和标点。
*/