#include <iostream>
#include <string>
using namespace std;

// 根据先序和中序遍历序列，递归构造后序遍历序列
void buildPostOrder(string pre, string in, string &post) {
    if (pre.empty() || in.empty()) {
        return;
    }

    char root = pre[0]; // 先序的第一个节点是根节点
    int rootPos = in.find(root); // 在中序中找到根节点的位置

    // 递归处理左子树
    string leftPre = pre.substr(1, rootPos); // 左子树的先序
    string leftIn = in.substr(0, rootPos); // 左子树的中序
    buildPostOrder(leftPre, leftIn, post);

    // 递归处理右子树
    string rightPre = pre.substr(rootPos + 1); // 右子树的先序
    string rightIn = in.substr(rootPos + 1); // 右子树的中序
    buildPostOrder(rightPre, rightIn, post);

    post += root; // 后序遍历最后访问根节点
}

int main() {
    string pre, in;
    cin >> pre >> in; // 输入先序和中序遍历序列

    string post; // 存储后序遍历序列
    buildPostOrder(pre, in, post); // 构造后序遍历序列

    cout << post << endl; // 输出后序遍历序列

    return 0;
}
/*
Description
二叉树的三种遍历都可以通过递归实现。
如果我们知道一棵二叉树的先序和中序序列，可以用递归的方法求后序遍历序列。



输入格式
两行，第一行一个字符串，表示树的先序遍历，第二行一个字符串，表示树的中序遍历。
树的结点一律用小写字母表示,且字符串长度不超过30。


输出格式
一个字符串，树的后序序列。


输入样例
abcde
bcade


输出样例
cbeda*/