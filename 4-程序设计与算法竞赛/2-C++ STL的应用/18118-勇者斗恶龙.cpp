#include <iostream>
#include <vector>
#include <algorithm>  // 用于sort函数

using namespace std;

/*
 * 算法思想：贪心算法
 * 1. 将龙头直径和骑士能力分别排序
 * 2. 使用双指针法匹配最小的合适骑士
 * 3. 累计金币并检查是否所有龙头都被砍掉
 * 记忆技巧：排序+双指针=最小花费解
 */
int main(){

    // 多组测试数据循环
    while(1) {
        // 优化输入输出速度
        std::ios::sync_with_stdio(false);
        cin.tie(0);
        
        // 读取龙头数量n和骑士数量m
        int n, m;
        cin >> n >> m;
        // 输入结束条件
        if(n == 0 && m == 0) break;
        
        // 存储龙头直径(d)和骑士能力(s)
        vector<int> d, s;
        // 读取所有龙头直径
        for(int i = 0; i < n; i++) {
            int t;
            cin >> t;
            d.push_back(t);
        }
        
        // 读取所有骑士能力值
        for(int i = 0; i < m; i++) {
            int t;
            cin >> t;
            s.push_back(t);
        }
        // 骑士数量不足，直接输出失败
        if(d.size() > s.size()) {
            cout << "Loowater is doomed!" << endl;
            continue;
        }
        
        // 关键步骤1：排序龙头直径(从小到大)
        sort(d.begin(), d.end());
        // 关键步骤2：排序骑士能力(从小到大)
        sort(s.begin(), s.end());
        
        // 初始化总花费和双指针
        int cost = 0;      // 总金币花费
        int di = 0;        // 龙头指针
        int si = 0;        // 骑士指针
        // 贪心匹配：为每个龙头找能力最小的能砍它的骑士
        while(di < d.size() && si < s.size()) {
            if(s[si] >= d[di]) {  // 当前骑士能砍当前龙头
                cost += s[si];    // 累加金币
                si++;             // 该骑士已被雇佣
                di++;             // 该龙头已被砍掉
            } else {
                si++;             // 当前骑士太弱，尝试下一个
            }
        }

        // 输出结果：检查是否所有龙头都被砍掉
        if(di >= d.size()) {
            cout << cost << endl;  // 输出最小总花费
        } else {
            cout << "Loowater is doomed!" << endl;  // 无法砍掉所有龙头
        }

    }

    return 0;
}

/*
Description
有n个头的恶龙，你希望雇一些骑士把它杀死（即砍掉所有头）。村里有ｍ个骑士可以雇佣，一个能力值为x的骑士可以砍掉恶龙
一个直径不超过x的头，且需要支付x个金币。如何雇佣骑士才能砍掉恶龙的所有头，且需要支付的金币最少？注意，一个骑士只
能砍一个头（且不能被雇佣两次）



输入格式
多组数据，每组数据的第一行为正整数n和m(1<=n,m<=200000)；以下n行每行为一个整数，即恶龙每个头的直径；以下m行每行为
一个整数，即每个骑士的能力。输入结束标志ｎ＝ｍ＝0;


输出格式
输出格式：每组数据，输出最少花费，无解输出"Loowater is doomed!"


输入样例
2 3
5
4
7
8
4
2 1
5
5
10
0 0


输出样例
11
Loowater is doomed!
*/