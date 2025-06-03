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
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    stack<char> S, Reverse;
    char a;
    int N;
    cin >> N;
    string sentence;
    getchar();
    while(N--){
        while (!S.empty()) S.pop();
        getline(cin, sentence);
        //cout << sentence << endl;
        for(int i=0; i<sentence.length(); i++){
            if( sentence[i] == '#' && !S.empty() )
                S.pop();
            else if( sentence[i] == '@' && !S.empty() )
                while(!S.empty()) S.pop();
            else S.push(sentence[i]);
        }
        while(!S.empty()){
            Reverse.push(S.top());
            S.pop();
        }
        while(!Reverse.empty()){
            cout << Reverse.top();
            Reverse.pop();
        }
        cout << endl;
    }

    

	return 0;
}

/*
Description 利用栈编写简单的行编辑程序：
接受用户从终端输入的程序或数据，
在输入过程中，允许用户输入出差错，
并在发现有误时可以及时更正。
例如：当用户发现刚刚键入的一个字符是错的时，
可以补进一个退格符“#”，以表示前一个字符无效；
如果发现当前键入的行内差错较多或难以补救，
则可以键入一个退行符“@”，以表示当前行中的字符均无效。
例如：假设从终端接受了这样两行字符： whli##ilr#e (s#*s) outcha@putchar(*s=#++); 
则实际有效的是下列两行： while (*s) putchar(*s++); 
本题目给出部分函数，要求将行编辑函数补充完整，并完成整个程序。
输入格式
第一行：第一个字符为输入文本的行数n;
第二行至第n行：每行均为一串字符，其间可以含有“#”和“@”符号，以回车键结束本行的输入；


输出格式
输出第一至第n行的内容如下：
第一行：第一行从终端输入的有效字符。
第二行：第二行从终端输入的有效字符。
…… ……
第n行：第n行从终端输入的有效字符。


输入样例
2
defne##ine OK 1
typp cila@type int element


输出样例
define OK 1
type int element

*/