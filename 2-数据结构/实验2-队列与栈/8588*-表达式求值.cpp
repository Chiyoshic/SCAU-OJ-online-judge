#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // '(' 的优先级最低
}

double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) break;
            return a / b;
        default:
            break;
            return 0;
    }
    return 0;
}


int main(){
    std::ios::sync_with_stdio(false);
    string str;
    int i;
    stack<char> Symbol;
    vector<string> Output;
    getline(cin, str);
    for (int i = 0; str[i]!='='; i++) {
        if (isdigit(str[i])) { // 是数字
            string num; // 存储完整的数字
            while (i < str.length() && isdigit(str[i])) {
                num += str[i];
                i++;
            }
            i--; // 回退一位，因为外层循环还会增加 i
            Output.push_back(num);
        } else if (str[i] == '(') { // 左括号直接入栈
            Symbol.push(str[i]);
        } else if (str[i] == ')') { // 右括号处理
            while (!Symbol.empty() && Symbol.top() != '(') {
                Output.push_back(string(1, Symbol.top()));
                Symbol.pop();
            }
            if (!Symbol.empty()) Symbol.pop(); // 弹出 '('
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            while (!Symbol.empty() && priority(Symbol.top()) >= priority(str[i])) {
                Output.push_back(string(1, Symbol.top()));
                Symbol.pop();
            }
            Symbol.push(str[i]);
        } else { // 非法字符
            cerr << "Error: Invalid character '" << str[i] << "' in expression." << endl;
            return 1;
        }
    }


    while (!Symbol.empty()) {
        Output.push_back(string(1, Symbol.top()));
        Symbol.pop();
    }


    //for (i=0; i<Output.size(); i++) cout << Output[i] << " ";
    //cout << endl;

    string a;
    double temp;
    stack<double> Number;

    for(i=0; i<Output.size(); i++){
        a = Output[i];
        if (isdigit(a[0]) || (a[0] == '-' && a.size() > 1)) {
            // 是数字或负数或小数
            temp = std::atof(a.c_str());
            Number.push(temp);
        }else if (a.size() == 1 && (a[0] == '+' || a[0] == '-' || a[0] == '*' || a[0] == '/')) {
            if (Number.size() < 2) continue;
            double c = Number.top();
            Number.pop();
            double b = Number.top();
            Number.pop();
            Number.push(calculate(b, c, a[0]));
        }
    }

    cout << Number.top() << endl;

	return 0;
}

/*
利用栈编写表达式求值程序：输入含有“+”、“-”、“*”、“/”四则运算的表达式，其中负数要用（0-正数）表示，并以=结束。要求输出表达式的值（两运算符号的优先关系见教材表3.1）。



输入格式
第一行：一个算术表达式


输出格式
第一行：算术表达式的值


输入样例
3*(9-7)=


输出样例
6


作者 yqm*/