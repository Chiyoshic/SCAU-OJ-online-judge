#include <iostream>  // 标准输入输出
#include <vector>   // 向量容器
#include <queue>    // 优先队列，用于Prim算法
using namespace std;

/* 类型定义和常量 */
typedef long long ll;  // 定义长整型别名，用于处理大数
typedef pair<ll, int> pii; // 定义边类型(权重,顶点)
const ll INF = 1LL << 60; // 定义无穷大值

/**
 * Prim算法实现最小生成树
 * 算法思想：贪心策略，每次选择连接已选和未选顶点集合的最小边
 * 记忆方法：P(优先队列)R(松弛操作)I(初始化)M(最小边)
 * @param n 顶点数量
 * @param adj 邻接表表示的图
 * @return 最小生成树的总权重
 */
ll prim(int n, vector<vector<pii>>& adj) {
    /* 初始化阶段 */
    vector<ll> dist(n + 1, INF); // 存储各顶点到已选集合的最小距离
    vector<bool> visited(n + 1, false); // 标记顶点是否已加入生成树
    priority_queue<pii, vector<pii>, greater<pii>> pq; // 小顶堆，按权重排序
    
    /* 从顶点1开始构建生成树 */
    dist[1] = 0; // 起始顶点距离设为0
    pq.push({0, 1}); // 将起始顶点加入优先队列
    
    ll total_weight = 0; // 最小生成树总权重
    int nodes_added = 0; // 已加入生成树的顶点数
    
    /* 主循环：每次选择一个顶点加入生成树 */
    while (!pq.empty() && nodes_added < n) {
        /* 取出当前最小边 */
        ll current_dist = pq.top().first; // 获取最小边的权重
        int u = pq.top().second; // 获取顶点编号
        pq.pop(); // 从队列中移除
        
        /* 跳过已处理的顶点 */
        if (visited[u]) continue;
        
        /* 将顶点u加入生成树 */
        visited[u] = true; // 标记为已访问
        total_weight += current_dist; // 累加权重
        nodes_added++; // 计数加1
        
        /* 松弛操作：更新邻接顶点到生成树的最小距离 */
        for (auto& edge : adj[u]) {
            ll w = edge.first; // 边权重
            int v = edge.second; // 邻接顶点
            
            /* 如果顶点v未加入且找到更小距离 */
            if (!visited[v] && w < dist[v]) {
                dist[v] = w; // 更新最小距离
                pq.push({w, v}); // 加入优先队列
            }
        }
    }
    
    return total_weight;
}

int main() {
    /* 输入输出优化 */
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /* 读取输入 */
    int n, m; // n-顶点数, m-边数
    cin >> n >> m;
    
    /* 构建邻接表 */
    vector<vector<pii>> adj(n + 1); // 邻接表存储图
    
    /* 读取边信息 */
    for (int i = 0; i < m; i++) {
        int a, b; // 边的两个顶点
        ll w; // 边权重
        cin >> a >> b >> w;
        
        /* 无向图，双向添加边 */
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    
    /* 计算并输出最小生成树权重 */
    ll result = prim(n, adj);
    cout << result << endl;
    
    return 0;
}

/*
Description
给定结点数为n，边数为m的带权无向连通图G，所有结点编号为1,2,3....n。
求图G的最小生成树的边权和。



输入格式
第一行两个正整数n和m。n,m<=2000
之后的m行，每行三个正整数a,b,w，描述一条连接结点a和b,边权为w的边。1=<a,b<=n,w<=10^18。
注意可能存在重边和自环。


输出格式
一个整数表示图G的最小生成树的边权和（注意用长整型）。


输入样例
7 12
1 2 9
1 5 2
1 6 3
2 3 5
2 6 7
3 4 6
3 7 3
4 5 6
4 7 2
5 6 3
5 7 6
6 7 1


输出样例
16
*/