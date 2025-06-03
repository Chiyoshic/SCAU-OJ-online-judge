#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    stack<int> S;
    int value;
    cin >> value;

    while(value!=0){
        S.push(value%8);
        value /=8;
    }

    int Amount = S.size();
    for(int i = 0; i<Amount; i++){
        cout << S.top();
        S.pop();
    }
    
	return 0;
}

/*
Description
利用顺序栈的基本操作算法，编写满足下列要求的数制转换程序：对于输入的任意一个非负十进制整数，打印输出与其等值的八进制数。



输入格式
第一行：输入一个非负的十进制整数


输出格式
第一行：与输入等值的八进制数


输入样例
15


输出样例
17


作者 yqm*/