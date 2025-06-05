#include <iostream>
typedef long long ll;
using namespace std;

int n, child[105][3], ans = 0; // n: 节点数；child: 存储每个节点的左右孩子；ans: 记录最大直径

// 递归计算以root为根的子树的深度，并更新最大直径
int dfs(int root) {
    if (!root) // 如果当前节点为空，返回深度0
        return 0;

    // 递归计算左子树和右子树的深度
    int lchild = dfs(child[root][1]);
    int rchild = dfs(child[root][2]);

    // 当前节点的直径是左子树深度 + 右子树深度
    // 更新全局最大直径
    ans = max(ans, lchild + rchild);

    // 返回当前节点的深度（左右子树深度的最大值 + 1）
    return max(lchild, rchild) + 1;
}

int main() {
    int i, j, x, y;
    cin >> n; // 输入节点数

    // 构建二叉树的孩子关系
    for (i = 1; i < n; i++) {
        cin >> x >> y; // 输入父子关系，x是父节点，y是子节点
        if (!child[x][1]) // 如果父节点x的第1个孩子为空
            child[x][1] = y; // 将y作为x的第1个孩子
        else
            child[x][2] = y; // 否则将y作为x的第2个孩子
    }

    dfs(1); // 从根节点1开始递归计算深度和直径

    cout << ans; // 输出最大直径
    return 0;
}
/*
Description
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
          1
         / \
        2   3
       / \     
      4   5   
答案为3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。



输入格式
共n行。
第一行一个整数n，表示有n个结点，编号为1至n。
第二行至第n行，每行有两个整数x和y，表示在二叉树中x为y的父节点。x第一次出现时y为左孩子


输出格式
输出二叉树的直径。


输入样例
5
1 2
1 3
2 4
2 5


输出样例
3
*/