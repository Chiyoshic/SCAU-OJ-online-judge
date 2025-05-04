#include <iostream> // 标准输入输出流
#include <vector>   // 向量容器
#include <algorithm> // STL算法库，包含sort和next_permutation

using namespace std;

/*
算法思想：
1. 使用STL的next_permutation函数生成全排列
2. 必须先排序才能保证排列按字典序输出
3. 每次生成下一个排列直到返回false

步骤详解：
1. 读取输入数字个数N
2. 读取N个不同的整数存入vector
3. 对vector进行排序(关键步骤)
4. 使用do-while循环输出所有排列
5. next_permutation会自动生成下一个字典序排列

记忆方法：
- 排序是必须的前置步骤
- do-while保证至少执行一次输出
- next_permutation会修改原数组
*/
int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    
    // 必须先排序才能保证next_permutation生成所有排列
    sort(nums.begin(), nums.end());
    
    // 使用do-while确保至少输出一次(原始排列)
    do {
        // 输出当前排列，数字间用空格分隔
        for (int i = 0; i < N; ++i) {
            if (i != 0) cout << " ";
            cout << nums[i];
        }
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));
    
    return 0;
}
/*
描述：
由键盘输入N个不同的整数，输出这N个数的全部排列。

输入格式：
第一行一个正整数。N<=5
每二行N个整数，以空格分隔。

输出格式：
每行一个排列，数之间由一个空格分隔，要求排列按由小到大输出，不允许重复。

输入样例：
3
3 9 1

输出样例：
1 3 9
1 9 3
3 1 9
3 9 1
9 1 3
9 3 1
*/