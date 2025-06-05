
#include "stdio.h"
#include "malloc.h"
#include <iostream>
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
using namespace std;
typedef int  Status;
typedef char  ElemType;
typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;
int zero = 0, one = 0, two = 0;

Status CreateBiTree(BiTree &T) {  // 算法6.4
  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
  // 构造二叉链表表示的二叉树T。
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
     if(!CreateBiTree(T->lchild)) return ERROR;   // 构造左子树
    if(!CreateBiTree(T->rchild)) return ERROR;  // 构造右子树
  }
  return OK;
} // CreateBiTree

Status PreOrderTraverse( BiTree T) {
    if(!T) return OK;
   if(!T->lchild && !T->rchild) zero++;
   else if(T->lchild && T->rchild) two++;
   else if(T->lchild || T->rchild) one++;
   PreOrderTraverse(T->lchild);
   PreOrderTraverse(T->rchild);
} // PreOrderTraverse

int main()   //主函数
{
    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T);
    cout << two << endl;
    cout << one <<endl;
    cout << zero << endl;
    return 0;
 }//main

/*
输入格式
第一行输入先序次序二叉树中结点


输出格式
第一行输出度为2的节点数
第二行输出度为1的节点数
第三行输出度为0的节点数


输入样例
ABC###D##


输出样例
1
1
2
*/