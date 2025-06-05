#include <iostream>
#include <queue>
// 二叉树宽度计算
// 算法思想：使用层次遍历(BFS)，统计每层节点数，取最大值
// 记忆方法："层层计数" - 逐层遍历记录节点数量
typedef long long ll;
using namespace std;
int n;              // 节点总数
int child[105][3];  // 存储二叉树结构，child[i][1]为左孩子，child[i][2]为右孩子
int ans=1;          // 存储最大宽度，初始化为1（根节点）
int main()
{
    int i,j,x,y;
    cin>>n;  // 输入节点数量
    
    // 构建二叉树结构
    for(i=1; i<n; i++)
    {
        cin>>x>>y;  // 输入父子关系
        if(!child[x][1])
            child[x][1]=y;  // 第一个子节点作为左孩子
        else
            child[x][2]=y;  // 第二个子节点作为右孩子
    }
    // 层次遍历计算宽度
    queue<int>q;    // 使用队列进行BFS
    q.push(1);      // 从根节点开始
    
    while(q.size())  // 当队列不为空时继续遍历
    {
        int len=q.size();  // 当前层的节点数量
        ans=max(ans,len);  // 更新最大宽度
        
        // 处理当前层所有节点
        for(i=0;i<len;i++)
        {
            int t=q.front();  // 取出队首节点
            q.pop();
            
            // 将子节点加入队列（下一层）
            if(child[t][1])
                q.push(child[t][1]);  // 左孩子入队
            if(child[t][2])
                q.push(child[t][2]);  // 右孩子入队
        }
    }
    cout<<ans;  // 输出最大宽度
    return 0;
    // 注意：数组会自动释放内存
}
/*
Description
二叉树的宽度指的是具有节点数目最多的那一层的节点个数。
          1
         / \
        2   3
       /     
      4     
答案为2, 第二层节点数最多，为2个节点。



输入格式
共n行。
第一行一个整数n，表示有n个结点，编号为1至n,结点1为树根。（1<=n<=50）
第二行至第n行，每行有两个整数x和y，表示在二叉树中x为y的父节点。x第一次出现时y为左孩子


输出格式
输出二叉树的宽度。


输入样例
5
1 2
1 3
2 4
2 5


输出样例
2
*/