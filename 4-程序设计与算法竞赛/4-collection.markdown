# 程序设计与算法竞赛

## 1.四个常见问题

### 18104-练习使用多case解题
- Description
多CASE的问题在般有3种情形：（1）有一个数字开始表明CASE数目；（2）以特殊标志表示结束；（3）要求处理到最后一行。
现要求你在程序一次运行中，依次处理上述3种情况。

有三批测试数据，第1批测试数据，开头会以一个数字告之该批CASE数量，每一个CASE是两个正整数；
第1批测试数据结束后，紧接着是第2批数据，每一个CASE同样是两个正整数，第2批测试数据以两个0结束；
第2批测试数据结束后，紧接着是第3批数据，每一个CASE也是两个正整数，第3批测试数据一直到数据输入结束；

要求，每一个CASE，输出两数的最小公倍数
第1批测试数据处理完毕时，输出“group 1 done”
第2批测试数据处理完毕时，输出“group 2 done”
第3批测试数据处理完毕时，输出“group 3 done”


- 输入格式
有三批测试数据，第1批测试数据，开头会以一个数字告之该批CASE数量，每一个CASE是两个正整数(最大2的31次方)；
第1批测试数据结束后，紧接着是第2批数据，每一个CASE同样是两个正整数，第2批测试数据以两个0结束；
第2批测试数据结束后，紧接着是第3批数据，每一个CASE也是两个正整数，第3批测试数据一直到数据输入结束；


- 输出格式
要求，每一个CASE，输出两数的最小公倍数
第1批测试数据处理完毕时，输出“group 1 done”
第2批测试数据处理完毕时，输出“group 2 done”
第3批测试数据处理完毕时，输出“group 3 done”


- 输入样例
```
2
6 10
5 12
8 16
12 18
8 4
0 0
4 5
4 6
```


- 输出样例
```
30
60
group 1 done
16
36
8
group 2 done
20
12
group 3 done
```

- one of the answers
```cpp
#include <iostream>

using namespace std;

// 计算两个数的最大公约数（GCD）
// 使用欧几里得算法递归实现
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 计算两个数的最小公倍数（LCM）
// 基于公式：LCM(a,b) = a*b / GCD(a,b)
// 为避免溢出，先除后乘
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n;
    long long a, b;
    
    // 处理第一组数据：以数字n开头，表示有n个case
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << lcm(a, b) << endl;
    }
    cout << "group 1 done" << endl;
    
    // 处理第二组数据：以0 0作为结束标志
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        cout << lcm(a, b) << endl;
    }
    cout << "group 2 done" << endl;
    
    // 处理第三组数据：一直处理到输入结束
    while ((cin >> a >> b)) {
        cout << lcm(a, b) << endl;
    }
    cout << "group 3 done" << endl;
    
    return 0;
}
```

## 2.C++ STL 的应用

### 19634-有序数组元素安插

- Description
给定n个有序整数构成的序列，之后做m次操作，每次操作给定一个整数，要求将该整数安插到有序序列当中，之后序列仍然保持有序，每一次操作之后，输出当前序列的中位数。(中位数是指，当序列为奇数个数时，中位数为排在中间的那个数字，当序列为偶数个数时，中位数为排在中间的两个数之和的一半)

- 输入格式：
第一行为n
第二行为n个整数，以空格分割
第三行为m
第四行为m个整数，以空格分割

- 输出格式：
m行，每行一个输出的中位数

- 输入样例：
```
3
1 5 9
2
3 10
```

- 输出样例：
```
4
5
```

- one of the answers
```cpp
#include <iostream>
#include <vector>
// 移除不必要的algorithm头文件，因为代码中没有使用STL算法

using namespace std;

// 二分查找函数，返回目标值应插入的位置
// 参数：v-有序数组，left-左边界，right-右边界，tar-目标值
/**
 * 二分查找函数，返回目标值应插入的位置以保持数组有序
 * @param v 有序整数数组的引用
 * @param left 查找区间的左边界
 * @param right 查找区间的右边界
 * @param tar 要查找的目标值
 * @return 目标值应插入的位置索引
 */
int BinarySearch(vector<int> &v, int left, int right, int tar){
    // 递归终止条件：当查找区间缩小到只有一个元素时
    if (left >= right) {
        // 比较目标值与当前元素大小，决定插入位置
        return (tar > v[left]) ? left + 1 : left;
    }
    // 计算中间位置
    int mid = (left+right)/2;
    
    // 目标值大于中间值，在右半区间继续查找
    if(tar > v[mid]) return BinarySearch(v, mid+1, right, tar);
    
    // 目标值小于中间值，在左半区间继续查找
    if(tar < v[mid]) return BinarySearch(v, left, mid, tar);
    
    // 目标值等于中间值，继续在左半区间查找以保持稳定性
    return BinarySearch(v, left, mid, tar);
}

int main() {
    // 初始化有序数组
    vector<int> v;  // 存储有序整数序列
    int n;          // 用于存储输入的数量
    // 移除重复的vector和n声明
    // 读取初始有序数组
    cin >> n;
    while(n--) {
        int t;  // 临时存储输入的数字
        cin >> t;
        v.push_back(t);  // 将数字添加到数组末尾
    }

    // 读取要插入的数字数量
    cin >> n;
    while(n--) {
        int t;  // 临时存储要插入的数字
        cin >> t;
        
        // 使用二分查找确定插入位置
        int pos = BinarySearch(v, 0, v.size()-1, t);
        
        // 在正确位置插入数字，保持数组有序
        v.insert(v.begin()+pos, t);
        // 计算并输出当前中位数
        int size = v.size();
        
        // 数组长度为奇数时，中位数是中间元素
        if(size % 2 != 0) {
            cout << v[size/2] << endl;
        }
        // 数组长度为偶数时，中位数是中间两个数的平均值
        else {
            double median = (v[size / 2 - 1] + v[size / 2]) / 2.0;
            
            // 如果中位数是整数，输出整数形式；否则保留小数
            if (median == (int)median) {
                cout << (int)median << endl;
            } else {
                cout << median << endl;
            }
        }
    }

    
    return 0;
}
```

### 19116-丑数

- Description
“丑数”是指除了质因子2,3，5，不含其它质因子的正整数，例如由小到大前10个“丑数”为
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, ...
现要求编写一个程序，输出指定第几位的“丑数”。

- 输入格式
第一行为正整数T（T<=10000）, 表示case的数目。
此后T行，每行一个正整数 n (确定该第n个凑数不超过100000000).

- 输出格式
每一个n，输出第n个“丑数”

- 输入样例
```
3
1
2
9
```

- 输出样例
```
1
2
10
```

- one of the answers
```cpp
#include <iostream>
#include <vector>
using namespace std;

/*
 * 丑数生成算法
 * 使用动态规划方法生成丑数序列
 * 丑数定义：只包含质因子2、3、5的正整数
 */

int main() {
    // 优化输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    /*
     * 输入处理部分
     * 读取测试用例并找出最大的n值
     * 用于确定需要生成的丑数数量
     */

    int T;
    cin >> T;
    vector<int> cases(T);
    int max_n = 0;
    for (int i = 0; i < T; ++i) {
        cin >> cases[i];
        if (cases[i] > max_n) {
            max_n = cases[i];
        }
    }

    // 初始化丑数数组，第一个丑数为1
    vector<int> ugly(max_n);
    ugly[0] = 1;
    
    // 初始化三个指针，分别对应2、3、5的倍数
    int i2 = 0; // 指向下一个要乘以2的丑数
    int i3 = 0; // 指向下一个要乘以3的丑数
    int i5 = 0; // 指向下一个要乘以5的丑数

    /*
     * 动态生成丑数序列
     * 每个新丑数都是之前某个丑数乘以2、3或5得到的最小值
     */
    for (int i = 1; i < max_n; ++i) {
        // 计算三个候选丑数
        int next2 = ugly[i2] * 2;
        int next3 = ugly[i3] * 3;
        int next5 = ugly[i5] * 5;

        // 选择三个候选中的最小值作为下一个丑数
        int min_val = min(next2, min(next3, next5));
        ugly[i] = min_val;

        // 移动指针：哪个候选被选中，对应的指针就前进一位
        // 这样可以避免重复计算相同的丑数
        if (min_val == next2) ++i2;
        if (min_val == next3) ++i3;
        if (min_val == next5) ++i5;
    }

    for (int n : cases) {
        cout << ugly[n - 1] << '\n';
    }

    return 0;
}
```

