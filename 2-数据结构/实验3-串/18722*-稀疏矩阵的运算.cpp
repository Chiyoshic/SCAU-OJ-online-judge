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
#include <utility>
#include <algorithm>
using namespace std;

class unit {
public:
    int x;
    int y;
    int num;

    unit(int fx, int fy, int fnum) : x(fx), y(fy), num(fnum) {}
};

int n, m, k;
vector<unit> units;

bool compare(unit a, unit b){
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}

int main(){
    cin >> n >> m >> k;
    for(int i=0; i<k; i++){
        int x, y, num;
        cin >> x >> y >> num;
        units.push_back(unit(y, x, num));
    }
    sort(units.begin(), units.end(), compare);

    for(int i=0 ; i<k; i++){
        cout << units[i].x << " " << units[i].y << " " << units[i].num << endl;
    }
    return 0;
}
/*
Description
稀疏矩阵的压缩存储原则：只存矩阵的行列数和每个非零元的行列下标及其值。
例如下图的矩阵M由行列数（6,7）和三元组表{(1,2,12), (1,3,9), (3,1,-3),(3,6,14),(4,3,24),(5,2,18), (6,1,15), (6,4,-7) }唯一确定。
问题描述：已知一个稀疏矩阵的三元组表，使用快速转置算法求其转置矩阵的三元组表，三元组表要按行优先的方式存储。
输入格式
第一行三个整数n,m,k。n,m代表矩阵A的行列数（0<=n,m<=1000000）,k为三元组表中元素的个数。
此后为k行，每行3个整数a，b，c，分别代表元素的行号，列号和值。数据确保按行优先给出。（0<=k<=10000）


输出格式
输出为k行，即转置矩阵的三元组表，三元组表要按行优先显示。


输入样例
6 7 8
1 2 12
1 3 9
3 1 -3
3 6 14
4 3 24
5 2 18
6 1 15
6 4 -7


输出样例
1 3 -3
1 6 15
2 1 12
2 5 18
3 1 9
3 4 24
4 6 -7
6 3 14
*/