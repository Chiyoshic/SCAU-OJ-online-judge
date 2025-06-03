typedef char SElemType;
#include"stdlib.h"
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#include <stack>
#include <string>
#include <iostream>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACKINCREMENT 2 // 存储空间分配增量
using namespace std;
void check()
{
    // 对于输入的任意一个字符串，检验括号是否配对
    stack<char> s;
    string p;

    //printf("请输入表达式\n");
    cin >> p;
    int i=0;
    while(i<p.size()) // 没到串尾
        switch(p[i])
        {
        case '(':
        case '[':
            s.push(p[i]);i++;
            break; // 左括号入栈，且p++
        case ')':
        case ']':
            if(!s.empty()) // 栈不空
            {
                char e; e = s.top(); s.pop(); // 弹出栈顶元素
                if(p[i]==')'&&e!='('||p[i]==']'&&e!='[')
                    // 弹出的栈顶元素与*p不配对
                {
                    printf("isn't matched pairs\n");
                    exit(ERROR);
                }
                else
                {
                    i++;
                    break; // 跳出switch语句
                }
            }
            else // 栈空
            {
                printf("lack of left parenthesis\n");
                exit(ERROR);
            }
        default:
            i++; break; // 其它字符不处理，指针向后移
        }
    if(s.empty()) // 字符串结束时栈空
        printf("matching\n");
    else
        printf("lack of right parenthesis\n");
}

int main()
{
    check();
    return 0;
}

/*
输入格式
第一行：输入一个包含圆括号或方括号、不超过80个字符的表达式串。


输出格式
第一行：若输入表达式括号匹配，输出"matching"; 若不匹配，输出具体信息:"isn't matched pairs", 或"lack of left parenthesis"或"lack of right parenthesis"


输入样例
8*[3*(35-23)]


输出样例
matching


作者 yqm*/