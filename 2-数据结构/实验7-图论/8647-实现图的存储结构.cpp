#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class pos{
public:
    int y;
    int x;

    pos(int y, int x){
        this->y = y;
        this->x = x;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v (n, vector<int>(n, 0));

    for(int i=0; i<m; i++){
        int y, x;
        cin >> y >> x;
        v[y-1][x-1] = 1;
    }

    for(int i=0 ; i<n; i++){
        for(int j=0; j<n; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}

/*Description
实现有向图的邻接矩阵存储结构。



输入格式
第一行：输入图的顶点个数n（各个顶点的默认编号为1~n）， 边的条数m。
第二 ~ m+1行：每行输入两个顶点编号i、j，表示连接顶点i到顶点j的一条边。


输出格式
分n行输出n*n的邻接矩阵，表示所输入的图存储，顶点i和顶点j之间如果有边相连，则输出1，没边相连则输出0。


输入样例
4 4
1 2
1 3
3 4
4 1


输出样例
0 1 1 0
0 0 0 0
0 0 0 1
1 0 0 0
*/