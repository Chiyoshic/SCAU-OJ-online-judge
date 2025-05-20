#include <iostream>  // 输入输出流
#include <vector>   // 向量容器
#include <queue>    // 队列容器，用于BFS算法
#include <map>      // 映射容器，用于顶点名到索引的映射
using namespace std;


/* 边结点结构体
 * adjvex: 邻接顶点在顶点数组中的下标
 * weight: 边的权值(网图使用)
 * nextarc: 指向下一条边的指针
 * 记忆方法：A(adjvex)W(weight)N(nextarc)
 */
struct ArcNode {
    int adjvex;        // 邻接顶点下标
    int weight;        // 边权值
    ArcNode* nextarc;  // 下一条边指针
};


/* 顶点结点结构体
 * data: 顶点数据
 * firstarc: 指向第一条依附该顶点的边
 * 记忆方法：D(data)F(firstarc)
 */
struct VNode {
    string data;       // 顶点数据
    ArcNode* firstarc; // 第一条边指针
};


/* 邻接表图类
 * vertices: 顶点数组
 * kind: 图类型(0-有向图,1-有向网,2-无向图,3-无向网)
 * vertexIndex: 顶点名到索引的映射
 */
class ALGraph {
private:
    vector<VNode> vertices; // 顶点数组
    int kind;              // 图类型
    map<string, int> vertexIndex; // 顶点名到索引的映射

public:
    ALGraph(int k, int vnum) : kind(k) {
        vertices.resize(vnum);
        for (int i = 0; i < vnum; i++) {
            vertices[i].firstarc = NULL;
        }
    }
    
    
    void setVertex(int index, const string& data) {
        vertices[index].data = data;
        vertexIndex[data] = index;
    }
    
    
    void addArc(const string& tail, const string& head, int weight = 0) {
        int t = vertexIndex[tail];
        int h = vertexIndex[head];
        
        
        ArcNode* newNode = new ArcNode;
        newNode->adjvex = h;
        newNode->weight = weight;
        newNode->nextarc = vertices[t].firstarc;
        vertices[t].firstarc = newNode;
        
        
        if (kind >= 2) {
            ArcNode* reverseNode = new ArcNode;
            reverseNode->adjvex = t;
            reverseNode->weight = weight;
            reverseNode->nextarc = vertices[h].firstarc;
            vertices[h].firstarc = reverseNode;
        }
    }
    
    
    /* 广度优先搜索算法
 * 步骤：
 * 1. 初始化访问标记数组和队列
 * 2. 起始顶点入队并标记已访问
 * 3. 循环直到队列为空：
 *    a. 队首顶点出队并加入结果
 *    b. 遍历该顶点的所有邻接顶点
 *    c. 未访问的邻接顶点入队并标记
 * 记忆方法：初始-入队-循环(出队-遍历-入队)
 */
void BFS(int start, vector<string>& result) {
        vector<bool> visited(vertices.size(), false); // 访问标记数组
        queue<int> q;  // BFS队列
        
        q.push(start); // 起始顶点入队
        visited[start] = true; // 标记已访问
        
        while (!q.empty()) {  // 队列不为空时循环
            int current = q.front(); // 获取队首顶点
            q.pop(); // 队首顶点出队
            result.push_back(vertices[current].data); // 加入结果
            
            // 遍历当前顶点的所有邻接顶点
            ArcNode* p = vertices[current].firstarc;
            while (p != NULL) {
                int adj = p->adjvex; // 邻接顶点索引
                if (!visited[adj]) {  // 未访问则处理
                    visited[adj] = true; // 标记已访问
                    q.push(adj);      // 邻接顶点入队
                }
                p = p->nextarc; // 处理下一条边
            }
        }
    }
};

int main() {
    int kind, vnum, anum;
    cin >> kind; 
    cin >> vnum >> anum; 
    
    ALGraph g(kind, vnum);
    
    
    for (int i = 0; i < vnum; i++) {
        string data;
        cin >> data;
        g.setVertex(i, data);
    }
    
    
    for (int i = 0; i < anum; i++) {
        string tail, head;
        cin >> tail >> head;
        if (kind == 1 || kind == 3) { 
            int weight;
            cin >> weight;
            g.addArc(tail, head, weight);
        } else {
            g.addArc(tail, head);
        }
    }
    
    vector<string> result;
    g.BFS(0, result); 
    
    
    for (size_t i = 0; i < result.size(); i++) {
        if (i != 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
    
    return 0;
}

/*
Description
使用图的深度遍历实现的邻接表存储结构和基本操作函数，在此基础上实现图的广度遍历算法并加以测试。注意正确使用队列存储结构。



输入格式
第一行：输入0到3之间整数(有向图:0,有向网:1,无向图:2,无向网:3)；
第二行：输入顶点数和边数；
第三行：输入各个顶点的值（字符型，长度〈3）；(遍历从输入的第一个顶点开始)
第四行：输入每条弧(边)弧尾和弧头(以空格作为间隔),如果是网还要输入权值；


输出格式
输出对图广度遍历的结果


输入样例
0
3 3
a b c
a b
b c
c b


输出样例
a b c


提示
注意题目的邻接表采用头插法，也就是后出现的边节点插入到邻接表的表头。
*/