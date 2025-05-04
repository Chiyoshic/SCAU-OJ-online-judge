#include <iostream>
#include <vector>
using namespace std;

/*
 * N皇后问题 - 回溯算法解决方案
 * 算法思想：
 * 1. 逐行放置皇后，避免行冲突
 * 2. 使用三个数组记录列和两个对角线的占用情况
 * 3. 递归尝试所有可能的放置位置
 * 4. 当放置完所有行时，计数有效解
 *
 * 记忆方法：
 * 1. 列冲突：直接检查列数组
 * 2. 对角线冲突：主对角线(row+col)相同，副对角线(row-col)相同
 * 3. 副对角线索引需要加上n-1避免负数
 */

/*
 * 递归解决N皇后问题的核心函数
 * 参数说明：
 *   n: 棋盘大小
 *   row: 当前处理的行
 *   col: 列占用标记数组，col[i]=1表示第i列已被占用
 *   diag1: 主对角线占用标记数组，diag1[row+i]=1表示该对角线已被占用
 *   diag2: 副对角线占用标记数组，diag2[row-i+n-1]=1表示该对角线已被占用
 *   count: 引用传递的解计数器
 */
void solveNQueens(int n, int row, vector<int>& col, vector<int>& diag1, vector<int>& diag2, int& count) {
    // 递归终止条件：所有行都已处理完毕
    if (row == n) {
        count++;  // 找到一个有效解
        return;
    }
    
    // 尝试在当前行的每一列放置皇后
    for (int i = 0; i < n; i++) {
        // 检查当前位置是否安全（无列冲突、无对角线冲突）
        // 检查当前位置是否安全（无列冲突、无对角线冲突）
        // diag1[row+i]检查主对角线冲突（row+col相同的点在同一主对角线）
        // diag2[row-i+n-1]检查副对角线冲突（row-col相同的点在同一副对角线）
        if (col[i] || diag1[row + i] || diag2[row - i + n - 1]) continue;
        
        // 放置皇后，标记相关列和对角线
        col[i] = diag1[row + i] = diag2[row - i + n - 1] = 1;
        
        // 递归处理下一行
        solveNQueens(n, row + 1, col, diag1, diag2, count);
        
        // 回溯：移除皇后，恢复标记
        col[i] = diag1[row + i] = diag2[row - i + n - 1] = 0;
    }
}

/*
 * 计算N皇后问题的解的总数
 * 参数说明：
 *   n: 棋盘大小
 * 返回值：
 *   所有有效解的数量
 *
 * 实现步骤：
 * 1. 初始化标记数组
 * 2. 调用递归求解函数
 * 3. 返回解的数量
 */
int totalNQueens(int n) {
    int count = 0;  // 解计数器
    vector<int> col(n, 0);  // 列标记数组
    vector<int> diag1(2 * n - 1, 0);  // 主对角线标记数组，索引计算为row+i
    vector<int> diag2(2 * n - 1, 0);  // 副对角线标记数组，索引计算为row-i+n-1
    /* 对角线索引说明：
     * 1. 主对角线(row+i): 同一主对角线上所有点的row+col值相同
     * 2. 副对角线(row-i+n-1): 同一副对角线上所有点的row-col值相同
     *    - 添加n-1是为了避免负数索引
     *    - 例如：在4x4棋盘上，row-i的范围是-3到3，加上3后变为0到6
     */
    
    // 从第0行开始递归求解
    solveNQueens(n, 0, col, diag1, diag2, count);
    
    return count;
}

/*
 * 主函数
 * 处理输入输出
 * 输入格式：
 *   第一行：测试用例数量T
 *   接下来T行：每个测试用例的N值
 * 输出格式：
 *   每个测试用例输出一行解的数量
 */
int main() {
    int T;  // 测试用例数量
    cin >> T;
    
    // 处理每个测试用例
    while (T--) {
        int N;  // 棋盘大小
        cin >> N;
        cout << totalNQueens(N) << endl;  // 输出解的数量
    }
    
    return 0;
}
/*
Description
有N*N的国际象棋棋盘，要求在上面放N个皇后，要求任意两个皇后不会互杀，有多少种不同的放法？



输入格式
每一个数为T，代表CASE的数量，T<=13
此后，每行一个数N（13>=N>0）


输出格式
每一个CASE，输出对应答案


输入样例
2
4
5


输出样例
2
10
*/