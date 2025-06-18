#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

// 定义绝对值宏
#define ABS(a) ((a)>=0?(a):-(a))

/**
 * 递归函数，计算N皇后问题的解的数量
 * @param n 棋盘大小(n×n)和皇后数量
 * @param cur 当前正在放置的行号(从0开始)
 * @param A 数组，记录每行皇后的列位置(A[i]表示第i行皇后所在的列)
 * @return 返回从当前状态开始的解的数目
 */
int F(int n, int cur, int* A)
{
    // 基本情况：已经成功放置了所有n个皇后
    if(cur == n)
        return 1;  // 找到一个有效解，返回1
    else
    {
        int ret = 0;  // 用于累计当前行的所有可能解
        
        // 尝试在当前行的每一列放置皇后
        for(int i = 0; i < n; i++)
        {
            int ok = 1;  // 标记当前位置是否可行
            
            // 检查与之前放置的所有皇后是否冲突
            for(int j = 0; j < cur; j++)
            {
                // 冲突条件1：同一列有皇后
                // 冲突条件2：在对角线上有皇后(行差绝对值等于列差绝对值)
                if(A[j] == i || ABS(cur - j) == ABS(A[j] - i))
                {
                    ok = 0;  // 发现冲突
                    break;   // 不需要继续检查其他皇后
                }
            }
            
            // 如果当前位置没有冲突
            if(ok)
            {
                A[cur] = i;  // 记录当前行皇后的位置
                // 递归处理下一行，并将返回的解数累加到ret中
                ret += F(n, cur + 1, A);
            }
        }
        return ret;  // 返回当前状态下的所有可能解数
    }
}

int main()
{
    int T, n, A[30];  // T:测试用例数, n:棋盘大小, A:存储皇后位置
    
    cin >> T;  // 读取测试用例数量
    
    while(T--)
    {
        cin >> n;  // 读取棋盘大小
        // 调用F函数计算解的数量并输出
        // 参数说明：n是棋盘大小，0表示从第0行开始放置，A是位置记录数组
        cout << F(n, 0, A) << endl;
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