
#include <iostream> // 标准输入输出
#include <vector>   // 向量容器
#include <algorithm> // STL算法库，包含sort和next_permutation
using namespace std;

/*
函数功能：检查排列中是否有相邻的两个奇数
算法思想：
1. 遍历排列中的每个元素(除最后一个)
2. 检查当前元素和下一个元素是否都是奇数
3. 如果发现相邻奇数对，立即返回false
4. 遍历完成后返回true

记忆方法：
- 奇数判断：num%2 != 0
- 相邻检查：i和i+1
*/
bool is(vector<int>& perm){
    for(int i=0; i<perm.size()-1; i++){
        if((perm[i]%2!=0) && (perm[i+1]%2!=0)) return false;
    }
    return true;
}

int main()
{
    /*
    算法流程：
    1. 输入数字个数n和n个整数
    2. 对数组进行排序(关键步骤，确保next_permutation生成所有排列)
    3. 使用do-while循环生成所有排列
    4. 对每个排列检查相邻奇数条件
    5. 符合条件的排列按格式输出
    
    next_permutation原理：
    - 生成当前序列的下一个字典序排列
    - 修改原数组内容
    - 返回true表示成功生成，false表示已是最后一个排列
    */
    
    int n;
    cin >> n; // 读取数字个数
    vector<int> nums(n); // 存储输入数字
    
    // 读取n个整数
    for(int i=0; i<n;i++){
        cin >> nums[i];
    }
    
    // 必须先排序才能保证next_permutation生成所有排列
    sort(nums.begin(), nums.end());

    // 生成所有排列并检查条件
    do{
        if(is(nums)){ // 检查当前排列是否满足相邻不为奇数的条件
            // 输出符合条件的排列
            for(int i=0; i<n; i++){
                cout << nums[i] << " ";
            }
            cout << endl;
        }
    }while(next_permutation(nums.begin(), nums.end())); // 生成下一个排列
    
    return 0;
}
/*
描述：
从键盘输入N个整数N<=10,要求输出这N个整数的全排列，且每一个排列当中，相邻两个数不能同为奇数。

输入格式：
第一行一个正整数N
第二行N个整数，以空格分隔

输出格式：
一行一个排列，按小到大的顺序输出

输入样例：
3
1 1 2

输出样例：
1 2 1
*/