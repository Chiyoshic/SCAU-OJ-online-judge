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
#include <iomanip>
using namespace std;

int akm(int m ,int n){
    if(m==0) return n+1;
    if(m>0 && n==0) return akm(m-1, 1);
    if(m>0 && n>0) return akm(m-1, akm(m, n-1));
}

int main(){
    int m, n;
    cin >> m >> n;

    cout << akm(m, n) << endl;
    return 0;
}
/*
输入格式
输入m和n。


输出格式
函数值。


输入样例
2 3


输出样例
9
*/