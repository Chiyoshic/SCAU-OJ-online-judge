#include "stdio.h"
#include "stdlib.h"
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

Status CreateBiTree(BiTree &T) {  // 算法6.4
  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
  // 构造二叉链表表示的二叉树T。
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data = ch; // 生成根结点
    if(!CreateBiTree(T->lchild)) return ERROR;   // 构造左子树
    if(!CreateBiTree(T->rchild)) return ERROR;  // 构造右子树
  }
  return OK;
} // CreateBiTree





Status PreOrderTraverse( BiTree T) {
    if(!T) return OK;
   if(T)printf("%c", T->data);
   PreOrderTraverse(T->lchild);
   PreOrderTraverse(T->rchild);
} // PreOrderTraverse



Status InOrderTraverse( BiTree T) {
    if(!T) return OK;
    InOrderTraverse(T->lchild);
    if(T) cout << T->data;
    InOrderTraverse(T->rchild);
} // InOrderTraverse



Status PostOrderTraverse( BiTree T) {
    if(!T) return OK;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    if(T)cout << T->data;
} // PostOrderTraverse



int main()   //主函数
{
    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T);
    cout << endl;
    InOrderTraverse(T);
    cout << endl;
    PostOrderTraverse(T);
    return 0;
 }//main

 /*
 输入格式
第一行：输入一棵二叉树的先序遍历序列


输出格式
第一行：二叉树的先序遍历序列
第二行：二叉树的中序遍历序列
第三行：二叉树的后序遍历序列


输入样例
AB##C##


输出样例
ABC
BAC
BCA
*/
