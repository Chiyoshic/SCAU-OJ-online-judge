#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;
int n,child[105][3],ans=1;
int main()
{
    int i,j,x,y;
    cin>>n;
    for(i=1; i<n; i++)
    {
        cin>>x>>y;
        if(!child[x][1])
            child[x][1]=y;
        else
            child[x][2]=y;
    }
    queue<int>q;
    q.push(1);
    while(q.size())
    {
        int len=q.size();
        ans=max(ans,len);
        for(i=0;i<len;i++)
        {
            int t=q.front();
            q.pop();
            if(child[t][1])
                q.push(child[t][1]);
            if(child[t][2])
                q.push(child[t][2]);
        }
    }
    cout<<ans;
    return 0;
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