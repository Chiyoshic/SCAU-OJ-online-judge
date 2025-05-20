#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 
 * 类型定义和常量
 * pii: 存储(距离,顶点)对，用于邻接表
 * INF: 表示无穷大的常量，替代INT_MAX
 * 记忆方法：P(距离)P(顶点)I(整数对)
 */
typedef pair<int, int> pii;
const int INF = 1 << 30;

/**
 * Dijkstra算法实现单源最短路径
 * 算法思想：贪心策略，每次选择当前已知的最短路径顶点进行松弛操作
 * 记忆方法：D(距离数组)I(优先队列)J(松弛操作)K(跳过已处理)
 * @param n 顶点数量
 * @param adj 邻接表表示的图
 * @return 起点到终点的最短距离，不可达则返回-1
 */

int dijkstra(int n, vector<vector<pii>>& adj) {
    /* 初始化阶段 */
    vector<int> dist(n + 1, INF); // 存储起点到各顶点的最短距离
    priority_queue<pii, vector<pii>, greater<pii>> pq; // 小顶堆，按距离排序
    
    /* 从起点1开始 */
    dist[1] = 0; // 起点到自身的距离为0
    pq.push({0, 1}); // 将起点加入优先队列
    
    /* 主循环：每次处理一个顶点 */
    while (!pq.empty()) {
        /* 取出当前距离最小的顶点 */
        int current_dist = pq.top().first; // 获取当前最短距离
        int u = pq.top().second; // 获取顶点编号
        pq.pop(); // 从队列中移除
        
        /* 跳过已处理的顶点（因为有更优解已存在） */
        if (current_dist > dist[u]) continue;
        
        /* 松弛操作：更新邻接顶点的最短距离 */
        for (auto& edge : adj[u]) {
            int v = edge.first; // 邻接顶点
            int w = edge.second; // 边权重
            
            /* 如果找到更短的路径 */
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w; // 更新最短距离
                pq.push({dist[v], v}); // 加入优先队列
            }
        }
    }
    
    /* 返回终点n的最短距离，不可达则返回-1 */
    return dist[n] == INF ? -1 : dist[n];
}

int main() {
    /* 输入输出优化 */
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /* 读取输入 */
    int n, m; // n-车站数量, m-公交线路数量
    cin >> n >> m;
    
    /* 构建邻接表 */
    vector<vector<pii>> adj(n + 1); // 邻接表存储公交线路
    
    /* 读取公交线路信息 */
    for (int i = 0; i < m; i++) {
        int a, b, x; // 车站a和b，票价为x
        cin >> a >> b >> x;
        
        /* 无向图，双向添加边 */
        adj[a].push_back({b, x});
        adj[b].push_back({a, x});
    }
    
    /* 计算并输出最短路径 */
    int result = dijkstra(n, adj);
    cout << result << endl;
    
    return 0;
}
/*
Description
现在有n个车站和m条直达公交线路，每条线路都有一个固定票价。
作为一个窮人，你打算从车站1坐车到车站n，请计算下车站1到车站n的最少花费。
如果车站1无法到达车站n，请输出-1。
注意，在车站x和y之间可能存在不止一条线路。



输入格式
第一行两个整数n和m，表示车站数量和线路数量。(1<=n<=100),(1<=m<=1000)
第二行至第m+1行，每行3个整数a,b,x，代表车站a和车站b之间有一条票价为x的公交线路，公交线路是双向的。


输出格式
输出车站1到n的最小花费。


输入样例
4 4
1 2 4
2 3 7
2 4 1
3 4 6


输出样例
5
*/